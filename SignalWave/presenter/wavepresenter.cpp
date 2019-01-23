#include "wavepresenter.h"
#include "processing.h"

WavePresenter::WavePresenter()
    : _waveView(new WaveView),
      sSignal(nullptr)
{
    connect(_waveView, &WaveView::buildSineSignal, this, &WavePresenter::buildSignal);
    connect(_waveView, &WaveView::addSineSignal, this, &WavePresenter::addSineSignal);
}

WavePresenter::~WavePresenter()
{
    if(sSignal != nullptr)
    {
        delete sSignal;
    }
}

void WavePresenter::showView()
{
    _waveView->show();
}

void WavePresenter::buildSignal(int frequency, int amplitude, int samples)
{
    if(sSignal != nullptr)
    {
        delete sSignal;
    }

    sSignal = new SineSignal(frequency, amplitude, samples);
    addSineSignalToView(sSignal);
}

void WavePresenter::addSineSignal(int frequency, int amplitude, int samples)
{
    SineSignal ss(frequency, amplitude, samples);
    sSignal->append(ss);

    addSineSignalToView(sSignal);
}

void WavePresenter::addSineSignalToView(SineSignal *signal)
{
    auto vectorSignal = signal->getVector();

    std::complex<double> *fftArray = vectorSignal.data();

    Processing p;
    p.fft2(fftArray, vectorSignal.size());

    WaveModel model;
    model.fft = fftArray;
    model.samplesFft = signal->getSamples();
    model.signal = signal->getVector();

    _waveView->updateView(model);
}
