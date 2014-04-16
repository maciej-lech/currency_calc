#ifndef CURLWRAPPER_H
#define CURLWRAPPER_H

/**
 * \file
 * \brief Definicja wrappera CURLWrapper biblioteki CURL.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <string>
#include <curl/curl.h>

/**
 * \brief Wrapper biblioteki CURL do pobierania danych przez protokół http.
 *
 * Wrapper biblioteki <a href="http://curl.haxx.se/libcurl/">CURL</a>,
 * wykorzystywany przez klasę FXRateNBP do pobierania pliku .xml z kursami walutowymi.
 * Klasa ta jest statyczna.
 */
class CURLWrapper
{
    private:
        static CURL *handle; ///< Handler curl.
        static std::string data; ///< Dane typu string

        /**
        * \brief Funkcja callback do zapisu przez bibliotekę curl.
        */
        static int curlWriteMemoryCallback(void *contents, size_t size, size_t blocks, void *mem_data);

    public:
        /**
        * \brief Konstruktor inicjujący bibliotekę curl.
        */
        CURLWrapper();
        /**
        * \brief Destruktor zwalniający zasoby wykorzystywane przez bibliotekę curl.
        */
        ~CURLWrapper();
        /**
        * \brief Pobiera dane przez protokół http.
        */
        static int downloadData(const std::string& url);
        /**
        * \brief Zwraca wskaźnik na pobrane dane.
        */
        static std::string* getDataPointer();
};

#endif // CURLWRAPPER_H
