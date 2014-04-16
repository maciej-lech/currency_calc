#ifndef LOG_H
#define LOG_H

/**
 * \file
 * \brief Definicja klasy Log, wyświetlającej informacje o działaniu programu.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include <iostream>
#include <string>

 /**
 * \brief Klasa wyświetlania powiadomień.
 *
 * Klasa typu <b>singleton</b> wyświetlająca powiadomienia na standardowym wyjściu,
 * gdy program zostanie uruchomiony z opcją \e --verbose. \e
 */
class Log
{
    private:
        static Log* instance; ///< Instancja klasy
        bool skip_log; ///< Flaga pomijania powiadomień
        /**
        * \brief Prywatny konstruktor.
        */
        Log();

    public:
        /**
        * \brief Zwraca instancję obiektu.
        */
        static Log& get();
        /**
        * \brief Wyświetla powiadomienie.
        */
        template <typename T> void log(const T& line)
        {
            if (!skip_log)
                std::cout << line;
        }
        /**
        * \brief Przeciążony operator<< wyświetlający powiadomienie.
        */
        template <typename T> Log& operator<<(const T& line)
        {
            log(line);
            return *this;
        }
        /**
        * \brief Ustawia flagę pomijania powiadomień.
        */
        void skipLog(bool skip);
};

#endif // LOG_H
