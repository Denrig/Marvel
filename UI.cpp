#include "UI.h"
UI::UI() {
	startUP();
}
UI::~UI(){}

void UI::startUP() {
	cout << "                     Welcome to the Marvel Universe." << "\n";
	int n,n1,n2,n3,n4;
	cout << "What do you want to do?" << "\n";
	while (true)
	{
		cout << "1.See the list of characters." << "\n";
		cout << "2.See the list of planets." << "\n";
		cout << "3.Join the fight." << "\n";
		cout << "5.Exit" << "\n";
		while (true)
		{
			cout << "\n" << "Please insert the NUMBER of your option then press ENTER:";
			cin >> n;
			if (cin.fail()||n<1||n>4) {
				cin.clear(); cin.ignore();
				cout << "Re-enter a valid value! " << endl;
			}
			else break;
		}
		
		if (n == 1) {
			ClearScreen();
			cout << f.getCh().toString();
		}
		else if (n == 2)
		{
			ClearScreen();
			cout << f.getPl().toString();
		}
		
		else if (n == 3)
		{
			cout << "\n" << "Glad to see you could join the fight!Now im gonna show you a list of heroes and you have to chose which one of them will represend the force of good." << endl << endl;
			cout << f.getHero().toString();
			while (true)
			{

				cout << "\n" << "Please insert the NUMBER of your hero then press ENTER:";
				cin >> n1;
				
				if (cin.fail() || n1 < 1 || n1>8) {
					cin.clear(); cin.ignore();
					cout << "Re-enter a valid value! " << endl;
				}
				else break;
			}
			ClearScreen();
			cout << "\n" << "Now which enemy shall our hero face?"<<endl;
			cout << f.getVillan().toString();
			while (true)
			{

				cout << "\n" << "Please insert the NUMBER of your villain then press ENTER:"<<endl<<endl;
				cin >> n2;
				
				if (cin.fail() || n2 < 1 || n2>8) {
					cin.clear(); cin.ignore();
					cout << "Re-enter a valid value! " << endl;
				}
				else break;
			}ClearScreen();
			cout << "\n" << "Where shall they fight each other?"<<"\n";
			cout << f.getPl().toString();
			while (true)
			{

				cout << "\n" << "Please insert the NUMBER of your planet then press ENTER:";
				cin >> n3;
				
				if (cin.fail() || n3 < 1 || n3>5) {
					cin.clear(); cin.ignore();
					cout << "Re-enter a valid value! " << endl;
				}
				else break;
			}


			Character a = f.fight(f.getPl().getAll()[n3-1], f.getHero().getAll()[n1-1], f.getVillan().getAll()[n2-1]);
		cout << a.getName() << "-WON";
			}	
		else { 
			cout << endl << endl;
			cout << "Farewell avanger!";
			Sleep(2000);
			break; }
		cout << endl << "Do you want to do more amazing things?"<<endl;
		cout << "1.Yes"<<endl;
		cout << "2.No";
		while (true)
		{

			cout << "\n" << "Please insert the NUMBER of your option then press ENTER:";
			cin >> n4;
			if (cin.fail() || n4 < 1 || n4>2) {
				cin.clear(); cin.ignore();
				cout << "Re-enter a valid value! " << endl;
			}
			else break;
		}
		if (n4 == 2)
		{
			cout << endl << endl;
			cout << "Farewell avanger!";
			Sleep(2000);
			break;
		}
		else
			continue;
		
	}
}
void UI::ClearScreen()
{
	int n;
	for (n = 0; n < 10; n++)
		printf("\n\n\n\n\n\n\n\n\n\n");
}