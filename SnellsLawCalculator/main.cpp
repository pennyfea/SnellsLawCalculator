/**
 * Snell's Law Calculator
 * When light travels from one medium to another, it bends or refracts.
 * This Snell's law calculator lets you calculate the angle of refraction. 
 * 
 * @Author: Austin Pennyfeather
 * @Date: 2021-06-11
 */
#include "SnellsLawCalculator.h"
#include "SnellsLawController.h"
#include "SnellsLaw.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SnellsLaw snellsLaw;
    SnellsLawCalculator snellsLawCalculator;
    SnellsLawController snellsLawController(snellsLaw, snellsLawCalculator);
    snellsLawCalculator.show();
    return a.exec();
}
