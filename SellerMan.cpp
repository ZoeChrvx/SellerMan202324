#include <iostream>
#include <string>
#include "Weapon.h"
#include "WeaponType.h"
#include "Character.h"
#include "Merchant.h"
using namespace std;


int main()
{
	//Player Information
	string firstName;
	string lastName;
	string catchPhrase;	
	Weapon playerWeapon;
	int choiceWeapon;
	Job playerJob = Job::Unemployed;
	int choiceClass;
	Races playerRace = Races::Undefined;
	int choiceRace;
	vector<Weapon> playerInventory;

	//Merchant
	vector<Weapon> shopInventory;
	Merchant merchant("Bob", "BilboQuet", "Welcome in my bilbobi Shop !", 99999, shopInventory);

	//Weapons
	Weapon basicSword("Bloody Sword", "a basic sword", WeaponType::Sword, 5, 10, 10, 1);
	Weapon basicDagger("Sticky Dagger", "a basic dagger", WeaponType::Dagger, 5, 10, 10, 1);
	Weapon basicStaff("Fire Staff", "a basic staff", WeaponType::Staff, 5, 10, 10, 1);
	Weapon basicBow("Windy Wind", "a basic bow", WeaponType::Bow, 5, 10, 10, 1);

	Weapon excalibur("Excalibur", "the legendary sword", WeaponType::Sword, 20, 25, 99, 1);


	//Character
	vector<Weapon> arthurInventory;
	Character arthurP("Arthur", "Pendragon", "See the light through my blade !", 500, 100, excalibur, Races::Human, Job::Warrior, arthurInventory);
		
	
	cout << "Hey ! Let's create your character !" << endl;
	cout << "First, what is your first name ?" << endl;
	cin >> firstName;
	cout << "And your last name ?" << endl;
	cin >> lastName;
	cout << "Nice " << firstName << " ! Now tell me yur catchphrase !" << endl;
	cin >> catchPhrase;
	cout << "Okey perfect buddy. You're going have 100 life point and 100 golds to start you're adventure." << endl;
	cout << endl;
	cout << endl;
	cout << "Now you need to choose a weapon between these 4 basics weapons." << endl;
	Character::DisplayBasicWeapon();
	cin >> choiceWeapon;
	if (choiceWeapon == 1) {
		playerWeapon = basicSword;
	}
	else if (choiceWeapon == 2) {
		playerWeapon = basicDagger;
	}
	else if (choiceWeapon == 3) {
		playerWeapon = basicStaff;
	}
	else if (choiceWeapon == 4) {
		playerWeapon = basicBow;
	}
	else {
		Character::DisplayBasicWeapon();
		cin >> choiceWeapon;
	}

	
	while (playerRace == Races::Undefined) {
		cout << "Now you need to choose a race between these 4 races." << endl;
		Character::DisplayRace();
		cin >> choiceRace;
		playerRace = Character::ChooseRace(choiceRace);
	}

	while (playerJob == Job::Unemployed) {
		cout << "Now you need to choose a class between these 4 classes." << endl;
		Character::DisplayClasses();
		cin >> choiceClass;
		playerJob = Character::ChooseClass(choiceClass);
	}
	Character player(firstName, lastName, catchPhrase, 100, 100, playerWeapon, playerRace, playerJob, playerInventory);

	cout << "Sooo, now, this is you !" << endl;
	player.Display();
	cout << endl;
	cout << endl;
	player.DisplayActivities(merchant);
	
	merchant.DisplayInventoryShop();



	
}
