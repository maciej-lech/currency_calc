#ifndef OUTPUTBUILDERFILE_H
#define OUTPUTBUILDERFILE_H

/**
 * \file
 * \brief Definicja klasy OutputBuilderFile, budującej i zapisującej dane wyjściowe do pliku.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <fstream>
#include "Enums.h"
#include "OutputBuilder.h"

/**
 * \brief Budowniczy prezentacji danych wyjściowych w pliku.
 *
 * Budowniczy prezentacji danych wyjściowych w pliku.
 * Klasa pochodna od OutputBuilder, wykorzystywana we wzorcu <b>builder</b>.
 */
class OutputBuilderFile : public OutputBuilder
{
    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~OutputBuilderFile() {}
        /**
        * \brief Funckaja drukuje dane do pliku.
        */
        virtual int print(int type, InputData* in, std::string param = "");
};

#endif // OUTPUTBUILDERFILE_H
