#pragma once
#include "Boss.h"
#include "Enemy.h"
class GiantSlime : public Boss
{
    // Boss를 상속받은 GiantSlime 클래스
public:
    // 각각의 스킬을 위한 가상함수 처리
    virtual void UseSkill()override;

    // Enum 클래스를 통해 스킬 구분
    enum class ESkill
    {
        Heal,
        SplitBomb
    };

    // 생성자를 통해 이름과 최대 최소 HP,공격을 초기화
    GiantSlime()
        : Boss("GiantSlime", 2000, 2000, 300, 400)
    {
        //HealthPoint 초기화
        HealthPoint = MaxHealth;

        // 스킬을 사용하는 확률 33%를 생각하고 넣음
        UseSkillPercent = 3;

        // 보스를 잡을 시 얻는 골드 설정
        Gold = 50;

        // Vector를 통해 스킬갯수 처리
        Skills.push_back(static_cast<ESkill>(ESkill::Heal));
        Skills.push_back(static_cast<ESkill>(ESkill::SplitBomb));
    }
    // 소멸자 
    virtual ~GiantSlime() {};
private:
    // 스킬들을 담을 vector 
    std::vector<ESkill> Skills;

    // 회복 스킬을 사용할 때 사용될 회복 양을 담는 변수 
    static constexpr float HealingAmount = 40.0f;
};

