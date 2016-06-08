#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>

class Score : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Score(QGraphicsItem *parent=0);
    int getScore(int _score);
public slots:
    void increase(int _score);
private:
    int score1, score2;
};

#endif // SCORE_H
