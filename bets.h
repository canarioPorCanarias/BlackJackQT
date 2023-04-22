#ifndef BETS_H
#define BETS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class bets : public QObject
{
    Q_OBJECT
public:
    void setBet(int value);
    bets();
signals:
    void updateBet(int value);

private:
    int bet;
};

#endif // BETS_H
