#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "deck.h"
#include "hands.cpp"

void delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
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
    ui->frame2->hide();
    //QMainWindow::showFullScreen();
    //full screen

}
void MainWindow::newgamestart(){
    ui->frame2->hide();
    dhand.clear();
    phand.clear();
    ui->hand1_p->clear();
    ui->hand2_p->clear();
    ui->hand3_p->clear();
    ui->hand4_p->clear();
    ui->hand5_p->clear();
    ui->hand6_p->clear();
    ui->hand1_d->clear();
    ui->hand2_d->clear();
    ui->hand3_d->clear();
    ui->hand4_d->clear();
    ui->hand5_d->clear();
    ui->hand6_d->clear();
    ui->player_num->hide();
    ui->player_num->hide();
    ui->shows->show();
};

int sum(std::vector<int> const &vec)
{
    int total = 0;
    int jack = 0;
    for (int i = 0; i < (int) vec.size(); i++)
    {

        if (vec.at(i) == 1)
        {
            jack += 1;
        }
        else
        {
            total += vec.at(i);
        }
    }

    if (jack && (total <= (11 - jack)))
    {
        total += 10 + jack;
    }
    else if (jack >= 1)
    {
        total += jack;
    }
    // if (jack == 1 && (total <= 10))
    // {
    //     total += 11;
    // }
    // else if (jack == 1)
    // {
    //     total += 1;
    // }
    // if (jack == 2 && (total <= 9))
    // {
    //     total += 12;
    // }
    // else if (jack == 2)
    // {
    //     total += 2;
    // }
    // if (jack == 3 && (total <= 8))
    // {
    //     total += 13;
    // }
    // else if (jack == 3)
    // {
    //     total += 3;
    // }

    return total;
}

bool is_number(std::string value)
{
    char num=(char) value[0];
    if(isdigit(num)){
        return true;
    }else{
        return false;
    }
}

int getvalue(std::string card){
        int value;
        card.erase(0,7);
        card.erase(card.length()-4);
        if(is_number(card)){
        value=std::stoi(card);
        }else{
        value=10;
        }
        return value;
}

void MainWindow::start_round(){
//    extern std::vector<int> dhand;
//    extern std::vector<int> phand;
    ui->frame2->hide();
    ui->shows->hide();
    ui->player_num->show();
    ui->player_num->show();
    //dealer second hand
    std::string dcard2 = newdeck.card();
    dhand.push_back(getvalue(":/deck/"+dcard2));
    QPixmap dhand2((":/deck/"+dcard2).c_str());
    ui->hand2_d->setPixmap(dhand2.scaled(100,100,Qt::KeepAspectRatio));
    ui->hand2_d->hide();
    std::string dcard = newdeck.card();
    QPixmap pix((":/deck/"+dcard).c_str());
    dhand.push_back(getvalue(":/deck/"+dcard));
    ui->hand1_d->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
//    QPixmap pix2((":/deck/"+dcard).c_str());
//    ui->hand2_d->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
//    QPixmap Reverse(":/deck/gray_back.png");
//    ui->hand2_d->setPixmap(Reverse.scaled(100,100,Qt::KeepAspectRatio));
    ui->dealer_num->setText(std::to_string(dhand[0]).c_str());
    std::string pcard = newdeck.card();
    pcard=newdeck.card();
    std::string pcard2 = newdeck.card();
    QPixmap fcard((":/deck/"+pcard).c_str());
    QPixmap scard((":/deck/"+pcard2).c_str());
    phand.push_back(getvalue(":/deck/"+pcard));
    phand.push_back(getvalue(":/deck/"+pcard2));
    ui->hand1_p->setPixmap(fcard.scaled(100,100,Qt::KeepAspectRatio));
    ui->hand2_p->setPixmap(scard.scaled(100,100,Qt::KeepAspectRatio));
    ui->player_num->setText(std::to_string(sum(phand)).c_str());
    if(sum(phand)==21 && sum(dhand) !=21){
        QMessageBox::information(this,tr("YOU WIN"),tr("Congratulations"));
        newgamestart();
    }else if(sum(phand)==21 && sum(dhand)==21){
        QMessageBox::information(this,tr("TIE"),tr("PUSH BACK"));
        newgamestart();
    }else if((phand[0]==1 && phand[1]==10) || (phand[1]==1 && phand[0]==10)){
         QMessageBox::information(this,tr("Blackjack"),tr("You won"));
         newgamestart();
    }


    //delay(3000);
    //qDebug() << "first" << ui->hand1_p->pixmap(Qt::ReturnByValue) << "SECOND " << ui->hand4_p->pixmap(Qt::ReturnByValue);

}

