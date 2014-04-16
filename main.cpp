/* -*- Mode: C++; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * currency_calc (Currency calculator).
 *
 * Copyright (C) 2014 Maciej Lech & Karol Sowa
 *
 */

 /**
 * \file
 * \brief Funkcja main().
 *
 * Plik ten jest częścią projektu currency_calc.
 */

#include "Application.h"

 /**
 * \file
 * \brief Funkcja main().
 *
 * Funkja main() programu.
 */
int main(int argc, const char* argv[])
{
    int exit_status = Application::get()->run(argc, argv);

    return exit_status;
}
