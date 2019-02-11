#ifndef SINESIGNAL_H
#define SINESIGNAL_H

#include <vector>
#include <complex>
#include <memory>

#include "basesignal.h"

class SineSignalPrivate;

class SineSignal : public BaseSignal<SineSignalPrivate>
{
public:
    explicit SineSignal(int frequency, double period, int samples);


};

#endif // SINESIGNAL_H
