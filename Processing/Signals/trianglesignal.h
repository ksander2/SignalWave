#ifndef TRIANGLESIGNAL_H
#define TRIANGLESIGNAL_H

#include <vector>
#include <complex>
#include <memory>
#include "basesignal.h"

class TriangleSingnalPrivate;

class TriangleSignal  : public BaseSignal<TriangleSingnalPrivate>
{
public:
    explicit TriangleSignal(int frequency, double period, int samples);
};

#endif // TRIANGLESIGNAL_H
