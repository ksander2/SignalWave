#ifndef SQUARESIGNAL_H
#define SQUARESIGNAL_H

#include "sinesignal.h"

class SquareSignal : public SineSignal
{
public:
    SquareSignal(int frequency, double period, int samples);
};

#endif // SQUARESIGNAL_H
