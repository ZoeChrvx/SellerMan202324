#pragma once
#include <iostream>
#include "Weapon.h"
#include <vector>
#include "Character.h"


class Merchant
{
private:
	std::string mName;
	std::string mShopName;
	std::string mCatchPhrase;
	int mMoney;
	std::vector<Weapon> mWeapons;
public:
	Merchant(std::string name, std::string shopName, std::string catchPhrase, int money, std::vector<Weapon> weapons);
	~Merchant();

	std::string GetName();
	std::string GetShopName();
	std::string GetCatchPhrase();
	int GetMoney();

	void Display();
	void DisplayShop();
	void BuyOrSell(Character player);
	void DisplayInventoryShop(Character player);
	void AddInventory(Weapon weapon);
	void DeleteInventory(int purchasedWeapon);

};

