/**
* The SnellsLawCalculator represents the presentation of the data
*/

#pragma once
#include "ui_SnellsLawCalculator.h"
#include <QtWidgets/QMainWindow>
#include <QDoubleValidator>
#include <QDebug>
#include <QButtonGroup>

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
    SnellsLawCalculator(QWidget *parent = Q_NULLPTR);
    ~SnellsLawCalculator();
    double incidenceIndex();
    double refractiveIndex();
    double angleOfIncidence();
    double angleOfRefraction();
    int calculateGroupIndex();

    void setIncidenceIndex(double incidentIndex);
    void setRefractiveIndex(double refractiveIndex);
    void setAngleOfIncidence(double angleOfIncidence);
    void setAngleOfRefraction(double angleOfRefraction);
    void setCalculateGroup(int index);
  
signals:
    void refractiveIndexChanged(double refractiveIndex);
    void incidenceIndexChanged(double incidentIndex);
    void angleOfIncidenceChanged(double angleOfIncidence);
    void angleOfRefractionChanged(double angleOfRefraction);
    void calculateGroupChanged(int index);

private:
    QButtonGroup* calculateGroup;
    Ui::SnellsLawCalculatorClass *ui;
};
