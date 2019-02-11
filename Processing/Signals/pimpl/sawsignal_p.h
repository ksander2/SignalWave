#ifndef SAWSIGNAL_P_H
#define SAWSIGNAL_P_H

#include <vector>
#include <complex>
#include "basesignal_p.h"

class SawSignalPrivate : public BaseSignal_p
{
public:
    explicit SawSignalPrivate(int frequency, double period, int samples);
private:
      virtual void calculate(std::vector<std::complex<double> > &data, int frequency, int samples) override;
};

#endif // SAWSIGNAL_P_H
