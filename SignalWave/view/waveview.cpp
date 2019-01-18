#include "waveview.h"
#include "ui_waveview.h"
#include "processing.h"

using namespace std;

WaveView::WaveView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaveView)
{
    ui->setupUi(this);



    signalChart = new QChart();
    fftChart = new QChart();

    signalChart->legend()->hide();
    signalChart->setTitle("Signal");

    fftChart->legend()->hide();
    fftChart->setTitle("FFT");

    ui->mainWaveWidget->setChart(signalChart);
    ui->fftWiget->setChart(fftChart);


}

WaveView::~WaveView()
{
    delete ui;
}

void WaveView::on_AppendButton_clicked()
{
    signalChart->removeAllSeries();
    fftChart->removeAllSeries();

    Processing p;

    fftSeries = new QLineSeries();
    signalSeries = new QLineSeries();




    const int nSamples = ui->SampleSpinBx->value();

    sSignal =  std::shared_ptr<SineSignal>(new SineSignal(ui->spinBox->value(), 1, nSamples));

    auto vectorSignal = sSignal->getVector();

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

void WaveView::on_pushButton_clicked()
{
    signalChart->removeAllSeries();
    fftChart->removeAllSeries();
}
