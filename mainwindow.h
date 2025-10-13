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

private slots:

    int startcheck(QString firstnum, QString secondnum, QString thirdnum);
    void startinst();
    void errfirstnum();
    void errsecondnum();
    void errthirdnun();

    void on_act_btn_clicked();

    void on_txt_fn_textChanged(const QString &arg1);

    void on_txt_sn_textChanged(const QString &arg1);

    void on_txt_tn_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
