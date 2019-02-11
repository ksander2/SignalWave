#include "sawsignal.h"
#include "sawsignal_p.h"

SawSignal::SawSignal(int frequency, double period, int samples) : BaseSignal<SawSignalPrivate>(frequency, period, samples)
{

}
