/**
* The SnellsLawCalculator represents the presentation of the data
*/

#pragma once
#include <QtWidgets/QMainWindow>
#include <QDoubleValidator>
#include <QDebug>
#include <QButtonGroup>
#include <memory>
#include "SnellsLawWidget.h"
#include "ui_SnellsLawCalculator.h"


namespace Ui {
    class SnellsLawCalculator;
}

class SnellsLawCalculator : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(double incidenceIndex READ incidenceIndex WRITE setIncidenceIndex NOTIFY incidenceIndexChanged)
    Q_PROPERTY(double refractiveIndex READ refractiveIndex WRITE setRefractiveIndex NOTIFY refractiveIndexChanged)
    Q_PROPERTY(double angleOfIncidence READ incidenceIndex WRITE setIncidenceIndex NOTIFY angleOfIncidenceChanged)
    Q_PROPERTY(double angleOfRefraction READ incidenceIndex WRITE setIncidenceIndex NOTIFY angleOfRefractionChanged)
    Q_PROPERTY(int calculateGroupIndex READ calculateGroupIndex WRITE setCalculateGroup NOTIFY calculateGroupChanged)

public:
    explicit SnellsLawCalculator(QWidget *parent = Q_NULLPTR);
    ~SnellsLawCalculator();
    double incidenceIndex();
    double refractiveIndex();
    double angleOfIncidence();
    double angleOfRefraction();
    int calculateGroupIndex();

    void setIncidenceIndex(double incidenceIdx);
    void setCalculateGroup(int index);
    void setRefractiveIndex(double refractiveIdx);
    void setAngleOfIncidence(double angleOfInci);
    void setAngleOfRefraction(double angleOfRefrac);
  
signals:
    void refractiveIndexChanged(double refractiveIndex);
    void incidenceIndexChanged(double incidentIndex);
    void angleOfIncidenceChanged(double angleOfIncidence);
    void angleOfRefractionChanged(double angleOfRefraction);
    void calculateGroupChanged(int index);

private:
    std::unique_ptr<QButtonGroup> calculateGroup;
    std::unique_ptr<SnellsLawWidget> snellsLawWidget;
    Ui::SnellsLawCalculatorClass *ui;
};
