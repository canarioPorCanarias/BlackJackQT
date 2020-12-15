#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "deck.h"
#include "hands.cpp"


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


bool is_number(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int getvalue(std::string card){

        int value;
        card.erase(0,7);
        card.erase(card.length()-4);
        if(is_number(card)){
        value=std::stoi( card );
        }else{
        value=10;
        }
return value;
}

void MainWindow::give_d_card(int i){
    extern std::vector<int> dhand;
    extern std::vector<int> phand;
    deck newdeck;
    std::string route=":/deck/";
    if(i==1){
    ui->shows->hide();
    ui->frame2->hide();
    std::string dcard = newdeck.card();
    QPixmap pix((":/deck/"+dcard).c_str());
    ui->hand1_d->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
    QPixmap Reverse(":/deck/gray_back.png");
    dhand.push_back(getvalue(":/deck/"+dcard));
    ui->hand2_d->setPixmap(Reverse.scaled(100,100,Qt::KeepAspectRatio));
    ui->dealer_num->setText(std::to_string(dhand[0]).c_str());
    }
    else if(i==2){
        std::string pcard = newdeck.card();
        pcard=newdeck.card();
        std::string pcard2 = newdeck.card();
        QPixmap fcard((":/deck/"+pcard).c_str());
        QPixmap scard((":/deck/"+pcard2).c_str());
        phand.push_back(getvalue(":/deck/"+pcard));
        phand.push_back(getvalue(":/deck/"+pcard2));
        ui->hand1_p->setPixmap(fcard.scaled(100,100,Qt::KeepAspectRatio));
        ui->hand2_p->setPixmap(scard.scaled(100,100,Qt::KeepAspectRatio));
        ui->hand_value->setText(std::to_string(phand[0]+phand[1]).c_str());
    }

}



void MainWindow::on_shows_clicked()
{


    give_d_card(1);
    give_d_card(2);




}


MainWindow::~MainWindow()
{
    delete ui;
}
