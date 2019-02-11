#include "trianglesignal.h"
#include "trianglesingnal_p.h"

TriangleSignal::TriangleSignal(int frequency, double period, int samples) : BaseSignal<TriangleSingnalPrivate>(frequency, period, samples)
{

}
