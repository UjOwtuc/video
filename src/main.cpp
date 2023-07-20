#include "video.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QStringList args = app.arguments();
	args.pop_front();

	Video vid;
	for (const QString& filename : args)
		vid.loadSource(filename);
	vid.showMaximized();

	return app.exec();
}
