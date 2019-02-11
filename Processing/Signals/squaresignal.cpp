#include "squaresignal.h"

#include "squaresignal_p.h"

SquareSignal::SquareSignal(int frequency, double period, int samples) : BaseSignal<SquareSignalPrivate>(frequency, period, samples)
{

}
