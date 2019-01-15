#include "sinesignal.h"

using namespace std;

SineSignal::SineSignal(int frequency, double period, int samples)
{
    _frequency = frequency;
    _period = period;
    _samples = samples;
}

std::vector<std::complex<double> > SineSignal::getVector()
{
    vector<complex<double> > x(_samples);
    for(int i=0; i<_samples; i++) {
        x[i] = sin( 2*M_PI*_frequency*i/_samples );
    }

    return x;
}

double SineSignal::getFreqResolution() const
{
    double sampleRate = _samples / _period;
    return sampleRate / _samples;
}


