#ifndef SINESIGNAL_H
#define SINESIGNAL_H

#include <vector>
#include <complex>
#include <memory>

class SineSignalPrivate;

class SineSignal
{
public:
    explicit SineSignal(int frequency, double period, int samples);

    virtual ~SineSignal();

    std::vector<std::complex<double> > getVector();

    double getFreqResolution() const;

    void append(SineSignal &signal);

    int getSamples();

    void computeSignal();


private:
    std::shared_ptr<SineSignalPrivate> d_ptr;
};

#endif // SINESIGNAL_H
