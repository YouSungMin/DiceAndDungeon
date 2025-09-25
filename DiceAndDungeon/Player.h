#pragma once
#include "Actor.h"
class Player : public Actor
{
public:
	Player() = default;
	Player(const std::string InName, float InHealth, float InAttackPower, float InDefensivePower)
	{
		Name = InName;
		//HealthPoint += InHealth;
		HealthPoint = 5.0f;
		MaxHealth = HealthPoint;
		AttackPower += InAttackPower;
		DefensivePower += InDefensivePower;
	}
	bool IsHealthPointFull(){return HealthPoint == MaxHealth;}
public:
	void SetPlayerHealth(float InHealth)
	{
		SetHealth(InHealth); // ���� Ŭ����(Actor)�� protected ����� ����
	}
	void SetPlayerGold(int InGold)
	{
		SetGold(InGold);
	}
private:
};

