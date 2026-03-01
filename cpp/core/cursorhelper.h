#ifndef CURSORHELPER_H
#define CURSORHELPER_H

#include <QObject>
#include <QString>

class CursorHelper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString cursor READ cursor WRITE setCursor NOTIFY cursorChanged FINAL);
public:
    explicit CursorHelper(QObject *parent = nullptr);

    QString cursor();

public slots:

    void setCursor(QString path);
    void resetCursor();

signals:
    void cursorChanged();

private:
    QString m_cursor = "";
};

#endif // CURSORHELPER_H
