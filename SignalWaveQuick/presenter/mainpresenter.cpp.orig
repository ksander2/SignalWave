#include "mainpresenter.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include "processing.h"

#include "Signals/sinesignal.h"
#include "Signals/squaresignal.h"
#include "Signals/sawsignal.h"
#include "Signals/trianglesignal.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{

}

int MainPresenter::compute(int a, int b)
{
    return a + b;
}

QVector<qreal> MainPresenter::computevec(int frequency, int amplitude, int samples, int type)
{
    ISignal *sig = buildSignalPtr(frequency, amplitude, samples, type);
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
       vecfft[i] = abs(fftArray[i]);
    }

    return vecfft;
}

ISignal *MainPresenter::buildSignalPtr(int frequency, int amplitude, int samples, int type)
{
    ISignal  *builtSignal = nullptr;

    switch (type) {
    case 0:
        builtSignal = new SineSignal(frequency, amplitude, samples);
        break;
    case 1:
        builtSignal = new SquareSignal(frequency, amplitude, samples);
        break;
    case 2:
        builtSignal = new SawSignal(frequency, amplitude, samples);
        break;
    case 3:
        builtSignal = new TriangleSignal(frequency, amplitude, samples);
        break;
    default:
        break;
    }

    return builtSignal;
}
