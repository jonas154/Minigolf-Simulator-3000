//BEISPIELCODE, WIRD SPÄTER ERSETZT

#include "ball.h"

Ball::Ball()
{
    setFlag(ItemUsesExtendedStyleOption);

    canCollide = 0; //Zähler damit Kollision nicht abspackt, kann besser gelöst werden

    speed = 0;
    angle = 0;

}

QRectF Ball::boundingRect() const
{
    return QRectF(-4,-4,8,8); //Größe 8*8, Mittelpunkt für Rotation in der Mitte
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setClipRect(option->exposedRect);

    QRectF rec = boundingRect();
    QBrush brush(Qt::white);

    doCollision();

    painter->fillRect(rec,brush);
    painter->drawRect(rec);
}

//bewege Ball
inline void Ball::advance(int phase)
{
    if(!phase) return;

    setPos(mapToParent(0,speed));

    //Abspackzähler
    --canCollide;
    if(canCollide < 0) canCollide=0;
}

void Ball::setAngle(qreal a)
{
    angle = a;
    setRotation(angle);
}

void Ball::setSpeed(qreal s)
{
    speed = s;
}

void Ball::doCollision()
{
    //check ob es eine Kollision gibt
    if(!(scene()->collidingItems(this).isEmpty()))
    {

        //finde Typ des kollidierenden Objectes heraus (BorderLine oder GroundMaterial)
        int sw = scene()->collidingItems(this).first()->type();

        BorderLine* borderline;
        int angle;

        switch(sw)
        {
            case CourtElement::borderline_type: //Kollision mit Spielfeldrand, abprallen

            qDebug() << "collision with borderline";

                //Jetzt weis man, dass es eine Borderline ist, also caste QGraphicsItem* in BorderLine*
                //Nehme ersten Eintrag aus der Kollisionsliste. Achtung, es können später auch weitere Einträge vorhanden sein.
                borderline = static_cast<BorderLine*>(scene()->collidingItems(this).first());
                angle = borderline->getAngle();

                if(canCollide<=0)
                {
                    //angle ist relativ zu 3 Uhr (Uhrzeigersinn), rotation ist relativ zu 12 Uhr (Uhrzeigersinn)
                    setRotation(2*(angle+90.0-rotation()) + rotation());

                    speed = speed * borderline->getReflectionCoefficient();
                 //   emit angleChanged();

                    //Abspackzähler
                    if(canCollide<=0)
                    {
                        canCollide = 16/speed;
                    }

                }

            break;

            default: break;
        }


    }
}
