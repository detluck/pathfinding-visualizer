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
    GridModel gridModel(100, 100);
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("cursorHelper", &cursorHelper);
    engine.rootContext()->setContextProperty("controller", &pathfinding);
    engine.rootContext()->setContextProperty("gridModel", &gridModel);
    engine.loadFromModule("Pathfinding", "Main");
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


