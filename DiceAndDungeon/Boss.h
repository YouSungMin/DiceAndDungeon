#pragma once
#include "Enemy.h"
#include <vector>
class Boss : public Enemy
{
    // Enemy를 상속받는 Boss 클래스 
    // Boss몬스터와 일반 몬스터를 구분하기 위해 중간다리 역할을 하는 클래스
public:
    // 각각의 스킬 사용을 위해 가상함수 처리한 함수
    virtual void UseSkill()override;

    // 이름, 최소 , 최대 HP와 공격력을 설정하여 최대와 최소 사이의 난수로 생성됨
    Boss(const std::string& InName, int InMinHealth, int InMaxHealth, int InMinAttack, int InMaxAttack);

    //소멸자
    virtual ~Boss() {};
protected:
    // 상속받을 보스들의 스킬 갯수를 넣은 변수
    static const int SkillCount = 2;
};

