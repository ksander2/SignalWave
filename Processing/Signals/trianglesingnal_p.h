#ifndef TRIANGLESINGNAL_P_H
#define TRIANGLESINGNAL_P_H

#include <vector>
#include <complex>
#include "basesignal_p.h"


class TriangleSingnalPrivate : public BaseSignal_p
{
public:
    TriangleSingnalPrivate(int frequency, double period, int samples);

private:
    void calculate(std::vector<std::complex<double> > &data, int frequency, int samples) override;
};

#endif // TRIANGLESINGNAL_P_H
