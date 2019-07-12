#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "bson/forwarding/bson.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QByteArray data = QByteArray("\x1b\x00\x00\x00\x08\x63\x6f\x6d\x70\x61\x63\x74\x00\x01\x10\x73\x63\x68\x65\x6d\x61\x00\x00\x00\x00\x00\x00",27);

    bson_t *b;
    bson_iter_t iter;

    b = bson_new_from_data (reinterpret_cast<uint8_t*>(data.data()), data.size());

    return app.exec();
}
