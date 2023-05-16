#include "FileState.h"

void FileState::setFile(const QString &path)
{
    file_.setFile(path);
}

void FileState::checkState()
{
    file_.refresh();
    bool exists = file_.exists();
    // Проверяем изменилось ли состояние существования файла
    if (exists != exists_)
    {
        exists_ = exists;
        Notify(true, exists_, 0);
    }
    // Проверяем изменилась ли дата модификации файла
    else if (exists && !file_.lastModified().isNull() && file_.lastModified() != lastModified_)
    {
        lastModified_ = file_.lastModified();
        Notify(true, true, file_.size());
    }
}
