#ifndef CONVERTER_H
#define CONVERTER_H

/**
 * \file
 * \brief Definicja klasy zarządzającej konwersją walut Converter.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include "Enums.h"
#include "InputData.h"
#include "InputDataStream.h"
#include "InputDataFile.h"
#include "FXRate.h"
#include "OutputBuilder.h"
#include "OutputBuilderStream.h"
#include "OutputBuilderFile.h"

/**
 * \brief Klasa zarządzająca konwersją walutową.
 *
 * Jest to główna klasa abstrakcji konwersji walutowej.\n\n
 * Klasa ta:\n
 * - pełni rolę fabryki, we wzorcu projektowym <b>factory method</b>, dla pobierania danych wejściowych;\n
 * - wybiera algorytm, zgodnie ze wzorcem projektowym <b>strategy</b>, sposobu pobierania kursu dla danych walut;\n
 * - pełni rolę dyrektora, we wzorcu projektowym <b>builder</b>, przy generowaniu danych wyjściowych.
 */
class Converter
{
    private:
        static InputData* input; ///< Dane wejściowe
        static OutputBuilder* output; ///< Budowniczy danych wyjściowych
        static FXRate* ex_rate; ///< Nasz kurs walutowy

    public:
        /**
        * \brief Zwraca instancję obiektu.
        */
        static Converter& get();
        /**
        * \brief Pobiera dane wejściowe.
        */
        static int getInput(int location, const std::string& file);
        /**
        * \brief Pobiera kurs.
        */
        static int getFXRate(FXRate* rate, const std::string& in_curr, const std::string& out_curr, const std::string& data);
        /**
        * \brief Generuje dane wyjściowe.
        */
        static int setOutput(int location, int type, const std::string& file);
};

#endif // CONVERTER_H
