#include "basesignal.h"
#include "sinesignal_p.h"

template<typename T>
BaseSignal<T>::BaseSignal(int frequency, double period, int samples)
    : d_ptr(new T(frequency, period, samples))
{

}
template<typename T>
BaseSignal<T>::~BaseSignal()
{

}
template<typename T>
std::vector<std::complex<double> > BaseSignal<T>::getVector()
{
    return d_ptr->getVector();
}

template<typename T>
double BaseSignal<T>::getFreqResolution() const
{
    return d_ptr->getFreqResolution();
}

template<typename T>
void BaseSignal<T>::append(BaseSignal &signal)
{
    d_ptr->append(signal.getVector());
}

template<typename T>
int BaseSignal<T>::getSamples()
{
    return d_ptr->getSamples();
}

template<typename T>
void BaseSignal<T>::computeSignal()
{
    d_ptr->computeSignal();
}


