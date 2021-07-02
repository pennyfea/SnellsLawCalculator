#include "SnellsLawWidget.h"

SnellsLawWidget::SnellsLawWidget(QWidget* parent_)
	: QWidget(parent_), angleOfIncidence(0.0), angleOfRefraction(0.0), refractiveIndex(0.0), incidenceIndex(0.0)
{
	ui.setupUi(this);
	parent = parent_;
}

SnellsLawWidget::~SnellsLawWidget()
{
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

void SnellsLawWidget::paintEvent(QPaintEvent* event)
{
	int width = parent->width();
	int height = parent->height();

	QPainter painter(this);

	painter.setPen(QPen(Qt::black, Qt::SolidLine));
	painter.drawLine(0, height / 2, width, height / 2);


	painter.setPen(QPen(Qt::green, Qt::DashLine));
	painter.drawLine(width / 2, 0, width / 2, height);

	QLineF incidenceLine;
	painter.setPen(QPen(Qt::red, Qt::SolidLine));
	incidenceLine.setP1(QPoint(width / 2, height / 2));
	incidenceLine.setAngle(qreal(angleOfIncidence) + qreal(90.0));
	incidenceLine.setLength(100);
	painter.drawLine(incidenceLine);

	QLineF refractiveLine;
	refractiveLine.setP1(QPoint(width / 2, height / 2));
	refractiveLine.setAngle(qreal(angleOfRefraction) - qreal(90.0));
	refractiveLine.setLength(100);
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
