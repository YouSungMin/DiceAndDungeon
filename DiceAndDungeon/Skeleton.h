#pragma once
#include "Enemy.h"
class Skeleton : public Enemy
{
    //Enemy를 상속받은 Skeleton클래스
public:
    // 각각의 스킬을 위한 가상함수 처리
	virtual void UseSkill()override;

    // 생성자를 통해 이름과 최대 최소 HP,공격을 초기화
    Skeleton()
        : Enemy("Skeleton", 300, 500, 300, 350)
    {
        HealthPoint = MaxHealth;
    }

    // 소멸자
    virtual ~Skeleton(){};
};

