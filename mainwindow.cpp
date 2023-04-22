#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "deck.h"
#include "hands.h"

void delay(int millisecondsToWait)
{
	QTime dieTime = QTime::currentTime().addMSecs(millisecondsToWait);
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}


MainWindow::MainWindow(QWidget *parent)
		: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	login log;
	log.setModal(true);
	log.exec();
	ui->label_name->setText("Name: " + name);
	ui->label_money->setText("Money: " + money + " $");
	ui->frame2->hide();
	ui->widget_status->hide();
	ui->settings->setStyleSheet("QPushButton { qproperty-icon: url(:/res/res/gear.png); }");
	setWindowIcon(QIcon((":/deck/aces.png")));

	// full screen 
	// QMainWindow::showFullScreen();
}
void MainWindow::newgamestart()
{
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
	ui->dealer_num->hide();
	ui->shows->show();
};

int sum(std::vector<int> const &vec)
{
	int total = 0;
	int jack = 0;
	for (int i = 0; i < (int)vec.size(); i++)
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

	return total;
}

bool is_number(std::string value)
{
	char num = (char)value[0];
	if (isdigit(num))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getvalue(std::string card)
{
	int value;
	card.erase(0, 7);
	card.erase(card.length() - 4);
	if (is_number(card))
	{
		value = std::stoi(card);
	}
	else
	{
		value = 10;
	}
	return value;
}

void MainWindow::start_round()
{
	ui->frame2->hide();
	ui->shows->hide();
	ui->player_num->show();
	ui->dealer_num->show();
	// dealer second hand
	QPixmap backcard(":/deck/gray_back.png");
	std::string dcard2 = newdeck.card();
	dhand.push_back(getvalue(":/deck/" + dcard2));
	QPixmap dhand2((":/deck/" + dcard2).c_str());
	ui->hand2_d->setPixmap(dhand2.scaled(100, 100, Qt::KeepAspectRatio));
	ui->hand2_d->hide();
	std::string dcard = newdeck.card();
	QPixmap pix((":/deck/" + dcard).c_str());
	dhand.push_back(getvalue(":/deck/" + dcard));
	ui->hand1_d->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
	
	ui->dealer_num->setText(std::to_string(dhand[1]).c_str());
	std::string pcard = newdeck.card();
	pcard = newdeck.card();
	std::string pcard2 = newdeck.card();

	QPixmap fcard((":/deck/" + pcard).c_str());
	QPixmap scard((":/deck/" + pcard2).c_str());
	

	phand.push_back(getvalue(":/deck/" + pcard));
	phand.push_back(getvalue(":/deck/" + pcard2));

	ui->hand1_p->setPixmap(fcard.scaled(100, 100, Qt::KeepAspectRatio));
	ui->hand2_p->setPixmap(scard.scaled(100, 100, Qt::KeepAspectRatio));
	ui->player_num->setText(std::to_string(sum(phand)).c_str());

	if (sum(phand) == 21 && sum(dhand) != 21)
	{
		CustomMessageBox("Win", "Congratulations");
		newgamestart();
	}
	else if (sum(phand) == 21 && sum(dhand) == 21)
	{
		ui->hand2_d->show();
		CustomMessageBox("Tie", "Money Pushed");
		newgamestart();
	}
	
}

void MainWindow::openmenu()
{
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
	delay(1000);
	std::string newcard = newdeck.card();
	QPixmap pixnewcard((":/deck/" + newcard).c_str());
	phand.push_back(getvalue(":/deck/" + newcard));
	ui->player_num->setText(std::to_string(sum(phand)).c_str());
	if ((ui->hand3_p->pixmap(Qt::ReturnByValue).isNull()))
	{
		ui->hand3_p->setPixmap(pixnewcard.scaled(100, 100, Qt::KeepAspectRatio));
	}
	else if ((ui->hand4_p->pixmap(Qt::ReturnByValue).isNull()))
	{
		ui->hand4_p->setPixmap(pixnewcard.scaled(100, 100, Qt::KeepAspectRatio));
	}
	delay(1000);
	if (sum(phand) > 21)
	{
		CustomMessageBox("Lose", "Too many");    
		newgamestart();
		return;
	}
	else if (sum(phand) == 21)
	{
		ui->hand2_d->show();
		CustomMessageBox("Black Jack", "You win");
		newgamestart();
		return;
	}
	else
	{
		ui->frame2->show();
	}
}

void MainWindow::on_Bstand_clicked()
{
	ui->shows->hide();
	ui->frame2->hide();
	ui->hand2_d->show();

	ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
	if (sum(dhand) == 16 && sum(phand) == 16)
	{
		CustomMessageBox("Tie", "Money Pushed");
		newgamestart();
		return;
	}

	if (sum(dhand) > sum(phand)) {
		CustomMessageBox("Lose", "Dealer have higher value");
		newgamestart();
		return;
	}

	while (sum(dhand) < 17)
	{
		delay(700);
		if (ui->hand3_d->pixmap(Qt::ReturnByValue).isNull())
		{
			std::string more = newdeck.card();
			dhand.push_back(getvalue(":/deck/" + more));
			QPixmap hand3((":/deck/" + more).c_str());
			ui->hand3_d->setPixmap(hand3.scaled(100, 100, Qt::KeepAspectRatio));
			ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
			ui->hand3_d->show();
			continue;
		}
		else if (ui->hand4_d->pixmap(Qt::ReturnByValue).isNull())
		{
			std::string more = newdeck.card();
			dhand.push_back(getvalue(":/deck/" + more));
			QPixmap hand4((":/deck/" + more).c_str());
			ui->hand4_d->setPixmap(hand4.scaled(100, 100, Qt::KeepAspectRatio));
			ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
			ui->hand4_d->show();
			continue;
		}
		else if (ui->hand5_d->pixmap(Qt::ReturnByValue).isNull())
		{
			std::string more = newdeck.card();
			dhand.push_back(getvalue(":/deck/" + more));
			QPixmap hand5((":/deck/" + more).c_str());
			ui->hand5_d->setPixmap(hand5.scaled(100, 100, Qt::KeepAspectRatio));
			ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
			ui->hand5_d->show();
			continue;
		}
		else if (ui->hand6_d->pixmap(Qt::ReturnByValue).isNull())
		{
			std::string more = newdeck.card();
			dhand.push_back(getvalue(":/deck/" + more));
			QPixmap hand5((":/deck/" + more).c_str());
			ui->hand6_d->setPixmap(hand5.scaled(100, 100, Qt::KeepAspectRatio));
			ui->dealer_num->setText(std::to_string(sum(dhand)).c_str());
			ui->hand6_d->show();
			continue;
		}
		
	}
	if (sum(dhand) < 17 && sum(phand) <= 21 && sum(dhand) < sum(phand))
	{
		CustomMessageBox("Win", "You have higher cards");
		
	}
	else if (sum(dhand) >= 22)
	{
		CustomMessageBox("Win", "dealer bust");
		
	}
	else if (sum(dhand) == sum(phand))
	{
		CustomMessageBox("Tie", "Money Pushed");
		
	}
	else if (sum(dhand) > sum(phand) && sum(phand) < 21)
	{
		CustomMessageBox("Lose", "dealer have higher cards");
	}
	else if (sum(phand) > sum(dhand))
	{
		CustomMessageBox("Win", "you have higher cards");
	}
	else if (sum(phand) == sum(dhand))
	{
		CustomMessageBox("Tie", "Money Pushed");
	}
	newgamestart();
}
	


void MainWindow::CustomMessageBox(QString title, QString body)
{
	ui->frame_status_label_title->clear();
	ui->frame_status_label_body->clear();
	ui->widget_status->show();
	ui->frame_status_label_title->setText(title);
	ui->frame_status_label_body->setText(body);
	delay(2000);
	ui->widget_status->hide();
	
}

void MainWindow::on_settings_clicked()
{
	settings window = new settings();
	window.exec();
}
