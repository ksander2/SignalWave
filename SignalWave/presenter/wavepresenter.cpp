#include "wavepresenter.h"
#include "processing.h"

#include "Signals/squaresignal.h"
#include "Signals/sawsignal.h"
#include "Signals/trianglesignal.h"

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
    case 2:
        sSignal = new SawSignal(frequency, amplitude, samples);
        break;
    case 3:
        sSignal = new TriangleSignal(frequency, amplitude, samples);
        break;
    default:
        break;
    }
    sSignal->computeSignal();
    addSineSignalToView(sSignal);
}

void WavePresenter::addSineSignal(int frequency, int amplitude, int samples)
{
    ISignal  *ss;

    switch (_waveView->getIndexSignalType()) {
    case 0:
        ss = new SineSignal(frequency, amplitude, samples);
        break;
    case 1:
        ss = new SquareSignal(frequency, amplitude, samples);
        break;
    case 2:
        ss = new SawSignal(frequency, amplitude, samples);
        break;
    case 3:
        ss = new TriangleSignal(frequency, amplitude, samples);
        break;
    default:
        break;
    }

    ss->computeSignal();
    sSignal->append(*ss);

    addSineSignalToView(sSignal);
    delete ss;

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
