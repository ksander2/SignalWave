#include "waveview.h"
#include "ui_waveview.h"
#include "processing.h"
#include "model/signaltypemodel.h"

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
    fftChart->setTitle("Fast fourier transform");

    ui->mainWaveWidget->setChart(signalChart);
    ui->fftWiget->setChart(fftChart);

    SignalTypeModel *stm = new SignalTypeModel;

    ui->SignalTypeCmbx->setModel(stm);

    createFirstAxes();
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
    emit addSineSignal(ui->spinBox->value(),1 ,ui->SampleSpinBx->value());
}

void WaveView::createFirstAxes()
{
    QLineSeries * signalSeries = new QLineSeries;
    signalSeries->append(0, 0);
    signalSeries->append(100,0);
    signalChart->addSeries(signalSeries);
    signalChart->createDefaultAxes();
    signalChart->axisX()->setTitleText("Frequency, Hz");

    QLineSeries * fftSeries = new QLineSeries;
    fftSeries->append(0, 0);
    fftSeries->append(100,0);
    fftChart->addSeries(fftSeries);
    fftChart->createDefaultAxes();
    fftChart->axisX()->setTitleText("Samples");
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
    signalChart->axisX()->setTitleText("Frequency, Hz");
    fftChart->axisX()->setTitleText("Samples");
}

int WaveView::getIndexSignalType()
{
    ui->SignalTypeCmbx->currentIndex();
}


