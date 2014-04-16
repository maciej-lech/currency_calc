#ifndef INPUTDATASTREAM_H
#define INPUTDATASTREAM_H

/**
 * \file
 * \brief Definicja klasy InputDataStream, pobierającej dane ze standardowego wejścia.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <iostream>
#include <sstream>
#include "InputData.h"

/**
 * \brief Klasa pobierająca dane ze standardowego wejścia.
 *
 * Klasa pobiera danych wejściowe ze stdin, wykorzystywana we wzorcu <b>factory metod</b>.
 */
class InputDataStream : public InputData
{

    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~InputDataStream() {}
        /**
        * \brief Funkcja pobiera dane ze standardowego wejśćia.
        */
        virtual int getData(std::string param);
};

#endif // INPUTDATASTREAM_H
