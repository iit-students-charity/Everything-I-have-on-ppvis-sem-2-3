#pragma once
#include <string>
namespace details
{
	class Weapon
	{
	protected:
		int ammo;
		int maxAmmo;
	public:
		virtual std::string fireOnce();
		virtual std::string happyTrigger();
		void reload();
		Weapon();
		~Weapon();
	};
	
}
namespace Weaponry
{
	class Handgun : public virtual details::Weapon
	{
	public:
		std::string hipFire();
	};
	class AssultRifle : public virtual details::Weapon
	{
	public:
		std::string fireOnce();
		std::string leadEmUp();
	};

	class Glock : public Handgun
	{
	public:
		Glock();
		std::string fireOnce();
	};

	class Colt : public Handgun
	{
	public:
		Colt();
		void russianRoulette();
		std::string fireOnce();
	};

	
	class Kalashnikov : public AssultRifle
	{
	public:
		Kalashnikov();
	};
	class M4 : public AssultRifle
	{
	public:
		M4();
	};
	class WunderWaffe : public AssultRifle, public Handgun
	{
	public:
		WunderWaffe();
	};
}