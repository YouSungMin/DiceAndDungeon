#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
    //Enemy를 상속받은 Goblin클래스
public:
    // 각각의 스킬을 위한 가상함수 처리
    virtual void UseSkill()override;

    // 생성자를 통해 이름과 최대 최소 HP,공격을 초기화
    Goblin()
        : Enemy("Goblin", 300, 400, 120, 180)
    {   //HealthPoint 초기화
        HealthPoint = MaxHealth;
    }
    // 소멸자 
    virtual ~Goblin() {};
};

