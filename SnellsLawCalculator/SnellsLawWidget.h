#pragma once

#include <QWidget>
#include <QPainter>
#include "ui_SnellsLawWidget.h"
#include <QLabel>

class SnellsLawWidget : public QWidget
{
	Q_OBJECT

public:
	SnellsLawWidget(QWidget *parent_ = Q_NULLPTR);
	~SnellsLawWidget();
	void setAngleOfRefraction(double angleOfRefraction_);
	void setAngleOfIncidence(double angleOfIncidence_);
	void setRefractiveIndex(double refractiveIndex_);
	void setIncidenceIndex(double incidenceIndex_);

protected:
	void paintEvent(QPaintEvent* event) override;
	virtual QSize sizeHint() const override;

private:
	int width;
	int height;
	const int indexLength = 75;
	const qreal angleOffset = 90.0;
	const QString theta = QChar(0x98, 0x03);
	Ui::SnellsLawWidget ui;
	double angleOfRefraction;
	double angleOfIncidence;
	double refractiveIndex;
	double incidenceIndex;
	QWidget* parent;

};
