#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}
QString name;
QString money;
void login::on_pushButton_clicked()
{
    name=ui->name_input->text();
    money=ui->money_input->text();
    close();
}


