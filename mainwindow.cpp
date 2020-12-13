#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
