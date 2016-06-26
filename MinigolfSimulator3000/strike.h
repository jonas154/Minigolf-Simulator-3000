#ifndef STRIKE_H
#define STRIKE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>


//! \brief Object for counting and displaying the player's strikes
class Strike : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    //! \brief Constructor
    Strike(QGraphicsItem *parent=0);

    //! \brief Return chosen player's strike
    int getStrike(int _strike);

public slots:

    //! \brief Decrease the chosen player's strike bar
    void decrease(int _strike);

private:
    int strike1, strike2;
};

#endif // STRIKE_H
