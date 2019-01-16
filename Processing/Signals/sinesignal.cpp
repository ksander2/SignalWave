#include "sinesignal.h"

using namespace std;

SineSignal::SineSignal(int frequency, double period, int samples)
{
    _frequency = frequency;
    _period = period;
    _samples = samples;

    _data.resize(samples);
    calculate(_data, frequency, samples);
}

SineSignal::~SineSignal()
{
    _data.clear();
}

std::vector<std::complex<double> > SineSignal::getVector()
{
    return _data;
}

double SineSignal::getFreqResolution() const
{
    double sampleRate = _samples / _period;
    return sampleRate / _samples;
}

void SineSignal::calculate(std::vector<complex<double> > &data, int frequency, int samples)
{
    for(int i=0; i<samples; i++) {
        data[i] = sin( 2*M_PI*frequency*i/samples );
    }
}
