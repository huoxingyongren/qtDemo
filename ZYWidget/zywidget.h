#ifndef ZYWIDGET_H
#define ZYWIDGET_H

#include <QWidget>
#include<QColor>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QResizeEvent>
#include<QPixmap>
#include<QPoint>
#include<QPainter>
#include<QPalette>

class ZYWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ZYWidget(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:

public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void clear();

private:
    QPixmap *pix;
    QPoint startPos;
    QPoint endPos;
    int style;
    int weight;
    QColor color;


};

#endif // ZYWIDGET_H
