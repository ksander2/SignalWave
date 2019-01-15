#ifndef SINESIGNAL_H
#define SINESIGNAL_H

#include <vector>
#include <complex>

class SineSignal
{
public:
    SineSignal(int frequency, double period, int samples);
    std::vector<std::complex<double> > getVector();

    double getFreqResolution() const;

private:
    int _frequency;
    double _period;
    int _samples;
    double _freqResolution;
};

#endif // SINESIGNAL_H
