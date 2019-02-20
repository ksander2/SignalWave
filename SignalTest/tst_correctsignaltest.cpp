#include <QtTest>
#include "Signals/sinesignal.h"

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
    void test_case1();

};

correctSignalTest::correctSignalTest(): countSamples(256)
{
    testSineSignal = new SineSignal(50, 1, countSamples);
}

correctSignalTest::~correctSignalTest()
{
    delete testSineSignal;
}

void correctSignalTest::test_case1()
{
   testSineSignal->computeSignal();
   std::vector<std::complex<double>> vectorSignal = testSineSignal->getVector();
   std::complex<double> complexValue = vectorSignal[0];
   QCOMPARE(complexValue.real(), 0);
   QCOMPARE(vectorSignal.size(), countSamples);
   //QVERIFY(condition)
}

QTEST_APPLESS_MAIN(correctSignalTest)

#include "tst_correctsignaltest.moc"
