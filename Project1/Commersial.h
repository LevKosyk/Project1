#pragma once
#include "Shareware.h"
class Commercial :
    public Shareware
{
protected:
    float price;
public:
    Commercial();
    Commercial(float price, string name, string company, int days, Date install);
    ~Commercial();

    void setPrice(float price);

    float getPrice()const;

    void show()const override;
    string type()const override;

    virtual void save(ofstream& file)const override;
    virtual void load(ifstream& file) override;
};

