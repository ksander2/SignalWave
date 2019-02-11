#include "sinesignal.h"
#include "sinesignal_p.h"

using namespace std;

SineSignal::SineSignal(int frequency, double period, int samples) : BaseSignal<SineSignalPrivate>(frequency, period, samples)
{

}

