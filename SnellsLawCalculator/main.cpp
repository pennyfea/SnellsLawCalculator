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

    // Takes care of input arguments, but also a lot of other things, and most notably, the event loop. 
    // The event loop is a loop that waits for user input in GUI applications.
    QApplication a(argc, argv);
    
    // Model
    SnellsLaw snellsLaw;
    // View
    SnellsLawCalculator snellsLawCalculator;
    // Controller
    SnellsLawController snellsLawController(snellsLaw, snellsLawCalculator);

    snellsLawCalculator.show();

    // Event loop is launched
    return a.exec();
}
