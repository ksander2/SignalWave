#ifndef BASESIGNAL_H
#define BASESIGNAL_H

#include <vector>
#include <complex>
#include <memory>

#include "isignal.h"

template <typename T>
class BaseSignal : public ISignal
{
public:
    explicit BaseSignal(int frequency, double period, int samples)
        : d_ptr(new T(frequency, period, samples))
    {

    }

    virtual ~BaseSignal()
    {

    }

    std::vector<std::complex<double> > getVector() override
    {
        return d_ptr->getVector();
    }

    double getFreqResolution() const override
    {
        return d_ptr->getFreqResolution();
    }

    void append(ISignal &signal) override
    {
        d_ptr->append(signal.getVector());
    }

    int getSamples() override
    {
        return d_ptr->getSamples();
    }

    void computeSignal() override
    {
        d_ptr->computeSignal();
    }

protected:
    std::shared_ptr<T> d_ptr;
};

#endif // BASESIGNAL_H
