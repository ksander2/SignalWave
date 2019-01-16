#include "sinesignal.h"
#include "sinesignal_p.h"

using namespace std;

SineSignal::SineSignal(int frequency, double period, int samples)
    : d_ptr(new SineSignalPrivate(frequency, period, samples))
{

}

SineSignal::~SineSignal()
{

}

std::vector<std::complex<double> > SineSignal::getVector()
{
    return d_ptr->getVector();
}

double SineSignal::getFreqResolution() const
{
    return d_ptr->getFreqResolution();
}

