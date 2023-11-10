#include "Commersial.h"

Commercial::Commercial()
{
    price = 0;
}

Commercial::Commercial(float price, string name, string company, int days, Date install)
    :Shareware(name, company, days, install)
{
    this->price = price;
}

Commercial::~Commercial()
{
    cout << "~Commercial()" << endl;
}

void Commercial::setPrice(float price)
{
    this->price = price;
}

float Commercial::getPrice() const
{
    return price;
}

void Commercial::show() const
{
    cout << "Type:      " << type() << endl;
    cout << "Name:      " << name << endl;
    cout << "Company:   " << company << endl;
    cout << "Term:      " << days << endl;
    cout << "Install:   " << install << endl;
    cout << "Use until: " << install + days << endl;
    cout << "Available: " << isAvailable() << endl;
    cout << "Price:     " << price << endl;
}

string Commercial::type() const
{
    return "Commercial";
}

void Commercial::save(ofstream& file) const
{
    file << type() << endl;
    file << name << endl;
    file << company << endl;
    file << install.getDay() << " " << install.getMonth() << " " << install.getYear() << endl;
    file << days << endl;
    file << price << endl;
}

void Commercial::load(ifstream& file)
{
    getline(file, name);
    getline(file, company);
    int d, m, y;
    file >> d >> m >> y;
    install = Date(y, m, d);
    file >> days;
    file >> price;
}
