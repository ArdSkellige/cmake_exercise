#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QWidget>

class Rectangle : public QWidget
{
	Q_OBJECT

	QList<QRect> rectList; // список для хранения нарисованных прямоугольников
	QPoint startPoint; // вторая координата Recta - topLeft
	QPoint currentPoint; // первая координата Recta - bottomRight
	QRect curRect; // текущий нарисованный прямоугольник
	bool isDrawing; // признак, рисуется ли прямоугольник
	bool isSelect; // признак, хотим ли мы выделить прямоугольник

public:
	Rectangle(QWidget *parent = nullptr, bool draw = false, bool select = false);
	~Rectangle();

	// QWidget interface
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);
};
#endif // RECTANGLE_H
