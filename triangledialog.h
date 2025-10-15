#ifndef TRIANGLEDIALOG_H
#define TRIANGLEDIALOG_H

#pragma once
#include <QDialog>

class TriangleDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TriangleDialog(int a, int b, int c, QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    int sideA, sideB, sideC;
};

#endif // TRIANGLEDIALOG_H
