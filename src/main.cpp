#include "video.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    video w;
    w.show();

    return app.exec();
}

