#include "waveview.h"
#include "ui_waveview.h"
#include "processing.h"

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
    double nSeconds = 1.0;                      // total time for sampling
    double sampleRate = nSamples / nSeconds;    // n Hz = n / second
    double freqResolution = sampleRate / nSamples; // freq step in FFT result
    complex<double> x[nSamples];                // storage for sample data
    complex<double> X[nSamples];                // storage for FFT answer
    const int nFreqs = 1;
    double freq[] = { 10, 240, 11, 17, 29,50 }; // known freqs for testing

    for(int i=0; i<nSamples; i++) {
        x[i] = complex<double>(0.,0.);

        for(int j=0; j<nFreqs; j++)
            x[i] += sin( 2*M_PI*freq[j]*i/nSamples );
        //X[i] = x[i];        // copy into X[] for FFT work & result
    }

    p.meandr(x,nSamples);

    for(int i=0; i<nSamples; i++) {
       X[i] = x[i];
    }

    for(int i=0; i<nSamples; i++) {
        signalSeries->append(i, x[i].real());
    }


    signalChart->addSeries(signalSeries);
    signalChart->createDefaultAxes();


    p.fft2(X,nSamples);

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
