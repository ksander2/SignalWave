#ifndef BASESIGNAL_H
#define BASESIGNAL_H

#include <vector>
#include <complex>
#include <memory>

template <typename T>
class BaseSignal
{
public:
    explicit BaseSignal(int frequency, double period, int samples);
    ~BaseSignal();

    std::vector<std::complex<double> > getVector();

    double getFreqResolution() const;

    void append(BaseSignal &signal);

    int getSamples();

    void computeSignal();

private:
    std::shared_ptr<T> d_ptr;
};

#endif // BASESIGNAL_H
