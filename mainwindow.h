#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    std::vector<int>dhand;
    std::vector<int>dhandbj;
    std::vector<int>phand;
    std::vector<int>phandbj;
private slots:
    void on_shows_clicked();
    void give_d_card();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
#include <QPixmap>
