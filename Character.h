#pragma once
#include <iostream>
#include "Races.h"
#include "Job.h"
#include "Weapon.h"

class Character
{
private:
	std::string cFirstName;
	std::string cLastName;
	std::string cCatchPhrase;
	int cMoney;
	int cLifePoint;
	Weapon cWeapon;
	Races cRace;
	Job cJob;

public:
	Character(std::string firstName, std::string lastName, std::string catchPhrase, int money, int lifePoint,Weapon weapon, Races race, Job job);
	Character(Weapon weapon);
	~Character();

	std::string GetFirstName();
	std::string GetLastName();
	std::string GetCatchPhrase();
	int GetMoney();
	int GetLifePoint();
	std::string GetRace();
	std::string GetJob();

	void Display();
	void Attack(Character& target);
	void TakeDamage(int enemyAttack);
	void Loot(Character&);
	void DisplayInventoryPlayer();

	static void DisplayBasicWeapon();
	static void DisplayRace();
	static Races ChooseRace(int choice);
	static void DisplayClasses();
	static Job ChooseClass(int choice);
	static void DisplayActivities(Merchant& merchant);
	
	
};

