#include "mainpresenter.h"
#include <QMessageBox>

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{

}

int MainPresenter::compute(int a, int b)
{
    return a + b;
}

void MainPresenter::do1()
{
    QMessageBox msg;
    msg.setText("111dsds");
    msg.exec();

}
