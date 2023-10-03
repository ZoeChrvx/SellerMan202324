#include <iostream>
#include <string>
#include "Weapon.h"
#include "WeaponType.h"
#include "Character.h"
using namespace std;


int main()
{
	//Weapons
	Weapon excalibur("Excalibur", "the legendary sword", WeaponType::Sword, 20, 25, 99, 1);

	Weapon basicSword("Bloody Sword", "a basic sword", WeaponType::Sword, 5, 10, 10, 1);
	Weapon basicDagger("Sticky Dagger", "a basic dagger", WeaponType::Dagger, 5, 10, 10, 1);
	Weapon basicStaff("Fire Staff", "a basic staff", WeaponType::Staff, 5, 10, 10, 1);
	Weapon basicBow("Windy Wind", "a basic bow", WeaponType::Bow, 5, 10, 10, 1);

	//Character
	Character arthurP("Arthur", "Pendragon", "See the light through my blade !", 500, 100, excalibur, Races::Human, Job::Warrior);



	cout << "Hey ! Let's create your character !" << endl;
	cout << "First, what is your first name ?" << endl;
	string firstName;
	cin >> firstName;
	cout << "And your last name ?" << endl;
	string lastName;
	cin >> lastName;
	cout << "Nice " << firstName << " ! Now tell me yur catchphrase !" << endl;
	string catchPhrase;
	cin >> catchPhrase;
	cout << "Okey perfect buddy. You're going have 100 life point and 100 golds to start you're adventure." << endl;
	cout << "Now you need to choose a class between these 4 classes." << endl;
	cout << endl;
	cout << "(Tape the number of the class you want between 1 and 4)" << endl;
	cout << 1 << ". Sword" << endl;
	cout << 2 << ". Dagger" << endl;
	cout << 3 << ". Staff" << endl;
	cout << 4 << ". Bow" << endl;
	int choiceClass;

	Character personal(firstName, lastName, catchPhrase, 100, 100, )


	
}
