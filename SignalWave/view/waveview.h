#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QMainWindow>
#include <QtCharts>

namespace Ui {
class WaveView;
}

class WaveView : public QMainWindow
{
    Q_OBJECT

public:
    explicit WaveView(QWidget *parent = 0);
    ~WaveView();

private:
    Ui::WaveView *ui;

    QLineSeries *fftSeries;
    QLineSeries *signalSeries;

    QChart *signalChart;
    QChart *fftChart;
};

#endif // WAVEVIEW_H
