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
    int getScore();
public slots:
    void increase();
private:
    int score;
};

#endif // SCORE_H
