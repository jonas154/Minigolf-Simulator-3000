#ifndef BORDERLINECURVEDRAWER_H
#define BORDERLINECURVEDRAWER_H

#include "borderline.h"
#include <vector>
#include <QGraphicsScene>
#include <cassert>

class BorderLineCurveDrawer
{

public:

    enum eOrientation{left=0, right};

    /*! \brief Draws a piecewise linear curve between start and stop
     *
     * @param radius The radius of the circular segment
     * @param lineLenght The length of the individual lines
     * @param orientation The orientation of the curve, BorderLineCurveDrawer::left or right
     * @param segmentIsComplementary If this is false, the shorter one of the two possible cirular segments is drawn.
     * If this is true, the longer one of the two possible segments is drawn
     * @param material The BorderLine's material as defined in the BorderLine class header
     * @param scene The GraphicsScene to which the curve will be added
     * @param pen The pen that is used to draw the curve. An invisible pen can be made by pen.setColor(QColor(0,0,0,0))
     */

    static std::vector<BorderLine*> draw(double startX, double startY,
                                         double stopX, double stopY,
                                         double radius,
                                         double lineLength,
                                         int orientation,
                                         bool segmentIsComplementary,
                                         int material,
                                         QGraphicsScene* scene,
                                         QPen pen = QPen())
    {

        std::vector<BorderLine*> lineVec;

        if(orientation == right) //switch start and stop
        {
            double tmpX = startX;
            double tmpY = startY;

            startX = stopX;
            startY = stopY;

            stopX = tmpX;
            stopY = tmpY;
        }

        if(segmentIsComplementary) //switch start and stop
        {
            double tmpX = startX;
            double tmpY = startY;

            startX = stopX;
            startY = stopY;

            stopX = tmpX;
            stopY = tmpY;
        }


        QLineF line(startX, startY, stopX, stopY);
        double s = line.length();

        assert(radius >= s/2.0);

        double alphaRad = 2.0*asin(s/(2.0*radius));
        double alphaDeg = (180.0/M_PI)*alphaRad;

        if(segmentIsComplementary)
        {
            alphaDeg = 360.0 - alphaDeg;
        }

        double stepInDegrees = (180.0/M_PI)*2.0*asin(lineLength/(2.0*radius));

        double correctStep = std::ceil(alphaDeg/stepInDegrees);
        stepInDegrees = alphaDeg/correctStep;

        double m_x = 0.5*(startX+stopX+(cos(alphaRad*0.5)/sin(alphaRad*0.5))*(startY-stopY));
        double m_y = 0.5*(startY+stopY+(cos(alphaRad*0.5)/sin(alphaRad*0.5))*(-startX+stopX));

        QPointF pOld, pNew;

        QLineF line1(m_x, m_y, stopX, stopY);

        pOld.setX(stopX);
        pOld.setY(stopY);


        if(segmentIsComplementary)
        {
            for(double step = -stepInDegrees; step >= -alphaDeg - 0.001 ; step -= stepInDegrees)
            {
                QLineF line2(line1);
                line2.setAngle(line1.angle()+step);

                pNew.setX(line2.x2());
                pNew.setY(line2.y2());

                BorderLine* line = new BorderLine(pOld.x(), pOld.y(), pNew.x(), pNew.y(), material);
                line->setPen(pen);

                lineVec.push_back(line);

                scene->addItem(line);

                pOld = pNew;
            }
        }
        else
        {
            for(double step = stepInDegrees; step <= alphaDeg + 0.001 ; step += stepInDegrees)
            {
                QLineF line2(line1);
                line2.setAngle(line1.angle()+step);

                pNew.setX(line2.x2());
                pNew.setY(line2.y2());

                BorderLine* line = new BorderLine(pOld.x(), pOld.y(), pNew.x(), pNew.y(), material);
                line->setPen(pen);

                lineVec.push_back(line);

                scene->addItem(line);

                pOld = pNew;
            }
        }

        return lineVec;

    };

};


#endif // BORDERLINECURVEDRAWER_H
