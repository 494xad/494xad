#include "FileStateObserver.h"
#include "FileState.h"
#include <QTextStream>

#include <thread>


int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    QTextStream in(stdin);
    QString path;

    out << "Enter file path: ";
    out.flush();
    in >> path;

    FileState state(path);

    FileStateObserver fileObserver;

    state.Attach(&fileObserver);

    out << "Tracking " << path << Qt::endl;

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        state.checkState();
    }

    return 0;
}
