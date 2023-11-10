#pragma once
#include "Software.h"
class Free :
    public Software
{
public:
    Free();
    Free(string name, string company);
    ~Free();

    void show()const override;
    string type()const override;
    bool isAvailable()const override;

    virtual void save(ofstream& file)const override;
    virtual void load(ifstream& file) override;
};

