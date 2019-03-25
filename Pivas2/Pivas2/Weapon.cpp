#include "stdafx.h"
#include "Weapon.h"
#include <string>
using namespace std;
using namespace Weaponry;
using namespace details;


std::string details::Weapon::fireOnce()
{
	return std::string();
}

std::string details::Weapon::happyTrigger()
{
	string rez;
	if (ammo == 0) return "No ammo, reload your gun";
	while (this->ammo > 0)
	{
		rez = rez + this->fireOnce() + " ";
	}
	return rez;
}

void Weapon::reload()
{
	this->ammo = this->maxAmmo;
}

details::Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

std::string Weaponry::Handgun::hipFire()
{
	if(ammo==0) return "No ammo, reload your gun";
	ammo--;
	return "*miss*";
}

std::string Weaponry::Glock::fireOnce()
{
	if (ammo == 0) return "No ammo, reload your gun";
	ammo--;
	return "pew";
}

Weaponry::Glock::Glock()
{
	maxAmmo = 16;
	ammo = 16;
}

Weaponry::Colt::Colt()
{
	maxAmmo = 6;
	ammo = 6;
}

void Weaponry::Colt::russianRoulette()
{
	int chance = rand() % 6;
	if (!chance)
	{
		exit(0);
	}
}

std::string Weaponry::Colt::fireOnce()
{
	if(ammo==0) return "No ammo, reload your gun";
	ammo--;
	return "Bam";
}

string Weaponry::AssultRifle::fireOnce()
{
	if (ammo == 0)
	{
		return "No ammo left, reload your gun";
	}
	this->ammo--;
	return "Puff";
}

std::string Weaponry::AssultRifle::leadEmUp()
{
	string fire;
	if (ammo < 2)
	{
		return this->fireOnce();
	}
	fire = "tra";
	ammo--;
	while (ammo > 0)
	{
		fire = fire + "ta";
		ammo--;
	}
	return fire;
}

Weaponry::Kalashnikov::Kalashnikov()
{
	maxAmmo = 31;
	ammo = 31;
}

Weaponry::M4::M4()
{
	maxAmmo = 31;
	ammo = 31;
}

Weaponry::WunderWaffe::WunderWaffe()
{
	ammo = 31;
	maxAmmo = 31;
}
