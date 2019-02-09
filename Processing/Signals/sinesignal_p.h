#ifndef SINESIGNAL_P_H
#define SINESIGNAL_P_H

#include <vector>
#include <complex>
#include "basesignal_p.h"

class SineSignalPrivate : public BaseSignal_p
{
public:
    SineSignalPrivate(int frequency, double period, int samples);
private:
      virtual void calculate(std::vector<std::complex<double> > &data, int frequency, int samples) override;
};

#endif // SINESIGNAL_P_H
