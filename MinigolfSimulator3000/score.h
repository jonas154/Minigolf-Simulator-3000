#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>


//! \brief Object for calculating the player's score
class Score : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    //! \brief Constructor
    Score(QGraphicsItem *parent=0);

    //! \brief Return chosen player's score
    int getScore(int _score);

public slots:

    //! \brief Increase the chosen player's score bar
    void increase(int _score);

private:
    int score1, score2;
};

#endif // SCORE_H
