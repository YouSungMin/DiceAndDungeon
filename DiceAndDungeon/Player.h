#pragma once
#include "Actor.h"
class Player : public Actor
{
public:
	Player() = default;
	Player(const std::string InName, float InHealth, float InAttackPower, float InDefensivePower)
	{
		Name = InName;
		HealthPoint += InHealth;
		MaxHealth = HealthPoint;
		AttackPower += InAttackPower;
		DefensivePower += InDefensivePower;
	}
private:
	
};

