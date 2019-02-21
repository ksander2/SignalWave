#include "wavepresenter.h"
#include "processing.h"

#include "Signals/squaresignal.h"
#include "Signals/sawsignal.h"
#include "Signals/trianglesignal.h"

#include <QMessageBox>

WavePresenter::WavePresenter()
    : _waveView(new WaveView),
      currentSignal(nullptr)
{
    connect(_waveView, &WaveView::buildSineSignal, this, &WavePresenter::onBuildSignalClicked);
    connect(_waveView, &WaveView::addSineSignal, this, &WavePresenter::onnAddSignalClicked);
}

WavePresenter::~WavePresenter()
{
    if(currentSignal != nullptr)
    {
        delete currentSignal;
    }
}

void WavePresenter::showView()
{
    _waveView->show();
}

void WavePresenter::onBuildSignalClicked(int frequency, int amplitude, int samples)
{
    if(currentSignal != nullptr)
    {
        delete currentSignal;
    }
    try {
        if(frequency > samples / 2)
        {
            throw std::runtime_error("Samples must be greater than 2x frequency");
        }
        currentSignal = buildSignalPtr(frequency, amplitude, samples);

        currentSignal->computeSignal();
        addSineSignalToView(currentSignal);
    }
    catch (std::runtime_error &error) {
        QMessageBox msg;
        msg.setText(error.what());
        msg.exec();
    }
}

void WavePresenter::onnAddSignalClicked(int frequency, int amplitude, int samples)
{
    try {

        if(currentSignal == nullptr)
        {
            throw std::runtime_error("Need build singal firstly");
        }
        if(samples != currentSignal->getSamples())
        {
            throw std::runtime_error("Count samples must be the same as in base signal");
        }
        if(frequency > samples / 2)
        {
            throw std::runtime_error("Samples must be greater than 2x frequency");
        }

        ISignal  *ss = buildSignalPtr(frequency, amplitude, samples);

        ss->computeSignal();
        currentSignal->append(*ss);

        addSineSignalToView(currentSignal);
        delete ss;
    }
    catch (std::runtime_error &error) {
        QMessageBox msg;
        msg.setText(error.what());
        msg.exec();
    }
}

void WavePresenter::addSineSignalToView(ISignal *signal)
{
    auto vectorSignal = signal->getVector();

    std::complex<double> *fftArray = vectorSignal.data();

    Processing p;
    p.fft2(fftArray, static_cast<int>(vectorSignal.size()));

    WaveModel model;
    model.fft = fftArray;
    model.samplesFft = signal->getSamples();
    model.signal = signal->getVector();

    _waveView->updateView(model);
}

ISignal *WavePresenter::buildSignalPtr(int frequency, int amplitude, int samples)
{
    ISignal  *builtSignal = nullptr;

    switch (_waveView->getIndexSignalType()) {
    case 0:
        builtSignal = new SineSignal(frequency, amplitude, samples);
        break;
    case 1:
        builtSignal = new SquareSignal(frequency, amplitude, samples);
        break;
    case 2:
        builtSignal = new SawSignal(frequency, amplitude, samples);
        break;
    case 3:
        builtSignal = new TriangleSignal(frequency, amplitude, samples);
        break;
    default:
        break;
    }

    return builtSignal;
}
