#include "Log.h"

Log* Log::instance = 0;

Log::Log()
{
    skip_log = true;
}

Log& Log::get()
{
    if (!instance) {
        instance = new Log;
    }
    return *instance;
}

void Log::skipLog(bool skip)
{
    skip_log = skip;
}
