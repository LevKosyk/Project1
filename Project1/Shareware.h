#pragma once
#include "Software.h"
#include"Date.h"
class Shareware :
    public Software
{
protected:
    Date install;
    int days;
public:
    Shareware();
    Shareware(string name, string company, int days, Date install);

    void setDate(Date install);
    void setDays(int days);

    Date getDate()const;
    int getDays()const;

    void show()const override;
    string type()const override;
    bool isAvailable()const override;


    virtual void save(ofstream& file)const override;
    virtual void load(ifstream& file) override;
};

