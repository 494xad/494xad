#include "FileSubject.h"

void FileSubject::Attach(IObserver* observer)
{
    if (observer)
    {
        observers.push_back(observer);
    }
}

void FileSubject::Detach(IObserver* observer)
{
    if (observer)
    {
        observers.removeOne(observer);
    }
}

void FileSubject::Notify(const QDateTime& lastModified, bool isExist, qint64 size) const
{
    for (auto& observer : observers)
    {
        observer->Update(lastModified, isExist, size);
    }
}
