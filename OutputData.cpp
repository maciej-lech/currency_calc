#include "OutputData.h"

void OutputData::setData(InputData* in, double course)
{
    for (std::vector<double>::iterator it = in->begin() ; it != in->end(); ++it)
        push(*it * course);
}
