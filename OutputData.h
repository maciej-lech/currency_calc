#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H

/**
 * \file
 * \brief Definicja klasy OutputData, pochodnej klasy Data, przechowującej dane wyjściowe.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <iostream>
#include "Data.h"
#include "InputData.h"

/**
 * \brief Klasa przechowująca dane wyjściowe.
 *
 * Klasa przechowuje danych wyjściowe, wykorzystywana we wzorcu <b>builder</b>.
 */
class OutputData : public Data
{
    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~OutputData() {}
        /**
        * \brief Funkcja przeliczająca dane dla podanego kursu.
        */
        void setData(InputData* in, double course);
};

#endif // OUTPUTDATA_H
