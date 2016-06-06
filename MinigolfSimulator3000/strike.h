#ifndef STRIKE_H
#define STRIKE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Strike : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Strike(QGraphicsItem *parent=0);
    int getStrike(int _strike);
public slots:
    void decrease(int _strike);
private:
    int strike1, strike2;
};

#endif // STRIKE_H
