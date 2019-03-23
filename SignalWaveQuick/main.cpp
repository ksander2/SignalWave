#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlComponent         comp(&engine);

    QObject* pobj           = comp.create();

    QObject* pcmdQuitButton = pobj->findChild<QObject*>("QuitButton");
    if (pcmdQuitButton) {
           // QObject::connect(pcmdQuitButton, SIGNAL(quitClicked()),
                //             &cc, SLOT(slotQuit())
                //            );
        }

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
