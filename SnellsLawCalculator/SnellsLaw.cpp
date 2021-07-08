#include "SnellsLaw.h"

SnellsLaw::SnellsLaw(QObject* parent)
	: QObject(parent)
{
}

SnellsLaw::~SnellsLaw()
{
}


/** Calculates and returns the angle of refraction
*/
double SnellsLaw::calculateAngleOfRefraction()
{
	return Angle::fromRadians(asin((incidenceIndex * sin(Angle::fromDegrees(angleOfIncidence).as_radians())) / refractiveIndex)).as_degrees();
}

/** Calculates and returns the angle of incidence
*/
double SnellsLaw::calculateAngleOfIncidence()
{
	return Angle::fromRadians(asin((refractiveIndex * sin(Angle::fromDegrees(angleOfRefraction).as_radians())) / incidenceIndex)).as_degrees();
}

/** Calculates and returns the refractiveIndex
*/
double SnellsLaw::calculateRefractiveIndex()
{
	return (incidenceIndex * sin(Angle::fromDegrees(angleOfIncidence).as_radians())) / sin(Angle::fromDegrees(angleOfRefraction).as_radians());
}

/** Calculates and returns the incidenceIndex
*/
double SnellsLaw::calculateIncidenceIndex()
{
	return (refractiveIndex * sin(Angle::fromDegrees(angleOfRefraction).as_radians())) / sin(Angle::fromDegrees(angleOfIncidence).as_radians());
}

double SnellsLaw::calculateCriticalAngle()
{
	return Angle::fromRadians(asin(refractiveIndex / incidenceIndex)).as_degrees();
}

void SnellsLaw::updateCalculation()
{
	switch (index) 
	{
		case 0:
			eAngleOfIncidenceUpdated(calculateIncidenceIndex());
		break;
		case 1:
			eRefractiveIndexUpdated(calculateRefractiveIndex());
		break;
		case 2:
			eAngleOfIncidenceUpdated(calculateAngleOfIncidence());
		break;
		case 3:
			eAngleOfRefractionUpdated(calculateAngleOfRefraction());
		break;
		default:
		break;
	}
}

void SnellsLaw::setAngleOfRefraction(double angleOfRefraction_)
{
	angleOfRefraction = angleOfRefraction_;
	updateCalculation();
}

void SnellsLaw::setAngleOfIncidence(double angleOfIncidence_)
{
	angleOfIncidence = angleOfIncidence_;
	updateCalculation();
}

void SnellsLaw::setIncidenceIndex(double incidencIndex_)
{
	incidenceIndex = incidencIndex_;
	updateCalculation();
}

void SnellsLaw::setRefractiveIndex(double refractiveIndex_)
{
	refractiveIndex = refractiveIndex_;
	updateCalculation();
}

void SnellsLaw::setCalculateIndex(int index_)
{
	index = index_;
}

