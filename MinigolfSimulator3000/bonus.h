#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Bonus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bonus(QGraphicsItem *parent=0);
    int getBonus(int _bonus);
public slots:
    void increase(int _bonus);
private:
    int bonus1, bonus2;
};

#endif // BONUS_H
