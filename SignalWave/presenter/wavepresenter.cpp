#include "wavepresenter.h"
#include "processing.h"

WavePresenter::WavePresenter()
    : _waveView(new WaveView)
{
    connect(_waveView, &WaveView::buildSineSignal, this, &WavePresenter::buildSignal);
}

void WavePresenter::showView()
{
    _waveView->show();
}

void WavePresenter::buildSignal(int frequency, int amplitude, int samples)
{
      sSignal = std::shared_ptr<SineSignal>(new SineSignal(frequency, amplitude, samples));

      auto vectorSignal = sSignal->getVector();

      std::complex<double> *X = vectorSignal.data();

      Processing p;
      p.fft2(X, vectorSignal.size());

      WaveModel model;
      model.fft = X;
      model.samplesFft = samples;

      model.signal = sSignal->getVector();
      _waveView->updateView(model);

}
