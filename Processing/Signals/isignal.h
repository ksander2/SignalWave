#ifndef ISIGNAL_H
#define ISIGNAL_H

class ISignal
{
public:
    virtual ~ISignal()
    {

    }

    virtual std::vector<std::complex<double> > getVector() = 0;
    virtual double getFreqResolution() const = 0;
    virtual void append(ISignal &signal) = 0;
    virtual int getSamples() = 0;
    virtual void computeSignal() = 0;

};

#endif // ISIGNAL_H
