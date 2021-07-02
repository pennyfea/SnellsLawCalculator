#pragma once

#include <QWidget>
#include <QPainter>
#include "ui_SnellsLawWidget.h"

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
	QSize sizeHint() const override;

private:
	Ui::SnellsLawWidget ui;
	double angleOfRefraction;
	double angleOfIncidence;
	double refractiveIndex;
	double incidenceIndex;
	QWidget* parent;
};
