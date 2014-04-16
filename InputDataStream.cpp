#include "InputDataStream.h"

int InputDataStream::getData(std::string param)
{
    std::string buff;
    std::stringstream ss;
    double num;

    std::getline(std::cin, buff);
    ss << buff;

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
