#pragma once
#include "Enemy.h"
class Oak : public Enemy
{
public:
	virtual void UseSkill()override;
    Oak()
        : Enemy("Oak", 1000, 1200, 400, 500)
    {
        HealthPoint = MaxHealth;
    }
    virtual ~Oak() {};
};

