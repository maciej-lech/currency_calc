#include "Converter.h"


InputData* Converter::input = 0;
OutputBuilder* Converter::output = 0;
FXRate* Converter::ex_rate = 0;

Converter& Converter::get()
{
    static Converter instance;
    return instance;
}

int Converter::getInput(int location, const std::string& file)
{
    if (!input) {
        switch(location) {
            case L_STREAM:
                input =  new InputDataStream();
            break;
            case L_FILE:
                input =  new InputDataFile();
            break;
            default:
                return 1;
        }
        if (input->getData(file))
            return 1;
    }
    return 0;
}

int Converter::getFXRate(FXRate* rate, const std::string& in_curr, const std::string& out_curr, const std::string& data)
{
    if (!rate)
        return 1;

    if (!ex_rate) {
        ex_rate = rate;
        if(ex_rate->getCours(in_curr, out_curr, data))
            return 1;
    }

    return 0;
}

int Converter::setOutput(int location, int type, const std::string& file)
{
    if (!output) {
        switch (location) {
            case L_STREAM:
                output =  new OutputBuilderStream;
                if (output->buildOutput(input, ex_rate->getCoursValue()))
                    return 1;
                if (output->print(type, input))
                    return 1;
            break;
            case L_FILE:
                output =  new OutputBuilderFile;
                if (output->buildOutput(input, ex_rate->getCoursValue()))
                    return 1;
                if (output->print(type, input, file))
                    return 1;
            break;
            default:
                return 1;
        }

    }
    return 0;
}
