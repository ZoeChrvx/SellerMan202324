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
		DisplayInventoryShop();
		return ;
	}
	else if (choice == 2) {
		//player.DisplayInventoryPlayer();
		return;
	}
	else if (choice == 3) {
		player.DisplayActivities(*this);
		return ;
	}
}

void Merchant::DisplayInventoryShop()
{
	for(Weapon weapon : mWeapons)
	{
		weapon.GetName();
	}
}

