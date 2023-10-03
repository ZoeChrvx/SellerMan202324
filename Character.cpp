#include "Character.h"
using namespace std;
#include <iostream>

Character::Character(string firstName, string lastName, string catchPhrase, int money, int lifePoint, Weapon weapon, Races race, Job job)
{
	cFirstName = firstName;
	cLastName = lastName;
	cCatchPhrase = catchPhrase;
	cMoney = money;
	cLifePoint = lifePoint;
	cWeapon = weapon;
	cRace = race;
	cJob = job;
}

Character::Character(Weapon weapon)
{
	cFirstName = "Arthur";
	cLastName = "Pendragon";
	cCatchPhrase = "See the light through my blade !";
	cMoney = 999;
	cLifePoint = 100;
	cWeapon = weapon;
	cRace = Races::Human;
	cJob = Job::Warrior;
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
	cout << "Hello, i'm " << cFirstName << " " << cLastName << " ! " << cCatchPhrase << endl;
	cout << "This character has " << cMoney << " golds and " << cWeapon.GetName() << "." << endl;
}

void Character::DisplayClasses() 
{
	cout << "(Tape the number of the class you want between 1 and 4)" << endl;
	cout << 1 << ". Sword" << endl;
	cout << 2 << ". Dagger" << endl;
	cout << 3 << ". Staff" << endl;
	cout << 4 << ". Bow" << endl;
}

Job ChooseClass(int choice)
{
	if (choice == 1) 
	{
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
	else if (choice > 4) {
		Character.DisplayClasses();
	}
}

int Character::Attack(Character& target)
{
	int damages = cWeapon.GetDamages();
	cout << cFirstName << " " << cLastName << " attacks " << target.GetFirstName() << " " << target.GetLastName() << " and inflicts " << damages << " dmg." << endl;
	target.TakeDamage(damages);
}
void Character::TakeDamage(int enemyAttack)
{
	cLifePoint - enemyAttack;
	cout << cFirstName << " " << cLastName << " has " << cLifePoint << " hp." << endl;
	
}
void Loot(Character&);

