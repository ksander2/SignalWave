#include "waveview.h"
#include "ui_waveview.h"
#include "processing.h"
#include "Signals/sinesignal.h"

using namespace std;

WaveView::WaveView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaveView)
{
    ui->setupUi(this);

    Processing p;

    fftSeries = new QLineSeries();
    signalSeries = new QLineSeries();

    signalChart = new QChart();

    fftChart = new QChart();

    signalChart->legend()->hide();
    signalChart->setTitle("Signal");

    fftChart->legend()->hide();
    fftChart->setTitle("FFT");

    ui->mainWaveWidget->setChart(signalChart);
    ui->fftWiget->setChart(fftChart);

    const int nSamples = 256;

    SineSignal  sSignal(50,1,nSamples);

    SineSignal s2 = sSignal;

    auto vectorSignal = s2.getVector();

    for(int i=0; i<vectorSignal.size(); i++) {
        signalSeries->append(i, vectorSignal[i].real());
    }


    signalChart->addSeries(signalSeries);
    signalChart->createDefaultAxes();


    complex<double> *X = vectorSignal.data();

    p.fft2(X, vectorSignal.size());

    for(int i=0; i<nSamples/2; i++)
    {
        QLineSeries * series = new QLineSeries;

        series->append(i,0);
        series->append(i,abs(X[i]));

        QPen p(QColor("blue"));
        p.setWidth(2);
        series->setPen(p);

        fftChart->addSeries(series);
    }

    fftChart->createDefaultAxes();

}

WaveView::~WaveView()
{
    delete ui;
}
