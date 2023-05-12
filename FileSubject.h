#ifndef FILESUBJECT_H
#define FILESUBJECT_H
#include "IObserver.h"
#include <QList>
#include <QDateTime>

// Класс отслеживающий всех наблюдателей и обновляющий их при изменениях
class FileSubject
{
public:
    // Добавить наблюдателя в список
    void Attach(IObserver* observer);

    // Удалить наблюдателя из списка
    void Detach(IObserver* observer);

    // Метод оповещения наблюдателей в случае изменения состояния файла
    // lastModified - дата последнего изменения фвйла
    // isExist - индикатор существования файла
    // size - размер файла в байтах
    void Notify(const QDateTime& lastModified, bool isExist, qint64 size) const;
private:
    // Список наблюдателей отслеживающих состояние файла
    QList<IObserver*> observers;
};


#endif // FILESUBJECT_H
