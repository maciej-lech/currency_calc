#include "Data.h"

void Data::push(double value)
{
    this->data.push_back(value);
}

double Data::get(unsigned int i)
{
    return this->data.at(i);
}

/*void Data::copyData(std::istream_iterator<double> first, std::istream_iterator<double> last)
{
    copy(first, last, std::back_inserter(data));
}*/

std::vector<double>::iterator Data::begin()
{
    return data.begin();
}

std::vector<double>::iterator Data::end()
{
    return data.end();
}

std::vector<double>::size_type Data::size()
{
    return data.size();
}
