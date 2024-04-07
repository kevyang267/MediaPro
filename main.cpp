#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "someclass.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    SomeClass testClass;

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MediaProV2", "Main");

    QQmlContext * rootCountext = engine.rootContext();
    rootCountext -> setContextProperty("classA", &testClass);

    return app.exec();
}
