#include "Free.h"

Free::Free()
{
}

Free::Free(string name, string company)
    :Software(name, company)
{
}

Free::~Free()
{
    cout << "~Free()" << endl;
}

void Free::show() const
{
    cout << "Type:    " << type() << endl;
    cout << "Name:    " << name << endl;
    cout << "Company: " << company << endl;
    cout << "Available: " << isAvailable() << endl;

}

string Free::type() const
{
    return "Free";
}

bool Free::isAvailable() const
{
    return true;
}

void Free::save(ofstream& file) const
{
    file << type() << endl;
    file << name << endl;
    file << company << endl;
}

void Free::load(ifstream& file)
{
    getline(file, name);
    getline(file, company);
}
