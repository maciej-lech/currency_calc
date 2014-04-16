#ifndef ENUMS_H
#define ENUMS_H

/**
 * \file
 * \brief Definicje typów wyliczeniowych wykorzystywanych w programie.
 *
 * Plik ten jest częścią projektu currency_calc.
 */

/**
 * \brief Typy lokalizacji danych.
 */
enum {L_STREAM, L_FILE};
/**
 * \brief Typy formatowania danych wyjściowych.
 */
enum {TEXT_TABLE_SPACE_SEPARATOR, TEXT_TABLE_TAB_SEPARATOR, TEXT_SPACE_SEPARATOR, TEXT_TAB_SEPARATOR, TEXT_NEWLINE_SEPARATOR};
/**
 * \brief Typy algorytmów pobierania kursów walutowych.
 */
enum {EX_RATE_NBP};

#endif // ENUMS_H
