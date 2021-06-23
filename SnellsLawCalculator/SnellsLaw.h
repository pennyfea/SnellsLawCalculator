
#pragma once
#include <math.h>
#include "Angle.h"
#include <QObject>
#include <QDebug>

class SnellsLaw : public QObject
{
	Q_OBJECT

public:
	SnellsLaw(QObject* parent = Q_NULLPTR);
	~SnellsLaw();
	double calculateAngleOfRefraction();
	double calculateAngleOfIncidence();
	double calculateRefractiveIndex();
	double calculateIncidenceIndex();
	double calculateCriticalAngle();
	void updateCalculation();


public slots:
	void setAngleOfRefraction(double angleOfRefraction_);
	void setAngleOfIncidence(double angleOfIncidence_);
	void setIncidenceIndex(double incidenceIndex_);
	void setRefractiveIndex(double refractiveIndex_);
	void setCalculateIndex(int index_);

signals:
	void eAngleOfRefractionUpdated(double value);
	void eAngleOfIncidenceUpdated(double value);
	void eRefractiveIndexUpdated(double value);
	void eIncidenceIndexUpdated(double value);

private:
	double incidenceIndex; // The refractive index of medium 1 (from which the ray travels);
	double refractiveIndex;  // The refractive index of medium 2 (into which the ray travels);
	double angleOfIncidence; // The angle of incidence - the angle between a line normal (perpendicular) to the boundary between two media and the incoming ray;
	double angleOfRefraction; // The angle of refraction - the angle between the normal to the boundary and the ray traveling through medium 2.
	int index;
};
