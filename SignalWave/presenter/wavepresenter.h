#ifndef WAVEPRESENTER_H
#define WAVEPRESENTER_H

#include "view/waveview.h"
#include <QObject>

class WavePresenter : public QObject
{
    Q_OBJECT
public:
    WavePresenter();
    virtual ~WavePresenter();

    void showView();


private:
    WaveView *_waveView;
    SineSignal *sSignal;
    void buildSignal(int frequency, int amplitude, int samples);
    void addSineSignal(int frequency, int amplitude, int samples);
    void addSineSignalToView(SineSignal *signal);

};

#endif // WAVEPRESENTER_H
