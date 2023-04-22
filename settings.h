#pragma once

#include <QDialog>
#include "ui_settings.h"

class settings : public QDialog
{
	Q_OBJECT

public:
	settings(QWidget *parent = nullptr);
	~settings();

private:
	Ui::settingsClass ui;
};
