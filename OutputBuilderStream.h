#ifndef OUTPUTBUILDERSTREAM_H
#define OUTPUTBUILDERSTREAM_H

/**
 * \file
 * \brief Definicja klasy OutputBuilderStream, budującej i prezentującej dane na standardowym wyjściu.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <iostream>
#include "Enums.h"
#include "OutputBuilder.h"

/**
 * \brief Budowniczy prezentacji danych wyjściowych na standardowym wejśćiu.
 *
 * Budowniczy prezentacji danych wyjściowych na standardowym wejśćiu.
 * Klasa pochodna od OutputBuilder, wykorzystywana we wzorcu <b>builder</b>.
 */
class OutputBuilderStream : public OutputBuilder
{
    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~OutputBuilderStream() {}
        /**
        * \brief Funckaja drukuje dane na standardowym wyjściu.
        */
        virtual int print(int type, InputData* in, std::string param = "");
};

#endif // OUTPUTBUILDERSTREAM_H
