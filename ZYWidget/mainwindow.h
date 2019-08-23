#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QToolButton>
#include<QLabel>
#include<QComboBox>
#include<QSpinBox>
#include"zywidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void createToolBar();
public slots:
    void ShowStyle();
    void ShowColor();

private:
    ZYWidget *zyWidget;
    QLabel *styleLable;
    QComboBox *styleComBox;
    QLabel *widthLable;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
};

#endif // MAINWINDOW_H
