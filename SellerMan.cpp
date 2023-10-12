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

	// Weapon Shop
	Weapon damocles("Damocles", "the double-edged sword", WeaponType::Sword, 15, 50, 50, 1);
	Weapon glamdring("Glamdring", "Gandalf's dagger", WeaponType::Dagger, 7, 20, 50, 1);
	Weapon boStaff("Bo", "the gorgious Bo", WeaponType::Staff, 12, 30, 50, 1);
	Weapon arthemis("Golden Bow", "Arthemis's Weapon", WeaponType::Bow, 35, 45, 50, 1);

	shopInventory.push_back(damocles);
	shopInventory.push_back(glamdring);
	shopInventory.push_back(boStaff);
	shopInventory.push_back(arthemis);

	Merchant merchant("Bob", "BilboQuet", "Welcome in my bilbobi Shop !", 99999, shopInventory);

	//Weapons
	//Basic
	Weapon basicSword("Bloody Sword", "a basic sword", WeaponType::Sword, 5, 10, 10, 1);
	Weapon basicDagger("Sticky Dagger", "a basic dagger", WeaponType::Dagger, 5, 10, 10, 1);
	Weapon basicStaff("Fire Staff", "a basic staff", WeaponType::Staff, 5, 10, 10, 1);
	Weapon basicBow("Windy Wind", "a basic bow", WeaponType::Bow, 5, 10, 10, 1);

	
	//Arthur
	Weapon excalibur("Excalibur", "the legendary sword", WeaponType::Sword, 20, 25, 99, 1);

	//Character
	vector<Weapon> arthurInventory;
	Character arthurP("Arthur", "Pendragon", "See the light through my blade !", 500, 100, excalibur, Races::Human, Job::Warrior, arthurInventory);
		


	cout << "Hey ! Let's create your character !" << endl;
	cout << "First, what is your first name ?" << endl;
	cin >> firstName;
	cout << "And your last name ?" << endl;
	cin >> lastName;
	cout << "Nice " << firstName << " ! Now tell me your catchphrase !" << endl;
	cin >> catchPhrase;
	cout << "Okey perfect buddy. You're going have 100 life point and 100 golds to start you're adventure." << endl;
	cout << endl;
	cout << endl;
	cout << "Now you need to choose a weapon between these 4 basics weapons." << endl;
	Character::DisplayBasicWeapon();
	cin >> choiceWeapon;
	if (choiceWeapon == 1) {
		std::vector<Weapon>::iterator it = playerInventory.begin();
		it = playerInventory.insert(it, basicSword);
		playerWeapon = *it;
	}
	else if (choiceWeapon == 2) {
		std::vector<Weapon>::iterator it = playerInventory.begin();
		it = playerInventory.insert(it, basicDagger);
		playerWeapon = *it;
	}
	else if (choiceWeapon == 3) {
		std::vector<Weapon>::iterator it = playerInventory.begin();
		it = playerInventory.insert(it, basicStaff);
		playerWeapon = *it;
	}
	else if (choiceWeapon == 4) {
		std::vector<Weapon>::iterator it = playerInventory.begin();
		it = playerInventory.insert(it, basicBow);
		playerWeapon = *it;
	}
	else 
	{
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
	player.DisplayActivities(merchant, arthurP);



	
}
