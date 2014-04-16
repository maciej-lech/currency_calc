#ifndef DATA_H
#define DATA_H

/**
 * \file
 * \brief Definicja klasy Data modelującej kontener vector, dla przechowywania danych wejściowych i wyjściowych.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <vector>
#include <iterator>
//#include <algorithm>

/**
 * \brief Klasa modelująca kontener vector.
 *
 * Jest to klasa nadrzędna dla innych klas przechowujących dane.
 * Zabezpiecza ona przed bezpośrednim dostępem do wektora,
 * oferując ograniczony interfejs modyfikacji danych.
 */
class Data
{
    private:
        std::vector<double> data; ///< Wektor liczb zmiennoprzecinkowych

    public:
        /**
        * \brief Wirtualny destruktor.
        */
        virtual ~Data() {}
        /**
        * \brief Dodaje element do wektora danych.
        */
        void push(double value);
        /**
        * \brief Wyświetla element wektora.
        */
        double get(unsigned int i);
        /**
        * \brief Zwraca iterator na początek.
        */
        std::vector<double>::iterator begin();
        /**
        * \brief Zwraca iterator na koniec.
        */
        std::vector<double>::iterator end();
        /**
        * \brief Zwraca ilość elementów wektora.
        */
        std::vector<double>::size_type size();
        //void copyData(std::istream_iterator<double> first, std::istream_iterator<double> last);
};

#endif // DATA_H
