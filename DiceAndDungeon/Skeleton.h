#pragma once
#include "Enemy.h"
class Skeleton : public Enemy
{
public:
	virtual void UseSkill()override;
    Skeleton()
        : Enemy("Skeleton", 300, 500, 300, 350)
    {
        HealthPoint = MaxHealth;
    }
    virtual ~Skeleton(){};
};

