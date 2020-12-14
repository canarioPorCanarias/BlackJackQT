#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "deck.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    login log;
//    log.setModal(true);
//    log.exec();
    ui->label_name->setText("Name: "+name);
    ui->label_money->setText("Money: " + money);
    //QMainWindow::showFullScreen();
    //full screen
}



void MainWindow::give_d_card(){
    deck newdeck;
    std::string route=":/deck/";
    std::string card = newdeck.card();
    route+=card;
    QPixmap pix(route.c_str());
    //ui->hand1_d->setText(route.c_str());
    ui->hand1_d->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap Reverse(":/deck/gray_back.png");
    ui->hand2_d->setPixmap(Reverse.scaled(100,100,Qt::KeepAspectRatio));

}



void MainWindow::on_shows_clicked()
{

    give_d_card();




}


MainWindow::~MainWindow()
{
    delete ui;
}
