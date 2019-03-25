#include <QtTest>
#include "Signals/sinesignal.h"
#include "processing.h"

class correctSignalTest : public QObject
{
    Q_OBJECT

public:
    correctSignalTest();
    ~correctSignalTest();

private:
    ISignal  *testSineSignal;
    int countSamples;

private slots:
    void test_signalvalue();
    void test_fft();

};

correctSignalTest::correctSignalTest(): countSamples(256)
{
    testSineSignal = new SineSignal(50, 1, countSamples);
}

correctSignalTest::~correctSignalTest()
{
    delete testSineSignal;
}

void correctSignalTest::test_signalvalue()
{
   testSineSignal->computeSignal();
   std::vector<std::complex<double>> vectorSignal = testSineSignal->getVector();
   //QCOMPARE(vectorSignal[0].real(), 0);
   QCOMPARE(vectorSignal[127].real(), -0.941544065183016);
  // QCOMPARE(vectorSignal.size(), countSamples);
   //QVERIFY(condition)
}

void correctSignalTest::test_fft()
{
    testSineSignal->computeSignal();
    auto vectorSignal = testSineSignal->getVector();
    std::complex<double> *fftArray = vectorSignal.data();

    Processing p;
    p.fft2(fftArray, vectorSignal.size());

    QCOMPARE((int)fftArray[50].imag(), -128);
}

QTEST_APPLESS_MAIN(correctSignalTest)

#include "tst_correctsignaltest.moc"
