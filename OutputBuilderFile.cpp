#include "OutputBuilderFile.h"

int OutputBuilderFile::print(int type, InputData* in, std::string param)
{
    bool table_view;
    char sep;
    std::vector<double>::iterator in_it, out_it;
    std::fstream file;

    switch (type) {
        case TEXT_TABLE_SPACE_SEPARATOR:
            table_view = true;
            sep = ' ';
        break;
        case TEXT_TABLE_TAB_SEPARATOR:
            table_view = true;
            sep = '\t';
        break;
        case TEXT_SPACE_SEPARATOR:
            table_view = false;
            sep = ' ';
        break;
        case TEXT_TAB_SEPARATOR:
            table_view = false;
            sep = '\t';
        break;
        case TEXT_NEWLINE_SEPARATOR:
            table_view = false;
            sep = '\n';
        break;
        default:
            return 1;
    }

    file.open(param, std::ios::out);
    if (file.good()) {
        if (table_view) {
            for (in_it = in->begin(), out_it = output->begin(); in_it != in->end(); ++in_it, ++out_it)
                file << *in_it << sep << *out_it << '\n';
        }
        else {
            for (out_it = output->begin(); out_it != in->end(); ++out_it)
                file << *out_it << sep;
        }
        file.close();
    }
    else
        return 1;



    return 0;
}
