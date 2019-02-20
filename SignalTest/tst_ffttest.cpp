#include <QtTest>
#include "Signals/sinesignal.h"

class FftTest : public QObject
{
    Q_OBJECT

public:
    FftTest();
    ~FftTest();

private:
    ISignal  *testSineSignal;
    int countSamples;

private slots:
    void test_case1();

};

FftTest::FftTest(): countSamples(256)
{
    testSineSignal = new SineSignal(50, 1, countSamples);
}

FftTest::~FftTest()
{
    delete testSineSignal;
}

void FftTest::test_case1()
{
     int a =0;
     a++;
    QCOMPARE(1, 0);
}

#include "tst_ffttest.moc"
