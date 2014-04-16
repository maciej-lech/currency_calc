#include "FXRateNBP.h"

std::string FXRateNBP::getXmlFromDate(std::string* dir_file, std::string date)
{
    std::string xml_name = "";
    std::size_t pos;

    pos = dir_file->rfind(date);
    if (pos != std::string::npos) {
        pos -= 4;
        xml_name.push_back('a');
        xml_name.append(dir_file->substr(pos, 10));
        xml_name.append(".xml");
    }

    return xml_name;
}

double FXRateNBP::getValue(std::string* xml, const std::string& curr)
{
    if (curr == "PLN")
        return 1.0;

    std::string curr_temp;
    std::size_t pos, pos2;
    double val, conv;

    curr_temp.append("<kod_waluty>");
    curr_temp.append(curr);
    curr_temp.append("</kod_waluty>");

    pos = xml->find(curr_temp);
    if (pos == std::string::npos)
        return 0.0;

    pos = xml->rfind("<przelicznik>", pos);
    if (pos == std::string::npos)
        return 0.0;
    pos += 13;
    pos2 = xml->find("</przelicznik>", pos);
    if (pos2 == std::string::npos)
        return 0.0;
    conv = std::stod(xml->substr(pos, pos2-pos));

    pos = xml->find("<kurs_sredni>", pos);
    if (pos == std::string::npos)
        return 0.0;
    pos += 13;
    std::string val_str = xml->substr(pos, 6);
    val_str.replace(1, 1, ".");
    val = std::stod(val_str);

    val /= conv;

    return val;
}

int FXRateNBP::getCours(const std::string& in_curr, const std::string& out_curr, const std::string& date)
{
    CURLWrapper file;

    std::string url = "http://www.nbp.pl/kursy/xml/";

    if (date != "") {
        if (file.downloadData("http://www.nbp.pl/kursy/xml/dir.txt"))
            return 1;
        url.append(getXmlFromDate(file.getDataPointer(), date));
    }
    else
        url.append("lasta.xml");


    if (file.downloadData(url))
        return 1;

    double in_val, out_val;

    in_val = getValue(file.getDataPointer(), in_curr);
    if (in_val == 0.0)
        return 1;

    out_val = getValue(file.getDataPointer(), out_curr);
    if (out_val == 0.0)
        return 1;

    setCourseValue(in_val / out_val);

    //std::cout << in_val << " / " << out_val << " = " << getCoursValue() << std::endl;

    return 0;
}
