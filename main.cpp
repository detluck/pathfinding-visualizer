#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cpp/cursorhelper.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    CursorHelper cursorHelper;
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cursorHelper", &cursorHelper);
    engine.loadFromModule("Pathfinding", "Main");
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


