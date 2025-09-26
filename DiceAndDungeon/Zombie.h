#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
    //Enemy를 상속받은 Zombie클래스
public:
    // 각각의 스킬을 위한 가상함수 처리
	virtual void UseSkill()override;

    // 생성자를 통해 이름과 최대 최소 HP,공격을 초기화
    Zombie()
        : Enemy("Zombie", 400, 600, 120, 200)
    {
        HealthPoint = MaxHealth;
    }
    // 소멸자
    virtual ~Zombie(){};
};

