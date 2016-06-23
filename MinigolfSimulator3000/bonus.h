#ifndef BONUS_H
#define BONUS_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Bonus : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    //! \brief Constructor
    Bonus(QGraphicsItem *parent=0);

    //! \brief Return chosen player's bonus
    int getBonus(int _bonus);

public slots:

    //! \brief Increase the player 1's bonus bar
    void increase1();

    //! \brief Increase the player 2's bonus bar
    void increase2();

private:
    int bonus1 = 0, bonus2 = 0;
};

#endif // BONUS_H
