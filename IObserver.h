#ifndef IOBSERVER_H
#define IOBSERVER_H
#include <QtGlobal>
#include <QDateTime>

// Интерфейс наблюдателя определяющий метод, который вызывается при изменении состояния файла
class IObserver
{
public:
    virtual void Update(const QDateTime& lastModified, bool isExist, qint64 size) = 0;
    virtual ~IObserver(){};
};

#endif // IOBSERVER_H
