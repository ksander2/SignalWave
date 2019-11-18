#include "squaresignal_p.h"

SquareSignalPrivate::SquareSignalPrivate(int frequency, double period,
                                         int samples) : BaseSignal_p(frequency, period, samples)
{

}

void SquareSignalPrivate::calculate(std::vector<std::complex<double> > &data, int frequency,
                                    int samples)
{
    for (int i = 0; i < samples; i++) {
        double value = sin( 2 * M_PI * frequency * i / samples );
        if (value > 0) {
            data[i] = 1;
        } else {
            data[i] = 0;
        }
    }
}

