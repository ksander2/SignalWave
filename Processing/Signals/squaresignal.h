#ifndef SQUARESIGNAL_H
#define SQUARESIGNAL_H

#include "basesignal.h"

class SquareSignalPrivate;

class SquareSignal : public BaseSignal<SquareSignalPrivate>
{
public:
    explicit SquareSignal(int frequency, double period, int samples);
};

#endif // SQUARESIGNAL_H
