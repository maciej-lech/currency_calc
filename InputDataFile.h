#ifndef INPUTDATAFILE_H
#define INPUTDATAFILE_H

/**
 * \file
 * \brief Definicja klasy InputDataFile, pobierającej dane wejściowe z pliku.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <fstream>
#include <sstream>
#include "InputData.h"

/**
 * \brief Klasa pobierająca dane z pliku.
 *
 * Klasa pobiera danych wejściowe z pliku, wykorzystywana we wzorcu <b>factory metod</b>.
 */
class InputDataFile : public InputData
{
public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~InputDataFile() {}
        /**
        * \brief Funkcja pobiera dane z pliku.
        */
        virtual int getData(std::string param);
};

#endif // INPUTDATAFILE_H
