#include <QtTest>
#include "Signals/sinesignal.h"

class correctSignalTest : public QObject
{
    Q_OBJECT

public:
    correctSignalTest();
    ~correctSignalTest();

private slots:
    void test_case1();

};

correctSignalTest::correctSignalTest()
{

}

correctSignalTest::~correctSignalTest()
{

}

void correctSignalTest::test_case1()
{
   ISignal  *pp = new SineSignal(50, 1, 256);
   pp->computeSignal();
   // testSineSignal.computeSignal();
   // auto vectorSignal = testSineSignal.getVector();
   // std::complex<double> *complexArray = vectorSignal.data();
    //QCOMPARE(complexArray[0].real(), 1);
    //QVERIFY(condition)
}

QTEST_APPLESS_MAIN(correctSignalTest)

#include "tst_correctsignaltest.moc"
