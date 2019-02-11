#ifndef SQUARESIGNAL_P_H
#define SQUARESIGNAL_P_H

#include <vector>
#include <complex>
#include "basesignal_p.h"

class SquareSignalPrivate : public BaseSignal_p
{
public:
    SquareSignalPrivate(int frequency, double period, int samples);

private:
    void calculate(std::vector<std::complex<double> > &data, int frequency, int samples) override;
};

#endif // SQUARESIGNAL_P_H
