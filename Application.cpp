#include "Application.h"

Application* Application::instance = 0;

Application::Application()
{
     setDefault();
}

int Application::parseCommandLine(int argc, const char* argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];

            if ((arg == "-h") || (arg == "--help")) {
                verbose = false;
                Log::get().skipLog(true);
                showUsage();
                return 1;
            }
            if ((arg == "-a") || (arg == "--about")) {
                verbose = false;
                Log::get().skipLog(true);
                showAbout();
                return 1;
            }
            else if ((arg == "-v") || (arg == "--verbose")) {
                verbose = true;
                Log::get().skipLog(false);
            }
            else if ((arg == "-e") || (arg == "--ex_rate")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    if (arg == "nbp_http") {
                        ex_rate_algorithm = EX_RATE_NBP;
                    }
                    else {
                        showUsage("Unknown --ex_rate option argument...");
                        return 1;
                    }
                }
                else {
                    showUsage("--ex_rate option requires one argument...");
                    return 1;
                }
            }
            else if ((arg == "-d") || (arg == "--date")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    if (arg != "last")
                        date = arg;
                }
                else {
                    showUsage("--date option requires one argument...");
                    return 1;
                }
            }
            else if ((arg == "-i") || (arg == "--in")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    if (arg == "stdin")
                        input = L_STREAM;
                    else {
                        input = L_FILE;
                        in_file = arg;
                    }
                }
                else {
                    showUsage("--in option requires one argument...");
                    return 1;
                }
            }
            else if ((arg == "-o") || (arg == "--out")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    if (arg == "stdout")
                        output = L_STREAM;
                    else {
                        output = L_FILE;
                        out_file = arg;
                    }
                }
                else {
                    showUsage("--out option requires one argument...");
                    return 1;
                }
            }
            else if ((arg == "-t") || (arg == "--type")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    if (arg == "text_table_space_sep")
                        out_type = TEXT_TABLE_SPACE_SEPARATOR;
                    else if (arg == "text_table_tab_sep")
                        out_type = TEXT_TABLE_TAB_SEPARATOR;
                    else if (arg == "text_space_sep")
                        out_type = TEXT_SPACE_SEPARATOR;
                    else if (arg == "text_tab_sep")
                        out_type = TEXT_TAB_SEPARATOR;
                    else if (arg == "text_newline_sep")
                        out_type = TEXT_NEWLINE_SEPARATOR;
                    else {
                        showUsage("Unknown --type option argument...");
                        return 1;
                    }
                }
                else {
                    showUsage("--type option requires one argument...");
                    return 1;
                }
            }
            else if ((arg == "-ic") || (arg == "--in_curr")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    in_currency = arg;
                    std::transform(in_currency.begin(), in_currency.end(), in_currency.begin(), ::toupper);
                }
                else {
                    showUsage("--in_curr option requires one argument...");
                    return 1;
                }
            }
            else if ((arg == "-oc") || (arg == "--out_curr")) {
                if (i + 1 < argc) {
                    std::string arg = argv[++i];
                    out_currency = arg;
                    std::transform(out_currency.begin(), out_currency.end(), out_currency.begin(), ::toupper);
                }
                else {
                    showUsage("--out_curr option requires one argument...");
                    return 1;
                }
            }
            else {
                showUsage("Unknown commandline option...");
                return 1;
            }
        }
    }

    if ((in_currency == "") || (out_currency == "")) {
        showUsage("You must define both currency...");
        return 1;
    }

    return 0;
}

void Application::showUsage(const std::string& err)
{
    std::cout << appName << " " << appVersion << std::endl;

    if (err != "")
        printError(err);
    else
        std::cout << std::endl;

    std::cout << "Usage:\n"
              << "\t" << appName << " -ic CURRENCY -oc CURRENCY [OPTIONS]\n"
              << std::endl
              << "Options:\n"
              << "\t-ic X  --in_curr X\tType of input currency\n"
              << "\t-oc X  --out_curr X\tType of output currency\n\n"
              << "\t-e X  --ex_rate X\tExchange rate source (nbp_http*)\n"
              << "\t-d X  --date X\t\tExchange rate date (last*, %RRMMDD%)\n\n"
              << "\t-i X  --in X\t\tSet location of input data (stdin*, %FILE%)\n"
              << "\t-o X  --out X\t\tSet location of output data (stdout*, %FILE%)\n"
              << "\t-t X  --type X\t\tType of output data (text_table_space_sep, text_table_tab_sep*, text_space_sep, text_tab_sep, text_newline_sep)\n\n"
              << "\t-h  --help\t\tShow this help message\n"
              << "\t-a  --about\t\tShow about\n"
              << "\t-v  --verbose\t\tVerbose mode\n"
              << std::endl
              << "\t*  Default option\n"
              << std::endl;
}

void Application::showAbout()
{
    std::cout << appName << " " << appVersion << " - " << appInfo << std::endl << std::endl;

    std::cout << "\tThis application was created as a project on the subject of Object-oriented Systems Design.\n\n"
              << "\tAuthors:\t" << appAutors << "\n\n"
              << "\tRelease date:\t" << appRelDate << "\n"
              << std::endl;
}

void Application::setDefault()
{
     input = L_STREAM;
     output = L_STREAM;
     out_type = TEXT_TABLE_TAB_SEPARATOR;
     ex_rate_algorithm = EX_RATE_NBP;
     in_currency = "";
     out_currency = "";
     date = "";
     in_file = "";
     out_file = "";
     verbose = false;
}

void Application::printError(const std::string& err)
{
    std::cerr << std::endl << "ERROR: " << err << std::endl << std::endl;
}

Application* Application::get()
{
    if (!instance)
        instance = new Application;

    return instance;
}

int Application::run(int argc, const char* argv[])
{
    if(parseCommandLine(argc, argv))
        return 1;

    Log::get() << appName << " " << appVersion << " starting..." << "\n";

    Converter conv = Converter::get();

    Log::get() << "Getting input data..." << "\n";
    if(conv.getInput(input, in_file)) {
        printError("Error with getting input data...");
        return 1;
    }

    Log::get() << "Getting exchange rate ";
    FXRate *fx_rate = 0;
    if (ex_rate_algorithm == EX_RATE_NBP) {
        Log::get() << "from NBP site...\n";
        fx_rate = new FXRateNBP;
    }

    if(conv.getFXRate(fx_rate, in_currency, out_currency, date)) {
        printError("Error with getting exchange rate...");
        return 1;
    }
    Log::get() << "FX rate from " << in_currency << " to " << out_currency << " is " << fx_rate->getCoursValue() << "\n";

    Log::get() << "Generating output data..." << "\n";
    if(conv.setOutput(output, out_type, out_file)) {
        printError("Error with generating output data...");
        return 1;
    }



    return 0;
}


