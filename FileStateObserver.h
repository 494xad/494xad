#ifndef FILESTATEOBSERVER_H
#define FILESTATEOBSERVER_H
#include "IObserver.h"

// Класс реализующий интерфейс наблюдателя
class FileStateObserver : public IObserver
{
public:
    // Метод, выполняющий проверку состояния файла в ответ на оповещение
    void Update(const QDateTime& lastModified, bool isExist, qint64 size);
    virtual ~FileStateObserver() {}
private:
    // Дата последнего изменения файла, нужна для отслеживания того, был ли файл изменен
    QDateTime lastModified_;
};


#endif // FILESTATEOBSERVER_H
