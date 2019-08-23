#include "mainwindow.h"
#include<QToolBar>
#include<QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    zyWidget = new ZYWidget;
    setCentralWidget(zyWidget);
    createToolBar();
    setMinimumSize(600,400);
    ShowStyle();

    zyWidget->setWidth(widthSpinBox->value());
     zyWidget->setColor(Qt::black);
}

MainWindow::~MainWindow()
{

}


void MainWindow::createToolBar(){
    QToolBar *toolBar = addToolBar("Tool");
    styleLable = new QLabel(tr("线性风格："));
    styleComBox = new QComboBox;
    styleComBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    styleComBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    styleComBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    styleComBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    styleComBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    connect(styleComBox,SIGNAL(activated(int)),this,SLOT(ShowStyle()));

     widthLable = new QLabel(tr("线宽："));
    widthSpinBox = new QSpinBox;
    connect(widthSpinBox,SIGNAL(valueChanged(int)),zyWidget,SLOT(setWidth(int)));
    colorBtn = new QToolButton;
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(ShowColor()));
            clearBtn = new QToolButton;
    clearBtn->setText(tr("清除"));
    connect(clearBtn,SIGNAL(clicked()),zyWidget, SLOT(clear()));
    toolBar->addWidget(styleLable);
    toolBar->addWidget(styleComBox);
    toolBar->addWidget(widthLable);
    toolBar->addWidget(widthSpinBox);
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);


}


void MainWindow::ShowStyle(){

    zyWidget->setStyle(styleComBox->itemData(
        styleComBox->currentIndex(),Qt::UserRole).toInt());
}

void MainWindow::ShowColor(){
    QColor color = QColorDialog::getColor(static_cast<int>(Qt::black),this);
    if(color.isValid()){
         zyWidget->setColor(color);
         QPixmap p(20,20);
         p.fill(color);
         colorBtn->setIcon(QIcon(p));
    }

}
