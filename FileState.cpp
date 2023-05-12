#include "FileState.h"

void FileState::setFile(const QString &path)
{
    file_.setFile(path);
}

void FileState::checkState()
{
    file_.refresh();
    Notify(file_.lastModified(), file_.exists(), file_.size());
}
