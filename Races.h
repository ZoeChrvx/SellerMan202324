#pragma once
#include <string>

enum class Races
{
	Undefined,
	Elf,
	Orc,
	Goblin,
	Human
};

static std::string RacesToString(Races race)
{
	switch (race)
	{
	case Races::Elf:
		return "elf";
	case Races::Orc:
		return "orc";
	case Races::Goblin:
		return "goblin";
	case Races::Human:
		return "human";	
	default:
		return "blob";
	}
	
}

