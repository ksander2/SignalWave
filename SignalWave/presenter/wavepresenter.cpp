#include "wavepresenter.h"
#include "processing.h"

#include "Signals/squaresignal.h"

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

    switch (_waveView->getIndexSignalType()) {
    case 0:
        sSignal = new SineSignal(frequency, amplitude, samples);
        break;
    case 1:
        sSignal = new SquareSignal(frequency, amplitude, samples);
        break;
    default:
        break;
    }
    sSignal->computeSignal();
    addSineSignalToView(sSignal);
}

void WavePresenter::addSineSignal(int frequency, int amplitude, int samples)
{

    SineSignal ss(frequency, amplitude, samples);
    ss.computeSignal();
    sSignal->append(ss);

    addSineSignalToView(sSignal);

}

void WavePresenter::addSineSignalToView(ISignal *signal)
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
