#include "rectangle.hpp"

#include <QIcon>
#include <QBitmap>
#include <QColorDialog>
#include <QPalette>
#include <QDebug>
#include <QMouseEvent>
#include <QTextStream>
#include <QToolTip>
#include <QPainter>
#include <QPen>

Rectangle::Rectangle(QWidget *parent, bool draw, bool select) : QWidget(parent), isDrawing(draw), isSelect(select)
{
	Qt::WindowFlags flags = Qt::Widget;
	flags |= Qt::CustomizeWindowHint;
	flags |= Qt::WindowMinimizeButtonHint;
	flags |= Qt::WindowStaysOnTopHint;
	flags |= Qt::WindowCloseButtonHint;
	this->setWindowFlags(flags);

	QIcon icon("brush.ico");
	this->setWindowIcon(icon);

	QPalette pal;
	QColorDialog colDia;
	QColor col = colDia.getColor();
	bool b = col.isValid();
	if(b)
	{
		pal.setColor(QPalette::Active, QPalette::Window, col);
	}
	else
	{
		pal.setColor(QPalette::Active, QPalette::Window, "YellowGreen");
	}
	pal.setColor(QPalette::Inactive, QPalette::Window, "#778899");
	this->setPalette(pal);

	this->setCursor(Qt::CrossCursor);
}

Rectangle::~Rectangle()
{
}

// QWidget interface
void Rectangle::mousePressEvent(QMouseEvent *event)
{
	if(event->buttons() == Qt::LeftButton)
	{
		qDebug() << "Left mouse is pressed";
	}
	if(event->buttons() == Qt::RightButton)
	{
		qDebug() << "Right mouse is pressed";
		isDrawing = true;
		startPoint = event->pos();
		this->setCursor(Qt::SizeAllCursor);

		QString str;
		QTextStream tstream(&str);
		tstream << "x=" << event->pos().rx() << " y=" << event->pos().ry() << ";";
		QToolTip::showText(event->globalPos(), str, this);
	}
}

void Rectangle::mouseReleaseEvent(QMouseEvent *event)
{
	if(event->buttons() == Qt::NoButton)
	{
		isDrawing = false;
		isSelect = false;
		this->setCursor(Qt::CrossCursor);
	}
	if(!isDrawing)
	{
		rectList.push_back(curRect);
	}
}

void Rectangle::mouseMoveEvent(QMouseEvent *event)
{
	if(isDrawing)
	{
		currentPoint = event->pos();
		this->repaint();

		QRect frame(this->rect()); // курсор в области виджета
		bool b = frame.contains(currentPoint);
		if(b)
		{
			this->setCursor(Qt::SizeAllCursor);
		}
		else
		{
			this->unsetCursor();
		}
	}

	QRect moveFrame(curRect); // курсор в области текущего прямоугольника
	bool isCursorInRect = moveFrame.contains(event->pos());
	if(isCursorInRect && event->buttons() == Qt::LeftButton)
	{
		isSelect = true;
		this->setCursor(Qt::ClosedHandCursor);
	}
	else if(!isCursorInRect && event->buttons() == Qt::LeftButton)
	{
		this->setCursor(Qt::ForbiddenCursor);
	}

	if(isSelect)
	{
		currentPoint = event->pos();
		this->repaint();
	}
}

void Rectangle::paintEvent(QPaintEvent *event)
{
	if(isDrawing)
	{
		QPainter paint(this);
		QPen pen("DarkGreen");
		curRect.setTopLeft(startPoint);
		curRect.setBottomRight(currentPoint);
		paint.setPen(pen);
		paint.drawRect(curRect);
	}

	if(isSelect)
	{
		QPainter paint(this);
		QRect tmp(curRect);
		QPen pen("DarkBlue");
		pen.setStyle(Qt::DashLine);
		tmp.setTopLeft(curRect.topLeft() + currentPoint);
		tmp.setBottomRight(curRect.bottomRight() + currentPoint);
		paint.setPen(pen);
		paint.drawRect(tmp);
	}

	for(int i = 0; i < rectList.size(); i++)
	{
		QRect rect = rectList[i];
		QPainter paint(this);
		paint.drawRect(rect);
	}
}