//BEISPIELCODE, WIRD SPÄTER ERSETZT

#include "ball.h"

Ball::Ball()
{
    setFlag(ItemUsesExtendedStyleOption);

    canCollide = 0; //Zähler damit Kollision nicht abspackt, kann besser gelöst werden
    speed = 0;
    angle = 0;

    birdDeadPicture = ":/Images/Images/vtot.png";
    birdDeadCounter = 0;

}

QRectF Ball::boundingRect() const
{
    return QRectF(-3,-3,6,6);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //QRectF rec = boundingRect();

    QBrush brush(Qt::white);
    QPen pen;
    pen.setColor(Qt::white);

    QPainterPath path(QPointF(0.0, -5.0));
    path.arcTo(QRectF(-5.0,-5.0,10.0,10.0), 90.0, 360.0);

    painter->setClipPath(path);
    painter->setPen(pen);
    painter->fillPath(path,brush);
    painter->drawPath(path);
}

//bewege Ball
inline void Ball::advance(int phase)
{
    if(!phase) return;

    setPos(mapToParent(0,speed));

    doCollision();

    if(canCollide > 0)
    {--canCollide;}
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
    if(birdDeadCounter>0)
    {
        --birdDeadCounter;
        if(birdDeadCounter<=0)
        {
            scene()->removeItem(removeBird);
        }
    }

    //check ob es eine Kollision gibt
    QList<QGraphicsItem*> collideList = scene()->collidingItems(this);


    //if(!(collideList.isEmpty()))
    for(int i=0; i<collideList.size(); ++i)
    {

        //finde Typ des kollidierenden Objectes heraus (BorderLine oder GroundMaterial)
        int sw = collideList.at(i)->type();

        BorderLine* borderline;
        int angle;

        switch(sw)
        {
            case CourtElement::borderline_type: //Kollision mit Spielfeldrand, abprallen

                //Jetzt weis man, dass es eine Borderline ist, also caste QGraphicsItem* in BorderLine*
                borderline = static_cast<BorderLine*>(collideList.at(i));
                angle = borderline->getAngle();

                if(canCollide<=0)
                {
                    //angle ist relativ zu 3 Uhr (Uhrzeigersinn), rotation ist relativ zu 12 Uhr (Uhrzeigersinn)
                    setRotation(2*(angle+90.0-rotation()) + rotation());

                    speed = speed * borderline->getReflectionCoefficient();

                    //emit angleChanged();

                    canCollide = 4;
                }

            break;

            case 7: //Vogel abgeschossen! (7 = Pixmap)

                removeBird = static_cast<QGraphicsPixmapItem*>(collideList.at(i));
                removeBird->setPixmap(birdDeadPicture);
                birdDeadCounter = 30;
            break;

            default: break;
        }


    }
}
