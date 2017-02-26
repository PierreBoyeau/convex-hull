#include "window.h"
#include <QApplication>

int main(int argv, char **args)
{	
	QApplication app(argv, args);
	app.setApplicationName("2D convex hull");
	MainWindow window;
	window.show();
	return app.exec();
}
