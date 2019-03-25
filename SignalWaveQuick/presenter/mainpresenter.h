#ifndef MAINPRESENTER_H
#define MAINPRESENTER_H

#include <QObject>
#include <vector>
#include <QVector>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);

    Q_INVOKABLE int compute(int a, int b);
    Q_INVOKABLE QVector<qreal> computevec();
signals:

public slots:
    void do1();
};

#endif // MAINPRESENTER_H
