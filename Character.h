#pragma once
#include <iostream>
#include<vector>
#include "Races.h"
#include "Job.h"
#include "Weapon.h"

class Merchant;

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
	std::vector<Weapon> cInventory;

public:
	Character(std::string firstName, std::string lastName, std::string catchPhrase, int money, int lifePoint,Weapon weapon, Races race, Job job, std::vector<Weapon> inventory);
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
	void Loot(Character& target);
	void DisplayInventoryPlayer(Merchant merchant, Character enemy);
	void AddInventoryPlayer(Weapon weapon);
	void DeleteInventoryPlayer(int soldWeapon);
	bool IsAlive();

	static void DisplayBasicWeapon();
	static void DisplayRace();
	static Races ChooseRace(int choice);
	static void DisplayClasses();
	static Job ChooseClass(int choice);
	void DisplayActivities(Merchant& merchant, Character enemy);
	
	
};

