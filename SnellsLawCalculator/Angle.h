/**
* The Angle class is a helper class that allows for
* the construction of an Angle from either degrees or radians,
* and can be interpreted as either degrees or radians 
*/

#pragma once
#include <QtMath>
class Angle
{
public:
    static Angle fromRadians(double value)
    {
        return Angle(value);
    }

    static Angle fromDegrees(double value)
    {
        return Angle(value / 180.0 * M_PI);
    }

    double as_radians() const {
        return radians;
    }

    double as_degrees() const {
        return radians / M_PI * 180.0;
    }

private:
    Angle(double value) : radians(value) {}
    double radians;

};


