#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QObject>
#include "presenter/mainpresenter.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    MainPresenter *pres = new MainPresenter;

    QQmlApplicationEngine engine;
    QQmlComponent         comp(&engine, QUrl(QStringLiteral("qrc:/main.qml")));
    QObject* pobj           = comp.create();
    QObject* pcmdQuitButton = pobj->findChild<QObject*>("InfoButton");
    if (pcmdQuitButton) {
            QObject::connect(pcmdQuitButton, SIGNAL(click1()),
                             pres, SLOT(do1())
                            );
        }

   // if (engine.rootObjects().isEmpty())
   //     return -1;

    return app.exec();
}
