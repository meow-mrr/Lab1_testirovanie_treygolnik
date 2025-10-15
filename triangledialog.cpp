#include "triangledialog.h"
#include <QPainter>
#include <QtMath>

TriangleDialog::TriangleDialog(int a, int b, int c, QWidget *parent)
    : QDialog(parent), sideA(a), sideB(b), sideC(c)
{
    setWindowTitle("Визуализация треугольника");
    resize(400, 400);
}

void TriangleDialog::paintEvent(QPaintEvent*)
{
    QPainter painter(this);

    double scale = 300.0 / qMax(qMax(sideA, sideB), sideC);

    double a = sideA * scale;
    double b = sideB * scale;
    double c = sideC * scale;

    double x = (b*b + c*c - a*a) / (2*c);
    double y = qSqrt(b*b - x*x);

    QPointF A(50, 350);
    QPointF B(50 + c, 350);
    QPointF C(50 + x, 350 - y);

    QPolygonF triangle;
    triangle << A << B << C;

    painter.setPen(Qt::black);
    painter.setBrush(QColor(173, 216, 230));
    painter.drawPolygon(triangle);

    painter.setPen(Qt::red);
    painter.drawText(A + QPointF(-10, 20), "A");
    painter.drawText(B + QPointF(10, 20), "B");
    painter.drawText(C + QPointF(0, -10), "C");
}
