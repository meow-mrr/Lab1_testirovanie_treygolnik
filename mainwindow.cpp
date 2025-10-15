#include "mainwindow.h"
#include "triangledialog.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::errfirstnum()
{
    ui->errorlabelfirst->setText("Неверный формат данных!");
    ui->errorlabelfirst->setStyleSheet("QLabel { color : red; }");

    ui->txt_fn->setStyleSheet("QLineEdit { border: red; }");
    ui->txt_fn->setStyleSheet("QLineEdit { color: red; }");

}

void MainWindow::errsecondnum()
{
    ui->errorlabelsecond->setText("Неверный формат данных!");
    ui->errorlabelsecond->setStyleSheet("QLabel { color : red; }");

    ui->txt_sn->setStyleSheet("QLineEdit { border: red; }");
    ui->txt_sn->setStyleSheet("QLineEdit { color: red; }");

}

void MainWindow::errthirdnun()
{
    ui->errorlabelthird->setText("Неверный формат данных!");
    ui->errorlabelthird->setStyleSheet("QLabel { color : red; }");

    ui->txt_tn->setStyleSheet("QLineEdit { border: red; }");
    ui->txt_tn->setStyleSheet("QLineEdit { color: red; }");

}

int MainWindow::startcheck(QString firstnum, QString secondnum, QString thirdnum)
{
    int a = 0;
    if(firstnum == "" or !QRegularExpression("^\\d+$").match(firstnum).hasMatch())
    {
        a++;
        errfirstnum();
    }
    if(secondnum == "" or !QRegularExpression("^\\d+$").match(secondnum).hasMatch())
    {
        a++;
        errsecondnum();
    }
    if(thirdnum == "" or !QRegularExpression("^\\d+$").match(thirdnum).hasMatch())
    {
        a++;
        errthirdnun();
    }
    return a;
}

void MainWindow::startinst()
{
    ui->errorlabelfirst->setText("");
    ui->txt_fn->setStyleSheet("QLabel { color : white; }");
    ui->errorlabelsecond->setText("");
    ui->txt_sn->setStyleSheet("QLabel { color : white; }");
    ui->errorlabelthird->setText("");
    ui->txt_tn->setStyleSheet("QLabel { color : white; }");
}

void MainWindow::on_act_btn_clicked()
{
    startinst();

    QString firstnum = ui->txt_fn->text();
    QString secondnum = ui->txt_sn->text();
    QString thirdnum = ui->txt_tn->text();

    if(startcheck(firstnum, secondnum, thirdnum) != 0)
    {
        return;
    }

    int firstnum2 = firstnum.toInt();
    int secondnum2 = secondnum.toInt();
    int thirdnum2 = thirdnum.toInt();

    int ercount = 0;

    if(firstnum2+secondnum2<thirdnum2 or firstnum2+thirdnum2<secondnum2 or secondnum2+thirdnum2<firstnum2)
    {
        ui->answerlabel->setText("Такого треугольника не существует!!");
        ercount++;
    }
    else if(firstnum2 == secondnum2 and firstnum2 == thirdnum2 and secondnum2 == thirdnum2)
    {
        ui->answerlabel->setText("Равносторонник трегольник!!");
    }
    else if(firstnum2==secondnum2 or firstnum2==thirdnum2 or secondnum2==thirdnum2)
    {
        ui->answerlabel->setText("Равнобедренный трегольник!!");
    }
    else
    {
        ui->answerlabel->setText("Произвольный трегольник!!");
    }

    if(ercount==0){
        TriangleDialog *dlg = new TriangleDialog(firstnum2, secondnum2, thirdnum2, this);
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show();
    }
}



void MainWindow::on_txt_fn_textChanged(const QString &arg1)
{
    ui->errorlabelfirst->setText("");
    ui->txt_fn->setStyleSheet("QLabel { color : white; }");
}


void MainWindow::on_txt_sn_textChanged(const QString &arg1)
{
    ui->errorlabelsecond->setText("");
    ui->txt_sn->setStyleSheet("QLabel { color : white; }");
}


void MainWindow::on_txt_tn_textChanged(const QString &arg1)
{
    ui->errorlabelthird->setText("");
    ui->txt_tn->setStyleSheet("QLabel { color : white; }");
}


