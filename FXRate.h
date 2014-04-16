#ifndef FXRATE_H
#define FXRATE_H

/**
 * \file
 * \brief Definicja klasy FXRate, nadrzędnej dla klasy pobierania kursu walutowego.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <string>

/**
 * \brief Nadrzędna klasa algorytmu pobierania kursów.
 *
 * Nadrzędna klasa, wykorzystywana we wzorcu <b>strategy</b>,
 * wyboru algorytmu pobierania kursów walutowych.
 */
class FXRate
{
    private:
        double course; ///< Zmienna przechowująca kurs

    public:
        /**
        * \brief Konstruktor.
        */
        FXRate();
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~FXRate() {}
        /**
        * \brief Funckja pobierania kursu, do przeciążenia przez klasę potomną.
        */
        virtual int getCours(const std::string& in_curr, const std::string& out_curr, const std::string& data) = 0;
        /**
        * \brief Zwraca kurs.
        */
        double getCoursValue() const;
        /**
        * \brief Ustawia kurs.
        */
        void setCourseValue(double val);
};

#endif // FXRATE_H
