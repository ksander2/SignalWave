#ifndef SINESIGNAL_P_H
#define SINESIGNAL_P_H

#include <vector>
#include <complex>

class SineSignalPrivate
{
public:
    SineSignalPrivate(int frequency, double period, int samples);

    double getFreqResolution() const;
    std::vector<std::complex<double> > getVector();

private:

    int _frequency;
    double _period;
    int _samples;
    double _freqResolution;

    void calculate(std::vector<std::complex<double> > &data, int frequency, int samples);
    std::vector<std::complex<double> > _data;

};

#endif // SINESIGNAL_P_H
