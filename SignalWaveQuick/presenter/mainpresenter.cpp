#include "mainpresenter.h"
#include <QMessageBox>

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{

}

void MainPresenter::do1()
{
    QMessageBox msg;
    msg.setText("111dsds");
    msg.exec();

}
