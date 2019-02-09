#ifndef BASESIGNAL_P_H
#define BASESIGNAL_P_H

#include <vector>
#include <complex>

class BaseSignal_p
{
public:
    BaseSignal_p(int frequency, double period, int samples);

    double getFreqResolution() const;
    std::vector<std::complex<double> > getVector();

    void append(std::vector<std::complex<double> > data);

    int getSamples() const;

    void computeSignal();

protected:

    int _frequency;
    double _period;
    int _samples;
    double _freqResolution;
    std::vector<std::complex<double> > _data;

    virtual void calculate(std::vector<std::complex<double> > &data, int frequency, int samples) = 0;
};

#endif // BASESIGNAL_P_H
