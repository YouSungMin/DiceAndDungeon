#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
public:
	virtual void UseSkill()override;
    Zombie()
        : Enemy("Zombie", 400, 600, 120, 200)
    {
        HealthPoint = MaxHealth;
    }
    virtual ~Zombie(){};
private:
	
};

