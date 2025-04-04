#include "qt_app/rectangle.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Rectangle w;
	w.show();
	return a.exec();
}