#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <Controllers/system.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    System m_systemHandler;

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    QQmlContext * context (engine.rootContext());
    context -> setContextProperty("appHandler", &m_systemHandler);
    engine.loadFromModule("MediaProV2", "Main");

    return app.exec();
}
