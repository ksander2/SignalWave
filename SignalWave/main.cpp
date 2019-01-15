
#include <QApplication>
#include "presenter/wavepresenter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WavePresenter *wavePresenter = new WavePresenter;
    wavePresenter->showView();

    return a.exec();
}