void MainWindow::openmenu(){
    ui->frame2->show();
}


void MainWindow::on_shows_clicked()
{
    start_round();
    openmenu();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Bhit_clicked()
{
    ui->shows->hide();
    ui->frame2->hide();
    //delay(1000);
    std::string newcard = newdeck.card();
    QPixmap pixnewcard((":/deck/"+newcard).c_str());
    phand.push_back(getvalue(":/deck/"+newcard));
    ui->player_num->setText(std::to_string(sum(phand)).c_str());
    if((ui->hand3_p->pixmap(Qt::ReturnByValue).isNull())){
            ui->hand3_p->setPixmap(pixnewcard.scaled(100,100,Qt::KeepAspectRatio));
    }else if((ui->hand4_p->pixmap(Qt::ReturnByValue).isNull())){
        ui->hand4_p->setPixmap(pixnewcard.scaled(100,100,Qt::KeepAspectRatio));
    }
    //delay(1000);
    if(sum(phand)>21){
        QMessageBox::information(this,tr("Busted you passed"),tr("good luck next time"));
        newgamestart();

    }else if(sum(phand)==21){
        QMessageBox::information(this,tr("Black Jack"),tr("You win"));
        newgamestart();
    }
    else{
    ui->frame2->show();
    }

}

void MainWindow::on_Bstand_clicked()
{
    ui->shows->hide();
    ui->frame2->hide();

    ui->hand2_d->show();
    ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
    if(sum(dhand)==16 && sum(phand)==16){
        QMessageBox::information(this,tr("Tie"),tr("money pushed"));
    }
    if(sum(dhand)<17){
    while(true){
        if(ui->hand3_d->pixmap(Qt::ReturnByValue).isNull()){
            std::string more = newdeck.card();
            dhand.push_back(getvalue(":/deck/"+more));
            QPixmap hand3((":/deck/"+more).c_str());
            ui->hand3_d->setPixmap(hand3.scaled(100,100,Qt::KeepAspectRatio));
            ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
        }else if(ui->hand4_d->pixmap(Qt::ReturnByValue).isNull()){
            std::string more = newdeck.card();
            dhand.push_back(getvalue(":/deck/"+more));
            QPixmap hand4((":/deck/"+more).c_str());
            ui->hand4_d->setPixmap(hand4.scaled(100,100,Qt::KeepAspectRatio));
            ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
        }else if(ui->hand5_d->pixmap(Qt::ReturnByValue).isNull()){
            std::string more = newdeck.card();
            dhand.push_back(getvalue(":/deck/"+more));
            QPixmap hand5((":/deck/"+more).c_str());
             ui->hand5_d->setPixmap(hand5.scaled(100,100,Qt::KeepAspectRatio));
            ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
        }else if(ui->hand6_d->pixmap(Qt::ReturnByValue).isNull()){
            std::string more = newdeck.card();
            dhand.push_back(getvalue(":/deck/"+more));
            QPixmap hand5((":/deck/"+more).c_str());
             ui->hand6_d->setPixmap(hand5.scaled(100,100,Qt::KeepAspectRatio));
            ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
        }
//        if(sum(dhand)<=17 && sum(phand)<21 && sum(dhand)<sum(phand)){
//            QMessageBox::information(this,tr("You have higher cards"),tr("good job"));
//        }
        if(sum(dhand)>=22){
            QMessageBox::information(this,tr("dealer bust you win"),tr("good job"));
            break;
        } else if(sum(dhand) > sum(phand)){
            QMessageBox::information(this,tr("Dealer have higher value"),tr("good luck next time"));
            break;
        }else if(sum(dhand)==sum(phand)){
            QMessageBox::information(this,tr("Tie"),tr("money pushed"));
            break;
        }
    }
    }
    else if(sum(dhand) > sum(phand) && sum(phand)<21){
        QMessageBox::information(this,tr("dealer wins"),tr("dealer have higher value"));
    }else if(sum(phand) > sum(dhand)){
        QMessageBox::information(this,tr("You wins"),tr("congratulations"));
    }else if (sum(phand) == sum(dhand)){
        QMessageBox::information(this,tr("Tie"),tr("money pushed"));
    }
newgamestart();
}
