#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
public:
	virtual void UseSkill()override;
    Goblin()
        : Enemy("Goblin", 300, 400, 120, 180)
    {
        HealthPoint = MaxHealth;
    }
    virtual ~Goblin() {};
};

