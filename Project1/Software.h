#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Software
{
protected:
	string name;
	string company;
public:
	Software();
	Software(string name, string company);
	virtual ~Software();

	void setName(string name);
	void setCompany(string company);

	string getName()const;
	string getCompany()const;

	virtual void show()const =0;
	virtual string type()const = 0;
	virtual bool isAvailable()const = 0;

	virtual void save(ofstream& file)const=0;
	virtual void load(ifstream& file) = 0;
}; 

