#include "Merchant.h"
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
