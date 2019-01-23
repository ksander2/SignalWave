#ifndef WAVEPRESENTER_H
#define WAVEPRESENTER_H

#include "view/waveview.h"
#include <QObject>

class WavePresenter : public QObject
{
    Q_OBJECT
public:
    WavePresenter();
    void showView();


private:
    WaveView *_waveView;
    std::shared_ptr<SineSignal> sSignal;
    void buildSignal(int frequency, int amplitude, int samples);

};

#endif // WAVEPRESENTER_H
