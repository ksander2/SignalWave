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
    emit buildSineSignal(ui->spinBox->value(),1 ,ui->SampleSpinBx->value());
}

void WaveView::on_pushButton_clicked()
{
    signalChart->removeAllSeries();
    fftChart->removeAllSeries();
}

void WaveView::updateView(WaveModel &model)
{
    signalChart->removeAllSeries();
    fftChart->removeAllSeries();

    fftSeries = new QLineSeries();
    signalSeries = new QLineSeries();

    for(int i=0; i<model.signal.size(); i++) {
        signalSeries->append(i, model.signal[i].real());
    }

    signalChart->addSeries(signalSeries);

    for(int i=0; i<model.samplesFft/2; i++)
    {
        QLineSeries * series = new QLineSeries;

        series->append(i,0);
        series->append(i,abs(model.fft[i]));

        QPen p(QColor("blue"));
        p.setWidth(2);
        series->setPen(p);

        fftChart->addSeries(series);
    }

    signalChart->createDefaultAxes();
    fftChart->createDefaultAxes();
}
