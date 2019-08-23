#include "mainwindow.h"
#include <QApplication>
#include"modelex.h"
#include<QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    ModelEx modelEx;
    QTableView  tableView;
    tableView.setModel(&modelEx);
    tableView.setWindowTitle(QObject::tr("哈哈哈哈"));
    tableView.resize(400,400);
    tableView.show();

    return a.exec();
}
