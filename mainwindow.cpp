#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login log;
    log.setModal(true);
    log.exec();
    ui->label_name->setText("Name: "+name);
    ui->label_money->setText("Money: " + money);

}

void MainWindow::on_shows_clicked()
{
 if(ui->frame2->isHidden()){
     ui->frame2->show();
 }else{
     ui->frame2->hide();
 }

}


MainWindow::~MainWindow()
{
    delete ui;
}
