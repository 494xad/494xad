#ifndef FILESTATE_H
#define FILESTATE_H
#include "FileSubject.h"
#include <QFileInfo>

// Реальный класс, который реагирует на изменения состояния файла
class FileState : public FileSubject
{
public:
    // Конструктор для файла, который нужно отслеживать
    // path - путь к файлу
    FileState(const QString& path) : file_(path) {}

    // Изменить отслеживаемый файл
    void setFile(const QString& path);

    // Проверка состояния файла, отправляет текущее состояние файла наблюдателям
    void checkState();
private:
    // Путь к файлу
    QFileInfo file_;
};

#endif // FILESTATE_H
