#include "sinesignal_p.h"

SineSignalPrivate::SineSignalPrivate(int frequency, double period, int samples)
{
    _frequency = frequency;
    _period = period;
    _samples = samples;

    _data.resize(samples);
    calculate(_data, frequency, samples);
}

double SineSignalPrivate::getFreqResolution() const
{
    double sampleRate = _samples / _period;
    return sampleRate / _samples;
}

std::vector<std::complex<double> > SineSignalPrivate::getVector()
{
     return _data;
}

void SineSignalPrivate::calculate(std::vector<std::complex<double> > &data, int frequency, int samples)
{
    for(int i=0; i<samples; i++) {
        data[i] = sin( 2*M_PI*frequency*i/samples );
    }
}