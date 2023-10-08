#include "Character.h"
#include "Merchant.h"
using namespace std;
#include <iostream>

Character::Character(string firstName, string lastName, string catchPhrase, int money, int lifePoint, Weapon weapon, Races race, Job job, std::vector<Weapon> inventory)
{
	cFirstName = firstName;
	cLastName = lastName;
	cCatchPhrase = catchPhrase;
	cMoney = money;
	cLifePoint = lifePoint;
	cWeapon = weapon;
	cRace = race;
	cJob = job;
	cInventory = inventory;
}

Character::~Character() {};

string Character::GetFirstName() 
{
	return cFirstName;
}
string Character::GetLastName()
{
	return cLastName;
}
string Character::GetCatchPhrase() 
{
	return cCatchPhrase;
}
int Character::GetMoney()
{
	return cMoney;
}
int Character::GetLifePoint() 
{
	return cLifePoint;
}
string Character::GetRace() 
{
	return RacesToString(cRace);
}

string Character::GetJob() 
{
	return JobToString(cJob);
}


void Character::Display()
{
	cout << "Hello, i'm " << cFirstName << " " << cLastName << " ! " << cCatchPhrase << " And i'm a " << GetRace() << " and a " << GetJob() << "." << endl;
	cout << "This character has " << cMoney << " golds and a " << cWeapon.GetName() << "." << endl;
}

void Character::DisplayBasicWeapon()
{
	cout << "(Tape the number of the weapon you want between 1 and 4)" << endl;
	cout << 1 << ". Sword" << endl;
	cout << 2 << ". Dagger" << endl;
	cout << 3 << ". Staff" << endl;
	cout << 4 << ". Bow" << endl;
}

void Character::DisplayRace()
{
	cout << "(Tape the number of the race you want between 1 and 4)" << endl;
	cout << 1 << ". Elf" << endl;
	cout << 2 << ". Orc" << endl;
	cout << 3 << ". Gobelin" << endl;
	cout << 4 << ". Human" << endl;
}
Races Character::ChooseRace(int choice)
{
	if (choice == 1) {
		return Races::Elf;
	}
	else if (choice == 2) {
		return Races::Orc;
	}
	else if (choice == 3) {
		return Races::Goblin;
	}
	else if (choice == 4) {
		return Races::Human;
	}
	else {
		return Races::Undefined;
	}
}

void Character::DisplayClasses() 
{
	cout << "(Tape the number of the class you want between 1 and 4)" << endl;
	cout << 1 << ". Warrior" << endl;
	cout << 2 << ". Paladin" << endl;
	cout << 3 << ". Priest" << endl;
	cout << 4 << ". Archer" << endl;
}
Job Character::ChooseClass(int choice)
{
	if (choice == 1) {
		return Job::Warrior;
	}
	else if (choice == 2) {
		return Job::Paladin;
	}
	else if (choice == 3) {
		return Job::Priest;
	}
	else if (choice == 4) {
		return Job::Archer;
	}
	else {
		DisplayClasses();

	}
}

void Character::DisplayActivities(Merchant& merchant)
{
	cout << "Do you want to go fight some rivals or you want to go buy some weapons ?" << endl;
	cout << "1. Go Shop" << endl;
	cout << "2. Go Fight" << endl;
	int choiceActivities;
	cin >> choiceActivities;
	if (choiceActivities == 1) {
		merchant.DisplayShop();
		merchant.BuyOrSell(*this);
	}
	else if (choiceActivities == 2) {
		//go fight
	}
}

void Character::DisplayInventoryPlayer()
{
	cWeapon.Display();
	for (Weapon weapon : cInventory)
	{
		weapon.Display();
	}
}

void Character::Attack(Character& target)
{
	int damages = cWeapon.GetDamages();
	cout << cFirstName << " " << cLastName << " attacks " << target.GetFirstName() << " " << target.GetLastName() << " and inflicts " << damages << " dmg." << endl;
	target.TakeDamage(damages);
}
void Character::TakeDamage(int enemyAttack)
{
	cLifePoint -= enemyAttack;
	cout << cFirstName << " " << cLastName << " has " << cLifePoint << " hp." << endl;
	
}
void Character::Loot(Character&)
{

}

