#include "Character.h"
#include "Merchant.h"
using namespace std;
#include <iostream>
#include <random>

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
		return Job::Unemployed;
		DisplayClasses();
	}
}

void Character::DisplayActivities(Merchant& merchant, Character enemy)
{
	cout << "Do you want to go fight some rivals or you want to go buy some weapons ?" << endl;
	cout << "1. Go Shop" << endl;
	cout << "2. Go Fight" << endl;
	cout << "3. Change Weapon" << endl;
	int choiceActivities;
	cin >> choiceActivities;
	if (choiceActivities == 1)
	{
		merchant.DisplayShop();
		merchant.BuyOrSell(*this, enemy);
	}
	else if (choiceActivities == 2) 
	{
		cout << "Ok ! Let's go meet your first (and only) enemy !" << endl;
		cout << enemy.GetCatchPhrase() << " The only one, " << enemy.GetFirstName() << " " << enemy.GetLastName() << " And I'm here to defeat you !" << endl;

		while (this->IsAlive() && enemy.IsAlive()) 
		{
			Attack(enemy);
			enemy.Attack(*this);
		}
		if (this->IsAlive()) {
			cout << "You win champion ! " << endl;
			cout << "He has some loot on him, let's find out these rewards." << endl;
			cout << "There are " << enemy.cWeapon.GetName() << " and " << enemy.cMoney << " golds." << endl;
			Loot(enemy);
			DisplayActivities(merchant, enemy);
		}
		else if(enemy.IsAlive())
		{
			cout << "Oh non, he beat you !" << endl;
			cout << "This is a GAME OVER" << endl;
			exit;
		}
	}
	else if(choiceActivities == 3)
	{
		cout << "Your equipped weapon is " << cWeapon.GetName() << "." << endl;
		cout << "Would you change your weapon ?" << endl;
		cout << "- Yes" << endl;
		cout << "- No" << endl;
		std::string answer;
		cin >> answer;
		if(answer == "yes" || answer == "Yes" || answer == "YES")
		{
			int nbWeapon = 0;
			cout << "(Choose the number of the weapon you want to equip)" << endl;
			for (Weapon weapon : cInventory)
			{
				nbWeapon += 1;
				cout << nbWeapon << " ";
				weapon.Display();
			}
			cout << nbWeapon + 1 << " ";
			cout << "- Return" << endl;
			int chooseEquippedWeapon;
			cout << cInventory.size() << endl;
			cin >> chooseEquippedWeapon;
			chooseEquippedWeapon--;
			if (chooseEquippedWeapon <= cInventory.size())
			{
				Weapon* temporary = &cInventory[0];
				cInventory[0] = cInventory[chooseEquippedWeapon];
				cInventory[chooseEquippedWeapon] = *temporary;

			}
		}
	}
}

void Character::DisplayInventoryPlayer(Merchant merchant, Character enemy)
{
	int nbWeapon = 0;
	cout << "(Choose the number of the weapon you want to sell)" << endl;
	for (Weapon weapon : cInventory)
	{
		nbWeapon += 1;
		cout << nbWeapon << " ";
		weapon.Display();
	}
	cout << nbWeapon + 1 << " ";
	cout << "- Return" << endl;
	int chooseWeaponSell;
	cout << cInventory.size() << endl;
	cin >> chooseWeaponSell;
	chooseWeaponSell--;
	if(chooseWeaponSell <= cInventory.size())
	{
		merchant.AddInventory(cInventory[chooseWeaponSell]);
		cMoney += cInventory[chooseWeaponSell].GetCost() * cInventory[chooseWeaponSell].GetDurability();
		DeleteInventoryPlayer(chooseWeaponSell);
		cout << "Thank you for your purchase !" << endl;
		cout << "You have " << GetMoney() << " gold left" << endl;
		cout << "Do you want buy something else ?" << endl;
		cout << "1- Yes" << endl << "2- No" << endl;
		int choose;
		cin >> choose;
		if (choose == 1)
		{
			DisplayInventoryPlayer(merchant, enemy);
		}
		else if (choose == 2)
		{
			merchant.BuyOrSell(*this, enemy);
		}
	}
}

void Character::AddInventoryPlayer(Weapon weapon)
{
	cInventory.push_back(weapon);
	cMoney = (int)(weapon.GetCost() * (0.2 + weapon.GetDurability()));
}

void Character::DeleteInventoryPlayer(int soldWeapon)
{
	cInventory.erase(cInventory.begin() + soldWeapon);
}

void Character::Attack(Character& target)
{
	int damages = cWeapon.GetDamages();
	cout << cFirstName << " " << cLastName << " attacks " << target.GetFirstName() << " " << target.GetLastName() << " and inflicts " << damages << " dmg." << endl;
	int x = rand() % 10;
	x = x / 50;
	cWeapon.SetDurability(x);
	target.TakeDamage(damages);
}
void Character::TakeDamage(int enemyAttack)
{
	cLifePoint -= enemyAttack;
	cout << cFirstName << " " << cLastName << " has " << cLifePoint << " hp." << endl;
	
}

bool Character::IsAlive()
{
	if (cLifePoint <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void Character::Loot(Character& target)
{
	cInventory.insert(cInventory.end(), target.cWeapon);
	cMoney = cMoney + target.cMoney;
}

