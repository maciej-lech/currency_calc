#ifndef OUTPUTBUILDER_H
#define OUTPUTBUILDER_H

/**
 * \file
 * \brief Definicja klasy OutputBuilder, nadrzędnej klasy budującej dane wyjścia.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include "InputData.h"
#include "OutputData.h"

/**
 * \brief Nadrzędny budowniczy interpretacji formatowania danych wyjściowych.
 *
 * Nadrzędny budowniczy interpretacji formatowania danych wyjściowych.
 * Klasa nadrzędna dla innych, wykorzystywana we wzorcu <b>builder</b>.
 */
class OutputBuilder
{
    protected:
        static OutputData* output; ///< Dane wyjściowe

    public:
    /**
        * \brief Konstruktor.
        */
        OutputBuilder();
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~OutputBuilder() {}
        /**
        * \brief Generuje dane wyjściowe.
        */
        int buildOutput(InputData* in, double course);
        /**
        * \brief Funkcja do prezentacji danych, przeciążana przez klasy pochodne.
        */
        virtual int print(int type, InputData* in, std::string param = "") = 0;
};

#endif // OUTPUTBUILDER_H
