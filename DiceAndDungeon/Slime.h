#pragma once
#include "Enemy.h"
class Slime : public Enemy
{
public:
	virtual void UseSkill()override;
    Slime()
        : Enemy(" Slime", 200, 300, 200, 250)
    {
        HealthPoint = MaxHealth;
    }
    virtual ~Slime() {};
};

