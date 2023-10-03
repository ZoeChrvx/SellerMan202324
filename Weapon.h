#pragma once
#include "WeaponType.h"

class Weapon
{
private:
	std::string wName;
	std::string wDescription;
	WeaponType wType;
	int wWeight;
	int wDamages;
	int wCost;
	int wDurability;

public:
	Weapon();
	Weapon(std::string name, std::string description, WeaponType type, int weight, int damages, int cost, int durability);
	~Weapon();

	std::string GetName();
	std::string GetDescription();
	std::string GetWeaponTypeString();
	int GetWeight();
	int GetDamages();
	int GetCost();
	int GetDurability();
};

