#ifndef BORDERLINE_H
#define BORDERLINE_H


#include "courtelement.h"
#include <QGraphicsLineItem>
#include <QLineF>
#include <QDebug>

//! \brief This class provides the functionality for setting up borderlines with different materials in the Court
class BorderLine : public QGraphicsLineItem, public CourtElement
{

public:

//--------------------------

    //! \brief enum for different materials
    enum eMaterial{metal_material=0, wood_material, spring_material, magnet_material};

//--------------------------

    /*! \brief Constructor
     *
     * Constructs a BorderLine object.
     * x1, y1, x2, y2 specify the coordinates of the line
     * @param _material The line's material as defined in enum eMaterial
     */
    BorderLine(qreal x1, qreal y1, qreal x2, qreal y2, const int _material, QGraphicsItem* parent = 0)
        :
        CourtElement(CourtElement::borderline_type), material(_material)
    {
        switch(material)
        {
            case metal_material:
                reflectionCoefficient = 0.95;
            break;

            case wood_material:
                reflectionCoefficient = 0.9;
            break;

            case spring_material:
                reflectionCoefficient = 1.5;
            break;

            case magnet_material:
                reflectionCoefficient = 0.0;
            break;

            default:
                reflectionCoefficient = 1.0;
            break;
        }

        QLineF line(x1, y1, x2, y2);
        this->setLine(line);

        angle = 360.0 - line.angle();

        if(angle >= 180.0)
        {
            angle -= 180.0;
        }

        if(angle == 180.0)
        {
            angle = 0.0;
        }

        //angle += 90.0; //evtl. relativ zu 12 Uhr definieren?

        //qDebug() << "line created, angle: " << angle;
    };

//--------------------------

    //! \brief Destructor
    virtual ~BorderLine(){};

//--------------------------

    //! \brief Reimplementation from QGraphicsItem::type()
    int type() const
    {
        return elementType;
    };

//--------------------------

    //! \brief Returns the line's angle relative to 3 o'clock (clockwise), intervall [0, 180[
    double getAngle() const
    {
        return angle;
    };

//--------------------------

    //! \brief Returns the reflection coefficient
    double getReflectionCoefficient() const
    {
        return reflectionCoefficient;
    };

//--------------------------

    //! \brief Returns the BorderLine's material, as defined in enum eMaterial
    int getMaterial() const
    {
        return material;
    };

//--------------------------------------

private:

    const int material;
    double reflectionCoefficient;
    double angle;

    using QGraphicsLineItem::setLine; //prevent calling from outside

};


#endif // BORDERLINE_H
