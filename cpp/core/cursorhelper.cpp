#include "cursorhelper.h"
#include <QGuiApplication>
#include <QIcon>
#include <QCursor>


CursorHelper::CursorHelper(QObject *parent)
    : QObject{parent}
{}

void CursorHelper::setCursor(QString path){
    QIcon icon(path);
    QPixmap pix = icon.pixmap(30,30);
    if(!pix.isNull()){
        QGuiApplication::setOverrideCursor(QCursor(pix, 16, 16));
    }
}

void CursorHelper::resetCursor(){
    QGuiApplication::restoreOverrideCursor();
}
