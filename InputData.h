#ifndef INPUTDATA_H
#define INPUTDATA_H

/**
 * \file
 * \brief Definicja klasy InputData, pochodnej klasy Data oraz nadrzędnej dla klas pobierających dane wejściowe.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <string>
#include <vector>
#include "Data.h"


/**
 * \brief Nadrzędna klasa danych wejściowych.
 *
 * Klasa nadrzędna dla danych wejściowych, wykorzystywana we wzorcu <b>factory metod</b>,
 * wyboru typu uzyskiwania danych.\n
 */
class InputData : public Data
{
    protected:
        /**
        * \brief Struktura filtru, dającego tylko dane liczbowe z wejśćia.
        */
        struct numeric_only: std::ctype<char>
        {
            numeric_only(): std::ctype<char>(get_table()) {}

            static std::ctype_base::mask const* get_table()
            {
                static std::vector<std::ctype_base::mask>
                    rc(std::ctype<char>::table_size,std::ctype_base::space);

                std::fill(&rc['0'], &rc[':'], std::ctype_base::digit);
                return &rc[0];
            }
        };

    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~InputData() {}
        /**
        * \brief Pobiera dane wejściowe. Funckja do przeciążenia dla klas pochodnych.
        */
        virtual int getData(std::string param) = 0;
};

#endif // INPUTDATA_H
