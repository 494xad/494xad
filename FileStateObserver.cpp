#include "FileStateObserver.h"
#include <QTextStream>

void FileStateObserver::Update(bool isChanged, bool isExist, qint64 size)
{
    QTextStream out(stdout);
    // Если файл существует
    if (isExist)
    {
        out << "File exists. ";
        // Если предудущая сохраненная дата не равна текущей дате, то файл был изменен
        if (isChanged)
        {
            out << "File has been changed. ";
        }
        // Вывод размера файла
        out << "Size = " << size << " bytes." << Qt::endl;
    }
    else
    {
        out << "File doesn't exists." << Qt::endl;
    }
}
