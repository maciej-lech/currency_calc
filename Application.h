#ifndef APPLICATION_H
#define APPLICATION_H

/**
 * \file
 * \brief Definicja głównej klasy aplikacji Application.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <iostream>
#include <string>
#include <algorithm>
#include "Enums.h"
#include "Log.h"
#include "Converter.h"
#include "FXRate.h"
#include "FXRateNBP.h"

const char* const appName = "currency_calc"; ///< Stała z nazwą programu.
const char* const appVersion = "1.0"; ///< Stała z wersją programu.
const char* const appInfo = "Currency calculator"; ///< Stała z opisem programu.
const char* const appAutors = "Maciej Lech & Karol Sowa"; ///< Stała z autorami.
const char* const appRelDate = "January 2014"; ///< Stała z datą utworzenia programu.

/**
 * \brief Główna klasa aplikacji.
 *
 * Jest to główna klasa programu. Wykorzystuje ona wzorzec <b>singleton</b>.
 * Jej instancja jest tworzona w funkcji main().
 */
class Application
{
    private:
        static Application* instance; ///< Wskaźnik do instancji jedynego obiektu klasy.

        int input; ///< Informacja o lokalizacji danych wejściowych.
        int output; ///< Informacja o lokalizacji danych wyjściowych.
        int out_type; ///< Informacja o sposobie formatowania danych wyjściowych.
        int ex_rate_algorithm; ///< Informacja o źródle kursów walutowych.
        bool verbose; ///< Informacja, czy włączyć "tryb krzykliwy".
        std::string in_currency; ///< Waluta danych wejściowych.
        std::string out_currency; ///< Waluta danych wyjściowych
        std::string date; ///< Data kursów: "RRMMDD", lub domyślnie najnowsze ""
        std::string in_file; ///< Plik z danymi wejściowymi
        std::string out_file; ///< Plik z danymi wyjściowymi

        /**
        * \brief Prywatny konstruktor.
        */
        Application();
        /**
        * \brief Parser linii poleceń.
        */
        int parseCommandLine(int argc, const char* argv[]);
        /**
        * \brief Wypisuje pomoc, z ewentualnymi błędami parsowania linii poleceń.
        */
        void showUsage(const std::string& err = "");
        /**
        * \brief Wypisuje informacje o programie i autorach.
        */
        void showAbout();
        /**
        * \brief Ustawia domyślne opcje.
        */
        void setDefault();
        /**
        * \brief Drukuje opis błędu.
        */
        void printError(const std::string& err);

    public:
        /**
        * \brief Zwraca instancję obiektu.
        */
        static Application* get();
        /**
        * \brief Uruchamia dalsze działanie aplikacji.
        */
        int run(int argc, const char* argv[]);
};

#endif // APPLICATION_H
