#include "ZYWidget.h"
#include <QtGui>
#include <QPen>

ZYWidget::ZYWidget(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);    //对窗体背景色的设置
    setPalette(QPalette(Qt::white));
    pix =new QPixmap(size());      	//此QPixmap对象用来准备随时接收绘制的内容
    pix->fill(Qt::white);           //填充背景色为白色
    setMinimumSize(600,400);      	//设置绘制区窗体的最小尺寸
}

void ZYWidget::setStyle(int s)
{
    style = s;
}

void ZYWidget::setWidth(int w)
{
    weight = w;
}

void ZYWidget::setColor(QColor c)
{
    color = c;
}

void ZYWidget::mousePressEvent(QMouseEvent *e)
{
    startPos = e->pos();
}

void ZYWidget::mouseMoveEvent(QMouseEvent *e)
{
    QPainter *painter = new QPainter;

    QPen pen;
    pen.setStyle((Qt::PenStyle)style);
    pen.setWidth(weight);
    pen.setColor(color);

    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos,e->pos());
    painter->end();
    startPos =e->pos();
    update();
}

void ZYWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}

void ZYWidget::resizeEvent(QResizeEvent *event)
{
    if(height()>pix->height()||width()>pix->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}

void ZYWidget::clear()
{
    QPixmap *clearPix =new QPixmap(size());
    clearPix->fill(Qt::white);
    pix = clearPix;
    update();
}
