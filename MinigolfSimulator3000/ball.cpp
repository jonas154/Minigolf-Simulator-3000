//BEISPIELCODE, WIRD SPÄTER ERSETZT

#include "ball.h"

Ball::Ball()

{
    setFlag(ItemUsesExtendedStyleOption);

    stopped = true;
    canCollide = 0; //Zähler damit Kollision nicht abspackt, kann besser gelöst werden
    speed = 0.0;
    angle = 0.0;

    birdDeadPicture = ":/Images/Images/vtot.png";
    birdDeadCounter = 0;

}

QRectF Ball::boundingRect() const
{
    return QRectF(-3,-3,6,6);
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

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
void Ball::advance(int phase)
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
    if(s>0.0) stopped = false;
    speed = s;
}

void Ball::doCollision()
{
    if(!stopped){

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

        switch(sw)
        {
            case CourtElement::borderline_type: //Kollision mit Spielfeldrand, abprallen
            {
                //Jetzt weis man, dass es eine Borderline ist, also caste QGraphicsItem* in BorderLine*
                BorderLine* borderline = static_cast<BorderLine*>(collideList.at(i));
                int angle = borderline->getAngle();

                if(canCollide<=0)
                {
                    //angle ist relativ zu 3 Uhr (Uhrzeigersinn), rotation ist relativ zu 12 Uhr (Uhrzeigersinn)
                    setRotation(2*(angle+90.0-rotation()) + rotation());

                    speed = speed * borderline->getReflectionCoefficient();

                    //emit angleChanged();

                    canCollide = 4;
                }
            }
            break;

            case CourtElement::groundmaterial_type:
            {
                GroundMaterial* groundmaterial = static_cast<GroundMaterial*>(collideList.at(i));

                double maxspeed = groundmaterial->getMaxSpeed();
                double minspeed = groundmaterial->getMinSpeed();
                double friction = groundmaterial->getFrictionCoefficient();

                switch(groundmaterial->getMaterial())
                {
                    case GroundMaterial::grass_material:
                    case GroundMaterial::concrete_material:
                    case GroundMaterial::wood_material:
                    case GroundMaterial::sand_material:
                    case GroundMaterial::speedUp_material:
                    {
                        speed -= friction;

                        if(speed<minspeed)
                        {
                            speed = 0.0;
                            emit ballStopped();
                            stopped = true;
                        }
                    }
                    break;

                    case GroundMaterial::water_material:

                        speed -= friction*speed;
                        //emit ballInWater();
                    break;

                    case GroundMaterial::nonNewtonian_material:

                        if(speed > minspeed)
                        {
                            speed -= speed*friction;
                        }
                        else if(speed<minspeed)
                        {
                            //emit ballInNewtonian();
                        }
                    break;

                    case GroundMaterial::hole_material:

                        if(speed>maxspeed)
                        {
                            speed -= speed*friction;
                        }
                        else
                        {
                            speed = 0.0;
                            //emit ballInHole();
                        }

                    break;

                    default: break;
                }
            }
            break;

            case 7: //Vogel abgeschossen! (7 = Pixmap)
            {
                removeBird = static_cast<QGraphicsPixmapItem*>(collideList.at(i));
                removeBird->setPixmap(birdDeadPicture);
                birdDeadCounter = 30;
            }
            break;

            default: break;
        }
    }
  }
}
