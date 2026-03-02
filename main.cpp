#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cpp/core/cursorhelper.h"
#include "cpp/core/pathfinding.h"
#include "cpp/model/gridmodel.h"

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    CursorHelper cursorHelper;
    Pathfinding pathfinding;
    QQmlApplicationEngine engine;

    qmlRegisterUncreatableType<Pathfinding>(
        "App.Controller", 1, 0,
        "Controller",
        "Enums only"
        );
    engine.rootContext()->setContextProperty("controller", &pathfinding);
    engine.rootContext()->setContextProperty("cursorHelper", &cursorHelper);
    engine.rootContext()->setContextProperty("gridModel", pathfinding.gridModel());
    engine.loadFromModule("Pathfinding", "Main");
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


