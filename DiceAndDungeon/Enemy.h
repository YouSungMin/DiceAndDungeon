#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:
	virtual void UseSkill();
	~Enemy() = default;
    Enemy(const std::string& InName, int InMinHealth, int InMaxHealth, int InMinAttack, int InMaxAttack)
        : Actor(InName)
    {
        int randomHealth = rand() % (InMaxHealth - InMinHealth + 1) + InMinHealth;
        int randomAttack = rand() % (InMaxAttack - InMinAttack + 1) + InMinAttack;

        this->MaxHealth = static_cast<float>(randomHealth) / 10.0f;
        this->AttackPower = static_cast<float>(randomAttack) / 10.0f;
        Gold = rand() % (MaxDropGold - MinDropGold +1) + MinDropGold;
        DefensivePower = 0.0f;
    }
protected:
    static const int MaxDropGold = 15;
    static const int MinDropGold = 5;
};

