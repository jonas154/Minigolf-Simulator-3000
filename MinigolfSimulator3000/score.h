#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Score : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    //! \brief Constructor
    Score(QGraphicsItem *parent=0);

    //! \brief Return chosen player's score
    int getScore(int _score);

public slots:

    //! \brief Increase the score bar
    void increase(int _score);

private:
    int score1, score2;
};

#endif // SCORE_H
