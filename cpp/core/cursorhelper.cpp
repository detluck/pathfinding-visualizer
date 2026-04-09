#include "cursorhelper.h"
#include <QGuiApplication>
#include <QIcon>
#include <QCursor>


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
    QIcon icon(m_cursor);
    QPixmap pix = icon.pixmap(30,30);
    if(!pix.isNull()){
        QGuiApplication::setOverrideCursor(QCursor(pix, 16, 16));
    }
}

void CursorHelper::resetCursor(){
    m_cursor = "";
    while(QGuiApplication::overrideCursor()){
        QGuiApplication::restoreOverrideCursor();
    }
}
