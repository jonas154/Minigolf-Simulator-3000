#ifndef COURT2_H
#define COURT2_H

#include <QWidget>

namespace Ui {
class Court2;
}

class Court2 : public QWidget
{
    Q_OBJECT

public:
    explicit Court2(QWidget *parent = 0);
    ~Court2();

private:
    Ui::Court2 *ui;
};

#endif // COURT2_H
