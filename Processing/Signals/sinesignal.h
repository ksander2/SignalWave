#ifndef SINESIGNAL_H
#define SINESIGNAL_H

#include <vector>
#include <complex>

class SineSignal
{
public:
    explicit SineSignal(int frequency, double period, int samples);
   // SineSignal(SineSignal );

    virtual ~SineSignal();

    std::vector<std::complex<double> > getVector();

    double getFreqResolution() const;

private:
    int _frequency;
    double _period;
    int _samples;
    double _freqResolution;

    std::vector<std::complex<double> > _data;

    void calculate(std::vector<std::complex<double> > &data, int frequency, int samples);
};

#endif // SINESIGNAL_H
