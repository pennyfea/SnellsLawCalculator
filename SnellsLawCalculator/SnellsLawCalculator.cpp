#include "SnellsLawCalculator.h"


SnellsLawCalculator::SnellsLawCalculator(QWidget* parent)
	: QMainWindow(parent),
	ui(new Ui::SnellsLawCalculatorClass)
{
	ui->setupUi(this);

	this->setFixedSize(900, 700);

	snellsLawWidget = std::make_unique<SnellsLawWidget>(ui->verticalLayoutWidget);
	snellsLawWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	ui->widgetVerticalLayout->insertWidget(0, snellsLawWidget.get());
	ui->widgetVerticalLayout->setAlignment(snellsLawWidget.get(), Qt::AlignCenter);

	calculateGroup = std::make_unique<QButtonGroup>(this);
	calculateGroup->addButton(ui->incidenceIndexRadioButton, 0);
	calculateGroup->addButton(ui->refractiveIndexRadioButton, 1);
	calculateGroup->addButton(ui->angleOfIncidenceRadioButton, 2);
	calculateGroup->addButton(ui->angleOfRefractionRadioButton, 3);

	setWindowTitle("Snell's Law Calculator");
	ui->incidenceIndexDoubleSpinBox->setValue(0.0);
	ui->refractiveIndexDoubleSpinBox->setValue(0.0);
	ui->angleOfIncidenceDoubleSpinBox->setValue(0.0);
	ui->angleOfRefractionDoubleSpinBox->setValue(0.0);

	ui->angleOfIncidenceDoubleSpinBox->setRange(0.0, 90.0);
	ui->angleOfRefractionDoubleSpinBox->setRange(0.0, 90.0);


	ui->incidenceIndexDoubleSpinBox->setDecimals(3);
	ui->refractiveIndexDoubleSpinBox->setDecimals(3);
	ui->angleOfIncidenceDoubleSpinBox->setDecimals(3);
	ui->angleOfRefractionDoubleSpinBox->setDecimals(3);

	ui->incidenceIndexDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
	ui->refractiveIndexDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
	ui->angleOfIncidenceDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);
	ui->angleOfRefractionDoubleSpinBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

	connect(ui->incidenceIndexDoubleSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(
		&QDoubleSpinBox::valueChanged), [&](double) {
			emit incidenceIndexChanged(incidenceIndex());
		});

	connect(ui->refractiveIndexDoubleSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(
		&QDoubleSpinBox::valueChanged), [&](double) {
			emit refractiveIndexChanged(refractiveIndex());
		});

	connect(ui->angleOfIncidenceDoubleSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(
		&QDoubleSpinBox::valueChanged), [&](double) {
			emit angleOfIncidenceChanged(angleOfIncidence());
		});

	connect(ui->angleOfRefractionDoubleSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(
		&QDoubleSpinBox::valueChanged), [&](double) {
			emit angleOfRefractionChanged(angleOfRefraction());
		});

	connect(calculateGroup.get(), static_cast<void (QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked),
		[&](int id) {
			emit calculateGroupChanged(calculateGroupIndex());
		});
}

SnellsLawCalculator::~SnellsLawCalculator()
{
	delete ui;
}


double SnellsLawCalculator::incidenceIndex()
{
	return ui->incidenceIndexDoubleSpinBox->value();
}

double SnellsLawCalculator::refractiveIndex()
{
	return ui->refractiveIndexDoubleSpinBox->value();
}

double SnellsLawCalculator::angleOfIncidence()
{
	return ui->angleOfIncidenceDoubleSpinBox->value();
}

double SnellsLawCalculator::angleOfRefraction()
{
	return ui->angleOfRefractionDoubleSpinBox->value();
}

int SnellsLawCalculator::calculateGroupIndex()
{
	return calculateGroup->checkedId();
}


void SnellsLawCalculator::setIncidenceIndex(double incidenceIdx)
{
	ui->incidenceIndexDoubleSpinBox->setValue(incidenceIdx);
}

void SnellsLawCalculator::setAngleOfRefraction(double angleOfRefrac)
{
	snellsLawWidget->setAngleOfRefraction(angleOfRefrac);
	ui->angleOfRefractionDoubleSpinBox->setValue(angleOfRefrac);
}


void SnellsLawCalculator::setAngleOfIncidence(double angleOfInci)
{
	snellsLawWidget->setAngleOfIncidence(angleOfInci);
	ui->angleOfIncidenceDoubleSpinBox->setValue(angleOfInci);
}

void SnellsLawCalculator::setRefractiveIndex(double refractiveIdx)
{
	ui->refractiveIndexDoubleSpinBox->setValue(refractiveIdx);
}

void SnellsLawCalculator::setCalculateGroup(int index)
{
	switch (index)
	{
	case 0:
		ui->incidenceIndexDoubleSpinBox->setDisabled(true);
		ui->refractiveIndexDoubleSpinBox->setEnabled(true);
		ui->angleOfIncidenceDoubleSpinBox->setEnabled(true);
		ui->angleOfRefractionDoubleSpinBox->setEnabled(true);
		break;
	case 1:
		ui->incidenceIndexDoubleSpinBox->setEnabled(true);
		ui->refractiveIndexDoubleSpinBox->setDisabled(true);
		ui->angleOfIncidenceDoubleSpinBox->setEnabled(true);
		ui->angleOfRefractionDoubleSpinBox->setEnabled(true);
		break;
	case 2:
		ui->incidenceIndexDoubleSpinBox->setEnabled(true);
		ui->refractiveIndexDoubleSpinBox->setEnabled(true);
		ui->angleOfIncidenceDoubleSpinBox->setDisabled(true);
		ui->angleOfRefractionDoubleSpinBox->setEnabled(true);
		break;
	case 3:
		ui->incidenceIndexDoubleSpinBox->setEnabled(true);
		ui->refractiveIndexDoubleSpinBox->setEnabled(true);
		ui->angleOfIncidenceDoubleSpinBox->setEnabled(true);
		ui->angleOfRefractionDoubleSpinBox->setDisabled(true);
		break;
	default:
		break;
	}
}
