#ifndef WAVEPRESENTER_H
#define WAVEPRESENTER_H

#include "view/waveview.h"

class WavePresenter
{

public:
    WavePresenter();
    void showView();

private:
    WaveView *_waveView;

};

#endif // WAVEPRESENTER_H
