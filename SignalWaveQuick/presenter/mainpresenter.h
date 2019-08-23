#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <vector>
#include <QVector>
#include "Signals/isignal.h"

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);

    Q_INVOKABLE int compute(int a, int b);
    Q_INVOKABLE QVector<qreal> computevec(int frequency, int amplitude, int samples, int type);
    Q_INVOKABLE QVector<qreal> computefft(const QVector<qreal> &array);

private:
    ISignal *buildSignalPtr(int frequency, int amplitude, int samples, int type);

};

#endif // MAINPRESENTER_H
