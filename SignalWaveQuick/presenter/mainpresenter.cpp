#include "mainpresenter.h"
#include <QMessageBox>
#include "Signals/isignal.h"
#include <iostream>

#include "processing.h"

#include "Signals/sinesignal.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{

}

int MainPresenter::compute(int a, int b)
{
    return a + b;
}

QVector<qreal> MainPresenter::computevec(int frequency, int amplitude, int samples)
{
    ISignal *sig = new SineSignal(frequency, amplitude, samples);
    sig->computeSignal();
    std::vector<std::complex<double> > vectorSig = sig->getVector();
    std::vector<double> vec(vectorSig.size());

    QVector<qreal> vec1(vectorSig.size());

    for (int i = 0; i < vectorSig.size(); ++i) {
        std::complex<double> dd = vectorSig[i];
        vec1[i] = dd.real();
    }

    return vec1;
}

QVector<qreal> MainPresenter::computefft(const QVector<qreal> &array)
{

    std::complex<double> *fftArray = new std::complex<double>[array.size()];
    for(int i=0; i< array.size(); i++)
    {
        std::complex<double> *ffttemp = fftArray + i;
        *ffttemp = array[i];
        *(fftArray +i) =  *ffttemp;
    }

    Processing p;
    p.fft2(fftArray, static_cast<int>(array.size()));

    QVector<qreal> vecfft(array.size()/2);

    for(int i=0; i< vecfft.size(); i++)
    {
       vecfft[i] = fftArray[i].imag();
    }

    return vecfft;
}

void MainPresenter::do1()
{
    QMessageBox msg;
    msg.setText("111dsds");
    msg.exec();

}
