#include "trianglesingnal_p.h"

TriangleSingnalPrivate::TriangleSingnalPrivate(int frequency, double period, int samples) : BaseSignal_p(frequency, period, samples)
{

}

void TriangleSingnalPrivate::calculate(std::vector<std::complex<double> > &data, int frequency, int samples)
{
    for(int i=0; i<samples; i++) {
        data[i] = asin(cos(i*2*M_PI*frequency/samples))/1.5708;
    }
}
