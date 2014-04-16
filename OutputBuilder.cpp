#include "OutputBuilder.h"

OutputData* OutputBuilder::output = 0;

OutputBuilder::OutputBuilder()
{
    if (!output)
    {
        output = new OutputData;
    }
}

int OutputBuilder::buildOutput(InputData* in, double course)
{
    output->setData(in, course);

    return 0;
}
