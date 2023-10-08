#include "Weapon.h"
using namespace std;
#include <iostream>

Weapon::Weapon() 
{
	wName = "Fist";
	wDescription = "Simple strengh";
	wDamages = 5;
}
Weapon::Weapon(string name, string description, WeaponType type, int weight, int damages, int cost, int durability)
{
	wName = name;
	wDescription = description;
	wType = type;
	wWeight = weight;
	wDamages = damages;
	wCost = cost;
	wDurability = durability;
}

Weapon::~Weapon(){}

void Weapon::Display()
{
	cout << "- " << GetWeaponTypeString() << ": " << wName << ", " << wDamages << ". It's cost " << wCost * (0.2 + wDurability) << " golds." << endl;
}

string Weapon::GetName() 
{
	return wName;
}

string Weapon::GetDescription() 
{
	return wDescription;
}

string Weapon::GetWeaponTypeString() 
{
	return WeaponTypeToString(wType);
}

int Weapon::GetWeight()
{
	return wWeight;
}

int Weapon::GetDamages()
{
	return wDamages;
}

int Weapon::GetCost()
{
	return wCost;
}

int Weapon::GetDurability() 
{
	return wDurability;
}