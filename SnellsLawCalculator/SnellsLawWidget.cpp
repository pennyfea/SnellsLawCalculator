#include "SnellsLawWidget.h"

SnellsLawWidget::SnellsLawWidget(QWidget* parent_)
	: QWidget(parent_), angleOfIncidence(0.0), angleOfRefraction(0.0), refractiveIndex(0.0), incidenceIndex(0.0)
{
	ui.setupUi(this);
	parent = parent_;
	width = parent->width();
	height = parent->height();
}

SnellsLawWidget::~SnellsLawWidget()
{
}


void SnellsLawWidget::paintEvent(QPaintEvent* event)
{

	QPainter painter(this);

	painter.drawText(QPoint(width - 100, height / 2 + 20), "Interface");
	painter.drawText(QPoint(width / 2 + 10, 20), "Normal");


	painter.drawText(QPoint(100, height / 2 - 20), "n1");
	painter.drawText(QPoint(100, height / 2 + 30), "n2");

	painter.setPen(QPen(Qt::black, Qt::SolidLine));
	painter.drawLine(0, height / 2, width, height / 2);

	painter.setPen(QPen(Qt::green, Qt::DashLine));
	painter.drawLine(width / 2, 0, width / 2, height);

	QLineF incidenceLine;
	painter.setPen(QPen(Qt::red, Qt::SolidLine));
	incidenceLine.setP1(QPoint(width / 2, height / 2));
	incidenceLine.setAngle(qreal(angleOfIncidence) + angleOffset);
	incidenceLine.setLength(indexLength);
	painter.drawLine(incidenceLine);
	painter.drawText(QPoint(incidenceLine.x2(), incidenceLine.y2()), theta + QString("1"));

	QLineF refractiveLine;
	refractiveLine.setP1(QPoint(width / 2, height / 2));
	refractiveLine.setAngle(qreal(angleOfRefraction) - angleOffset);
	refractiveLine.setLength(indexLength);
	painter.drawText(QPoint(refractiveLine.x2(), refractiveLine.y2()), theta + QString("2"));
	painter.drawLine(refractiveLine);	
}

QSize SnellsLawWidget::sizeHint() const
{
	return QSize(parent->width(), parent->height());
}

void SnellsLawWidget::setAngleOfRefraction(double angleOfRefraction_)
{
	this->angleOfRefraction = angleOfRefraction_;
	update();
}

void SnellsLawWidget::setAngleOfIncidence(double angleOfIncidence_)
{
	this->angleOfIncidence = angleOfIncidence_;
	update();
}

void SnellsLawWidget::setRefractiveIndex(double refractiveIndex_)
{
	this->refractiveIndex = refractiveIndex_;
	update();
}

void SnellsLawWidget::setIncidenceIndex(double incidenceIndex_)
{
	this->incidenceIndex = incidenceIndex_;
	update();
}
