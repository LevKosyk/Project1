#include "Shareware.h"

Shareware::Shareware()
{
    install = Date();
    days = 4;
}

Shareware::Shareware(string name, string company, int days, Date install)
    :Software(name, company)
{
    this->days = days;
    this->install = install;
}

void Shareware::setDate(Date install)
{
    this->install = install;
}

void Shareware::setDays(int days)
{
    this->days = days;
}

Date Shareware::getDate() const
{
    return install;
}

int Shareware::getDays() const
{
    return days;
}

void Shareware::show() const
{
    cout << "Type:      " << type() << endl;
    cout << "Name:      " << name << endl;
    cout << "Company:   " << company << endl;
    cout << "Term:      " << days << endl;
    cout << "Install:   " << install << endl;
    cout << "Use until: " << install + days << endl;
    cout << "Available: " << isAvailable() << endl;
}

string Shareware::type() const
{
    return "Shareware";
}

bool Shareware::isAvailable() const
{
    return install + days >= Date();

}

void Shareware::save(ofstream& file) const
{
    file << type() << endl;
    file << name << endl;
    file << company << endl;
    file << install.getDay()<< " "<<install.getMonth()<<" "<< install.getYear() << endl;
    file << days << endl;
}

void Shareware::load(ifstream& file)
{
    getline(file, name);
    getline(file, company);
    int d, m, y;
    file >> d >> m >> y;
    install = Date(y, m, d);
    file >> days;
}
