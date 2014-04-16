#ifndef FXRATENBP_H
#define FXRATENBP_H

/**
 * \file
 * \brief Definicja klasy FXRateNBP, pobierającej kurs walutowy ze strony <a href="http://www.nbp.pl">nbp.pl</a>.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <string>
#include "FXRate.h"
#include "CURLWrapper.h"

/**
 * \brief Klasa algorytmu pobierania kursów ze strony <a href="http://www.nbp.pl">nbp.pl</a>.
 *
 * Klasa potomna od FTRate, wykorzystywana we wzorcu <b>strategy</b>,
 * wyboru algorytmu pobierania kursów walutowych.\n
 * Pobiera kursy walutowe ze strony Narodowego Banku Polskiego, wykorzystując CURLWrapper.
 */
class FXRateNBP : public FXRate
{
    private:
        /**
        * \brief Generuje nazwę pliku .xml, dla podanej daty.
        */
        std::string getXmlFromDate(std::string* dir_file, std::string data);
        /**
        * \brief Wyszukuje odpowiedni kurs w pliku .xml z nbp.pl.
        */
        double getValue(std::string* xml, const std::string& curr);

    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~FXRateNBP() {}
        /**
        * \brief Funckja pobierania kursu.
        */
        virtual int getCours(const std::string& in_curr, const std::string& out_curr, const std::string& data);
};

#endif // FXRATENBP_H
