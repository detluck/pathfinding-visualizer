#include "cursorhelper.h"
#include <QGuiApplication>
#include <QIcon>
#include <QCursor>
#include <QDebug>


CursorHelper::CursorHelper(QObject *parent)
    : QObject{parent}
{}

QString CursorHelper::cursor() const
{
    return m_cursor;
}

void CursorHelper::setCursor(QString path){

    if(m_cursor == path){
        return;
    }
    if(path.isEmpty()){
        return;
    }
    m_cursor = path;

    // --- ANFANG DES FIXES ---
    // --- ANFANG DES FIXES ---
    QString cleanPath = path;

    // 1. Falls "qrc:/" davor steht, schneiden wir es einfach weg
    cleanPath.replace("qrc:/", "");

    // 2. Wir prüfen, ob QML den Modulnamen "Pathfinding/" schon mitgeschickt hat
    if (cleanPath.startsWith("Pathfinding/")) {
        cleanPath = ":/qt/qml/" + cleanPath;
    } else if (!cleanPath.startsWith(":/qt/qml/")) {
        // Nur wenn es wirklich ein nackter Pfad wie "ui/assets/..." ist
        cleanPath = ":/qt/qml/Pathfinding/" + cleanPath;
    }
    // --- ENDE DES FIXES ---

    QIcon icon(cleanPath);
    QPixmap pix = icon.pixmap(30, 30);

    if(!pix.isNull()){
        QGuiApplication::setOverrideCursor(QCursor(pix, 16, 16));
    } else {
        // Falls es immer noch nicht geht, zeigt dir dieses qDebug im Qt Creator genau an,
        // welchen falschen Pfad C++ zu laden versucht!
        qDebug() << "FEHLER: Konnte Cursor SVG nicht laden. Versuchter Pfad:" << cleanPath;
    }
}

void CursorHelper::resetCursor(){
    m_cursor = "";
    while(QGuiApplication::overrideCursor()){
        QGuiApplication::restoreOverrideCursor();
    }
}
