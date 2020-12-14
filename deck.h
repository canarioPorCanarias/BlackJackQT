#ifndef DECK_H
#define DECK_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>


class deck
{
public:
    deck();
    std::string card();
    std::string give_card();

};

#endif // DECK_H

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
#include <mainwindow.h>
