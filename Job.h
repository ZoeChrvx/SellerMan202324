#pragma once
#include <string>

enum class Job
{
	Archer,
	Warrior,
	Priest,
	Paladin
};

static std::string JobToString(Job job) 
{
	switch (job) 
	{
	case Job::Archer:
		return "archer";
	case Job::Warrior:
		return "warrior";
	case Job::Priest:
		return "priest";
	case Job::Paladin:
		return "paladin";
	default:
		return "you are nothing";
	}
	
}

