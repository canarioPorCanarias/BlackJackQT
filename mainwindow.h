#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "deck.h"
#include <QMainWindow>
#include <QTime>
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    deck newdeck;
    void newgamestart();
private slots:
    void on_shows_clicked();
    void start_round();
    void openmenu();
    void on_Bhit_clicked();
    void on_Bstand_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
#include <QPixmap>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <QMessageBox>
