/**
 * The SnellsLawController handles the user interaction. 
 * The controller interprets the inputs from the user informing SnellsLaw Class
 * And the SnellsLawCalculator Class to change as appropriate.
 */
#pragma once
#include "SnellsLawCalculator.h"
#include "SnellsLaw.h"
#include <QObject>
#include <memory>


class SnellsLawController : public QObject
{
	Q_OBJECT

public:
	SnellsLawController(SnellsLaw& snellsLaw_, SnellsLawCalculator& snellsLawCalculator_, QObject* parent = Q_NULLPTR);

public slots:
	void setAngleOfIncidence(double angleOfIncidence_);
	void setIncidenceIndex(double incidenceIndex_);
	void setRefractiveIndex(double refractiveIndex_);
	void setAngleOfRefraction(double angleOfRefraction_);
	void setCalculatedGroupIndex(int index_);
	void updateCalculation(double value);

signals:
	void eAngleOfRefraction(double value);
	void eAngleOfIncidende(double value);
	void eIncidenceIndex(double value);
	void eRefractiveIndex(double value);
	void eCalculateIndex(int value);

private:
	double angleOfRefraction;
	double angleOfIncidence;
	double incidenceIndex;
	double refractiveIndex;
	int index;
	SnellsLaw& snellsLaw;
	SnellsLawCalculator& snellsLawCalculator;
	std::unique_ptr <SnellsLawController> snellsLawController;
};