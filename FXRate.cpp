#include "FXRate.h"

FXRate::FXRate()
{
    course = 1.0;
}


double FXRate::getCoursValue() const
{
    return course;
}

void FXRate::setCourseValue(double val)
{
    course = val;
}
