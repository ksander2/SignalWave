#ifndef WAVEPRESENTER_H
#define WAVEPRESENTER_H

#include "view/waveview.h"
#include <QObject>
#include "Signals/isignal.h"

class WavePresenter : public QObject
{
    Q_OBJECT
public:
    WavePresenter();
    virtual ~WavePresenter();

    void showView();

private slots:
    void onBuildSignalClicked(int frequency, int amplitude, int samples);
    void onnAddSignalClicked(int frequency, int amplitude, int samples);

private:
    WaveView *_waveView;

    ISignal *currentSignal;
    void addSineSignalToView(ISignal *signal);
    ISignal *buildSignalPtr(int frequency, int amplitude, int samples);


};

#endif // WAVEPRESENTER_H
