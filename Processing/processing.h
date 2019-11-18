#ifndef PROCESSING_H
#define PROCESSING_H

#include <complex>

class  Processing
{

public:
    Processing();
    void meandr(std::complex<double> *v, int n);
    void fft2 (std::complex<double> *X, int N);
    void separate(std::complex<double> *a, int n);

};

#endif // PROCESSING_H
