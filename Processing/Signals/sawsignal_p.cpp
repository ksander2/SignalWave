#include "sawsignal_p.h"
#include <math.h>
SawSignalPrivate::SawSignalPrivate(int frequency, double period, int samples) : BaseSignal_p(frequency, period, samples)
{

}

void SawSignalPrivate::calculate(std::vector<std::complex<double> > &data, int frequency, int samples)
{
    for(int i=0; i<samples; i++) {
        double value =   abs((i % frequency) - 1);
        data[i] =value;
    }
}
