#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QMainWindow>
#include <QtCharts>
#include "Signals/sinesignal.h"

namespace Ui {
class WaveView;
}

class WaveView : public QMainWindow
{
    Q_OBJECT

public:
    explicit WaveView(QWidget *parent = 0);
    ~WaveView();

private slots:
    void on_AppendButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::WaveView *ui;

    QLineSeries *fftSeries;
    QLineSeries *signalSeries;

    QChart *signalChart;
    QChart *fftChart;

    std::shared_ptr<SineSignal> sSignal;
};

#endif // WAVEVIEW_H
