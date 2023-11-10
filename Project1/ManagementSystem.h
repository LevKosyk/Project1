#pragma once
#include"Commersial.h"
#include"Free.h"
#include"Shareware.h"
#include"Software.h"
#include<vector>
#include<fstream>
class ManagementSystem
{
    vector<Software*> arr;
public:
    ManagementSystem();
    ~ManagementSystem()
    {
        for (Software* soft : arr)
        {
            delete soft;
        }
        arr.clear();
    }

    void addSoft(Software* soft);
    void showInfo()const;
    void showAvailableSoft()const;

    void removeSoft(int ind);
    void sortByProd();

    void saveSystem()const;
    void loadSystem();
};

