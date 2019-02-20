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
   QCOMPARE(vectorSignal[0].real(), 0);
   QCOMPARE(vectorSignal[127].real(), -0.941544065183016);
   QCOMPARE(vectorSignal.size(), countSamples);
   //QVERIFY(condition)
}

QTEST_APPLESS_MAIN(correctSignalTest)

#include "tst_correctsignaltest.moc"
