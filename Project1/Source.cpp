#include"Software.h"
#include"Free.h"
#include"Shareware.h"
#include"Commersial.h"
#include"ManagementSystem.h"
int main() {
	int menu = 0;
	string str1, str2;
	double p;
	int d;
	//Software* a1 = new Free("Chrome", "Google");
	//Software* a2 = new Free("Opera", "Google");


	//Software* b1 = new Shareware("Opera", "Google", 12, Date());
	//Software* b2 = new Shareware("VisualStudio", "Xz", 10, Date());


	//Software* c1 = new Commercial(120, "lev", "Xfs", 10, Date());
	//Software* c2 = new Commercial(120, "Youtube", "Google", 12, Date());

	ManagementSystem arr;

	//arr.addSoft(a1);
	//arr.addSoft(a2);
	//arr.addSoft(b1);
	//arr.addSoft(b2);
	//arr.addSoft(c1);
	//arr.addSoft(c2);
	do
	{
		cout << "1 - Show info\n";
		cout << "2 - Availbel soft\n";
		cout << "3 - Add free soft\n";
		cout << "4 - Add comertical soft\n";
		cout << "5 - Add Software Conditiolna Free soft\n";
		cout << "6 - Remove soft\n";
		cout << "7 - Sort\n";
		cout << "8 - Save system\n";
		cout << "9 - Load system\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			arr.showInfo();
			break;
		case 2:
			arr.showAvailableSoft();
			break;
		case 3:
			cout << "Input name: " << endl;
			cin.ignore();
			getline(cin, str1);
			cout << "Input company:\n";
			getline(cin, str2);
			arr.addSoft(new Free(str1, str2));
			break;
		case 4:
			cout << "Input name: ";
			cin.ignore();
			getline(cin, str1);
			cout << "Input company: ";
			getline(cin, str2);
			cout << "Input turms: ";
			cin >> d;
			cout << "Input price: ";
			cin >> p;
			arr.addSoft(new Commercial(p, str1, str2, d, Date()));
			break;
		case 5:
			cout << "Input name: ";
			cin.ignore();
			getline(cin, str1);
			cout << "Input company: ";
			getline(cin, str2);
			cout << "Input turms: ";
			cin >> d;
			arr.addSoft(new Shareware(str1, str2, d, Date()));
			break;
		case 6:
			cout << "input num: \n";
			cin >> d;
			arr.removeSoft(d);
			break;
		case 7:
			arr.sortByProd();
			break;
		case 8:
			arr.saveSystem();
			break;
		case 9:
			arr.loadSystem();
			break;
		}

	} while (menu != 0);
}