#include "settings.h"

settings::settings(QWidget *parent)
	: QDialog(parent)
{
	setWindowIcon(QIcon((":/res/res/gear.png")));
	ui.setupUi(this);
	
}

settings::~settings()
{
	
}
