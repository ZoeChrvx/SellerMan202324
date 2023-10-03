#pragma once
#include <string>
 
enum class WeaponType
{
	Bow,
	Dagger,
	Staff,
	Sword,
};

static std::string WeaponTypeToString(WeaponType type)
{
	switch (type)
	{
	case WeaponType::Bow:
		return "bow";
	case WeaponType::Dagger:
		return "dagger";
	case WeaponType::Staff:
		return "staff";
	case WeaponType::Sword:
		return "sword";
	default:
		return "fist";
	}
	
}