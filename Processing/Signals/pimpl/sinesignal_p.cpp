#include "sinesignal_p.h"

SineSignalPrivate::SineSignalPrivate(int frequency, double period,
                                     int samples) : BaseSignal_p(frequency, period, samples)
{

}

void SineSignalPrivate::calculate(std::vector<std::complex<double> > &data, int frequency,
                                  int samples)
{
    for (int i = 0; i < samples; i++) {
        data[i] = sin( 2 * M_PI * frequency * i / samples );
    }
}
