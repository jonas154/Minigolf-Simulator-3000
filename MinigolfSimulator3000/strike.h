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
    int getStrike();
public slots:
    void decrease();
private:
    int strike;
};

#endif // STRIKE_H
