// Pivas2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Weapon.h"
#include <iostream>
#include<ctime>
using namespace Weaponry;
using namespace std;

int main()
{
	srand(time(NULL));
	int choice = 1;
	Glock* glock = new Glock();
	Colt* colt = new Colt();
	Kalashnikov* ak = new Kalashnikov();
	M4* ar = new M4();
	WunderWaffe* super = new WunderWaffe();

	while (choice)
	{
		int weaponOfChoice = 1;
		cout << "CHOOSE YOUR WEAPON" << endl << "0-Leave the shooting range\n1-Glock\n2-Colt Anaconda\n3-Kalash\n4-M4\n5-SuperWeapon" << endl;
		cin >> choice;
		switch (choice)
		{
		default:
			break;
		case 0:
			return 0;
		case 1:
			while (weaponOfChoice)
			{
				cout << "0-Choose another weapon\n1-Fire one bullet\n2-Shoot the whole mag (remember, no rapid fire in the building)\n3-Hipfire\n4-reload" << endl;
				cin >> weaponOfChoice;
				switch (weaponOfChoice)
				{
				default:
					break;
				case 1:
					cout << glock->fireOnce() << endl;
					break;
				case 2:
					cout << glock->happyTrigger() << endl;
					break;
				case 3:
					cout << glock->hipFire() << endl;
					break;
				case 4:
					glock->reload();
					break;
				}
			}
			break;
		case 2:
			while (weaponOfChoice)
			{
				cout << "0-Choose another weapon\n1-Fire one bullet\n2-Shoot the whole cylinder (remember, no rapid fire in the building)\n3-Hipfire\n4-reload\n5-Play russian roulette" << endl;
				cin >> weaponOfChoice;
				switch (weaponOfChoice)
				{
				default:
					break;
				case 1:
					cout << colt->fireOnce() << endl;
					break;
				case 2:
					cout << colt->happyTrigger() << endl;
					break;
				case 3:
					cout << colt->hipFire() << endl;
					break;
				case 4:
					colt->reload();
					break;
				case 5:
					colt->russianRoulette();
					cout << "You're still alive" << endl;
				}
			}
			break;
		case 3:
			while (weaponOfChoice)
			{
				cout << "0-Choose another weapon\n1-Fire one bullet\n2-Shoot the whole mag (remember, no rapid fire in the building)\n3-AutoFire\n4-reload" << endl;
				cin >> weaponOfChoice;
				switch (weaponOfChoice)
				{
				default:
					break;
				case 1:
					cout << ak->fireOnce() << endl;
					break;
				case 2:
					cout << ak->happyTrigger() << endl;
					break;
				case 3:
					cout << ak->leadEmUp() << endl;
					break;
				case 4:
					ak->reload();
					break;
				}
			}
			break;
		case 4:
			while (weaponOfChoice)
			{
				cout << "0-Choose another weapon\n1-Fire one bullet\n2-Shoot the whole mag (remember, no rapid fire in the building)\n3-AutoFire\n4-reload" << endl;
				cin >> weaponOfChoice;
				switch (weaponOfChoice)
				{
				default:
					break;
				case 1:
					cout << ar->fireOnce() << endl;
					break;
				case 2:
					cout << ar->happyTrigger() << endl;
					break;
				case 3:
					cout << ar->leadEmUp() << endl;
					break;
				case 4:
					ar->reload();
					break;
				}
			}
			break;
		case 5:
			while (weaponOfChoice)
			{
				cout << "0-Choose another weapon\n1-Fire one bullet\n2-Shoot the whole mag (remember, no rapid fire in the building)\n3-AutoFire\n4-Hipfire\n5-reload" << endl;
				cin >> weaponOfChoice;
				switch (weaponOfChoice)
				{
				default:
					break;
				case 1:
					cout << super->fireOnce() << endl;
					break;
				case 2:
					cout << super->happyTrigger() << endl;
					break;
				case 3:
					cout << super->leadEmUp() << endl;
					break;
				case 4:
					cout << super->hipFire() << endl;
				case 5:
					super->reload();
					break;
				}
			}
			break;
		}
	}
	return 0;
}
  


