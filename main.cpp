#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "cpp/core/cursorhelper.h"
#include "cpp/core/pathfinding.h"
#include <QQuickStyle>
#include <QFontDatabase>

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQuickStyle::setStyle("Basic");
    CursorHelper cursorHelper;
    Pathfinding pathfinding;
    QQmlApplicationEngine engine;

    int regularId = QFontDatabase::addApplicationFont(":/qt/qml/Pathfinding/ui/assets/fonts/JetBrainsMono-Regular.ttf");
    QFontDatabase::addApplicationFont(":/qt/qml/Pathfinding/ui/assets/fonts/JetBrainsMono-Bold.ttf");
    if (regularId != -1) {
        QString fontFamily = QFontDatabase::applicationFontFamilies(regularId).at(0);
        QFont globalFont(fontFamily, 11);
        app.setFont(globalFont);
    }
    qmlRegisterUncreatableType<Pathfinding>(
        "App.Controller", 1, 0,
        "Controller",
        "Enums only"
        );
    engine.rootContext()->setContextProperty("controller", &pathfinding);
    engine.rootContext()->setContextProperty("cursorHelper", &cursorHelper);
    engine.rootContext()->setContextProperty("gridModel", pathfinding.gridModel());
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &app, []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
    engine.loadFromModule("Pathfinding", "Main");
    if(engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}


