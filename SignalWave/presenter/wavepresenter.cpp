#include "wavepresenter.h"

WavePresenter::WavePresenter()
    : _waveView(new WaveView)
{

}

void WavePresenter::showView()
{
    _waveView->show();
}
