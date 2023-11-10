#include "ManagementSystem.h"
#include<algorithm>
ManagementSystem::ManagementSystem()
{
}

void ManagementSystem::addSoft(Software* soft)
{
	arr.push_back(soft);
}

void ManagementSystem::showInfo() const
{
	for (const Software* soft: arr)
	{
		cout << "-----------\n";
		soft->show();
		cout << "-----------\n";
	}
}

void ManagementSystem::showAvailableSoft() const
{
	for (const Software* soft : arr)
	{
		if (soft->isAvailable())
		{
			cout << "-----------\n";
			soft->show();
			cout << "-----------\n";
		}
	}
}

void ManagementSystem::removeSoft(int ind)
{
	if (ind >= 0 && ind< arr.size())
	{
		delete arr[ind];
		arr.erase(arr.begin() + ind);
	}
}

void ManagementSystem::sortByProd()
{
	std::sort(arr.begin(), arr.end(), [](const Software* left, const Software* right) {return left->getCompany() < right->getCompany(); });
}

void ManagementSystem::saveSystem() const
{
	ofstream file("admin.txt");
	if (file.is_open())
	{
		for (int i = 0; i < arr.size(); i++) {
			arr[i]->save(file);
		}
		file.close();
	}

}

void ManagementSystem::loadSystem()
{
	ifstream file("admin.txt");
	if (file.is_open())
	{
		string typeObj;
		Software* p = nullptr;
		while (!file.eof())
		{
			getline(file, typeObj);
			if (typeObj == "Free")
			{
				p = new Free();
				p->load(file);
				arr.push_back(p);
			}
			else if(typeObj == "Shareware")
			{
				p = new Shareware();
				p->load(file);
				arr.push_back(p);
			}
			else if (typeObj == "Commercial")
			{
				p = new Commercial();
				p->load(file);
				arr.push_back(p);
			}
		}
		file.close();
	}
}
