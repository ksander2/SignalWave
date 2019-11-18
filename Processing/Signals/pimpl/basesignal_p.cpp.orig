#include "basesignal_p.h"

BaseSignal_p::BaseSignal_p(int frequency, double period, int samples)
{
    _frequency = frequency;
    _period = period;
    _samples = samples;

    _data.resize(samples);
}

double BaseSignal_p::getFreqResolution() const
{
    double sampleRate = _samples / _period;
    return sampleRate / _samples;
}

std::vector<std::complex<double> > BaseSignal_p::getVector()
{
    return _data;
}

void BaseSignal_p::append(std::vector<std::complex<double> > data)
{
    if(_data.size() != data.size())
    {
        throw std::runtime_error("количество выборок не совпадает");
    }

    for (int i = 0; i < _data.size(); i++) {
        _data[i] += data[i];
    }
}

int BaseSignal_p::getSamples() const
{
    return _samples;
}

void BaseSignal_p::computeSignal()
{
     calculate(_data, _frequency, _samples);
}
