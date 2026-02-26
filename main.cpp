#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cpp/cursorhelper.h"
#include "cpp/pathfinding.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    CursorHelper cursorHelper;
    Pathfinding pathfinding;
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cursorHelper", &cursorHelper);
    engine.rootContext()->setContextProperty("controller", &pathfinding);
    engine.loadFromModule("Pathfinding", "Main");
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


