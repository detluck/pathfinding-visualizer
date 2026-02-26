#ifndef CURSORHELPER_H
#define CURSORHELPER_H

#include <QObject>
#include <QString>

class CursorHelper : public QObject
{
    Q_OBJECT
public:
    explicit CursorHelper(QObject *parent = nullptr);
    Q_INVOKABLE void setCursor(QString path);
    Q_INVOKABLE void resetCursor();
};

#endif // CURSORHELPER_H
