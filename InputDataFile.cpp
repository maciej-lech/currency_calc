#include "InputDataFile.h"

int InputDataFile::getData(std::string param)
{
    std::string buff;
    std::stringstream ss;
    double num;
    std::fstream file;

    file.open(param, std::ios::in);
    if(file.good()) {
        while(!file.eof()) {
            getline(file, buff);
            ss << buff << " ";
        }
        file.close();
    }
    else
        return 1;

    ss.imbue(std::locale(std::locale(), new numeric_only()));

    while (1) {
        if (!isspace(ss.peek())) {
            if (!(ss >> num))
                break;
            push(num);
            continue;
        }
        ss.get();
    }

    if (!size())
        return 1;

    return 0;
}
