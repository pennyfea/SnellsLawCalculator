#include "SnellsLawController.h"

SnellsLawController::SnellsLawController(SnellsLaw& snellsLaw_,  SnellsLawCalculator& snellsLawCalculator_, QObject* parent)
	: snellsLaw(snellsLaw_), snellsLawCalculator(snellsLawCalculator_), QObject(parent)
{
	connect(&snellsLawCalculator, SIGNAL(incidenceIndexChanged(double)), this, SLOT(setIncidenceIndex(double)));
	connect(&snellsLawCalculator, SIGNAL(refractiveIndexChanged(double)), this, SLOT(setRefractiveIndex(double)));
	connect(&snellsLawCalculator, SIGNAL(angleOfIncidenceChanged(double)), this, SLOT(setAngleOfIncidence(double)));
	connect(&snellsLawCalculator, SIGNAL(angleOfRefractionChanged(double)), this, SLOT(setAngleOfRefraction(double)));
	connect(&snellsLawCalculator, SIGNAL(calculateGroupChanged(int)), this, SLOT(setCalculatedGroupIndex(int)));

	connect(this, &SnellsLawController::eAngleOfRefraction, &snellsLaw, &SnellsLaw::setAngleOfRefraction);
	connect(this, &SnellsLawController::eAngleOfIncidende, &snellsLaw, &SnellsLaw::setAngleOfIncidence);
	connect(this, &SnellsLawController::eIncidenceIndex, &snellsLaw, &SnellsLaw::setIncidenceIndex);
	connect(this, &SnellsLawController::eRefractiveIndex, &snellsLaw, &SnellsLaw::setRefractiveIndex);
	connect(this, &SnellsLawController::eCalculateIndex, &snellsLaw, &SnellsLaw::setCalculateIndex);

	connect(this, &SnellsLawController::eCalculateIndex, &snellsLawCalculator, &SnellsLawCalculator::setCalculateGroup);

	connect(&snellsLaw, &SnellsLaw::eRefractiveIndexUpdated, this, &SnellsLawController::updateCalculation);
	connect(&snellsLaw, &SnellsLaw::eIncidenceIndexUpdated, this, &SnellsLawController::updateCalculation);
	connect(&snellsLaw, &SnellsLaw::eAngleOfIncidenceUpdated, this, &SnellsLawController::updateCalculation);
	connect(&snellsLaw, &SnellsLaw::eAngleOfRefractionUpdated, this, &SnellsLawController::updateCalculation);


}

void SnellsLawController::setAngleOfRefraction(double angleOfRefraction_)
{
	this->angleOfRefraction = angleOfRefraction_;
	emit eAngleOfRefraction(this->angleOfRefraction);

}

void SnellsLawController::setCalculatedGroupIndex(int index_)
{
	this->index = index_;
	emit eCalculateIndex(this->index);
}

void SnellsLawController::updateCalculation(double value)
{
	switch (index)
	{
	case 0:
		snellsLawCalculator.setIncidenceIndex(value);
		break;
	case 1:
		snellsLawCalculator.setRefractiveIndex(value);
		break;
	case 2:
		snellsLawCalculator.setAngleOfIncidence(value);
		break;
	case 3:
		snellsLawCalculator.setAngleOfRefraction(value);
		break;
	default:
		break;
	}
}

void SnellsLawController::setAngleOfIncidence(double angleOfIncidence_)
{
	this->angleOfIncidence = angleOfIncidence_;
	emit eAngleOfIncidende(this->angleOfIncidence);
}

void SnellsLawController::setIncidenceIndex(double incidenceIndex_)
{
	this->incidenceIndex = incidenceIndex_;
	emit eIncidenceIndex(this->incidenceIndex);
}

void SnellsLawController::setRefractiveIndex(double refractiveIndex_)
{
	this->refractiveIndex = refractiveIndex_;
	emit eRefractiveIndex(this->refractiveIndex);
}




