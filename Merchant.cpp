#include "Merchant.h"
#include "Character.h"
using namespace std;
#include <iostream>

Merchant::Merchant(string name, string shopName, string catchPhrase, int money, vector<Weapon> weapons)
{
	mName = name;
	mShopName = shopName;
	mCatchPhrase = catchPhrase;
	mMoney = money;
	mWeapons = weapons;
}

Merchant::~Merchant() {};


string Merchant::GetName() 
{
	return mName;
}

string Merchant::GetShopName()
{
	return mShopName;
}

string Merchant::GetCatchPhrase()
{
	return mCatchPhrase;
}

int Merchant::GetMoney()
{
	return mMoney;
}


void Merchant::Display()
{
	cout << "I'm " << mName << " ! " << mCatchPhrase << " The " << mShopName << " ! " << endl;
}

void Merchant::DisplayShop()
{
	cout << "Hello traveler ! " << endl;
	Display();
	cout << "We sell a lot of different weapon and we also can buy your weapon at a nice price." << endl;

}

void Merchant::BuyOrSell(Character player)
{
	cout << "Do you want to buy or sell something ?" << endl << "Or just quit my shop ?" << endl;
	cout << "1. Buy" << endl << "2. Sell" << endl << "3. Quit" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		DisplayInventoryShop(player);

		return ;
	}
	else if (choice == 2) {
		player.DisplayInventoryPlayer(*this);
		return;
	}
	else if (choice == 3) {
		player.DisplayActivities(*this);
		return ;
	}
}

void Merchant::DisplayInventoryShop(Character player)
{
	cout << "(Choose the number of the weapon you want to buy)" << endl;
	int nbWeapon = 0;
	for(Weapon weapon : mWeapons)
	{
		nbWeapon += 1;
		cout << nbWeapon << " ";
		weapon.Display();
	}
	cout << "- Return" << endl;
	cout << endl;
	int chooseWeaponBuy;
	cin >> chooseWeaponBuy;
	if(chooseWeaponBuy-1 <= mWeapons.size())
	{
		if (player.GetMoney() >= mWeapons[chooseWeaponBuy - 1].GetCost() * (0.2 + mWeapons[chooseWeaponBuy - 1].GetDurability())) 
		{
			player.AddInventoryPlayer(mWeapons[chooseWeaponBuy - 1]);
			DeleteInventory(chooseWeaponBuy);
			cout << "Thank you for your purchase !" << endl;
			cout << "You have " << player.GetMoney() << " gold left" << endl;
			cout << "Do you want buy something else ?" << endl;
			cout << "1- Yes" << endl << "2- No" << endl;
			int choose;
			cin >> choose;
			if(choose == 1)
			{
				DisplayInventoryShop(player);
			}
			else if(choose == 2)
			{
				BuyOrSell(player);
			}
		}
		else if(player.GetMoney() < mWeapons[chooseWeaponBuy - 1].GetCost() * (0.2 + mWeapons[chooseWeaponBuy - 1].GetDurability()))
		{
			cout << "Oh sorry " << player.GetFirstName() << ". You don't have the money to get that." << endl;
		}
	}
	else if (chooseWeaponBuy- 1 == mWeapons.size() + 1) 
	{
		BuyOrSell(player);
	}

}

void Merchant::AddInventory(Weapon weapon)
{
	std::vector<Weapon>::iterator it = mWeapons.end();
	it = mWeapons.insert(it, weapon);
}

void Merchant::DeleteInventory(int purchasedWeapon)
{
	std::vector<Weapon>::iterator it = mWeapons.begin() + (purchasedWeapon-1);
	it = mWeapons.erase(it);
}