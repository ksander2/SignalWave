#ifndef SAWSIGNAL_H
#define SAWSIGNAL_H

#include <vector>
#include <complex>
#include <memory>
#include "basesignal.h"

class SawSignalPrivate;

class SawSignal : public BaseSignal<SawSignalPrivate>
{
public:
    explicit SawSignal(int frequency, double period, int samples);
};

#endif // SAWSIGNAL_H
