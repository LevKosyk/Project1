#include "Software.h"

Software::Software()
{
    name = "0";
    company = "0";
}

Software::Software(string name, string company)
{
    this->name = name;
    this->company = company;
}

Software::~Software()
{
    cout << "~Software()" << endl;
}

void Software::setName(string name)
{
    this->name = name;

}

void Software::setCompany(string company)
{
    this->company = company;
}

string Software::getName() const
{
    return name;
}

string Software::getCompany() const
{
    return company;
}
