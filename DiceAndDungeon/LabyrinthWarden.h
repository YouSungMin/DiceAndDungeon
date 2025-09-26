#pragma once
#pragma once
#include "Boss.h"
#include "Enemy.h"
class LabyrinthWarden : public Boss
{
    // Boss를 상속받은 LabyrinthWarden 클래스
public:
    // 각각의 스킬을 위한 가상함수 처리
    virtual void UseSkill()override;

    // Enum 클래스를 통해 스킬 구분
    enum class ESkill
    {
        CrushingBlow,
        Earthquake
    };

    // 생성자를 통해 이름과 최대 최소 HP,공격을 초기화
    LabyrinthWarden()
        : Boss("LabyrinthWarden", 1500, 1500, 400, 500)
    {
        //HealthPoint 초기화
        HealthPoint = MaxHealth;

        // 스킬을 사용하는 확률 33%를 생각하고 넣음
        UseSkillPercent = 3;

        // 보스를 잡을 시 얻는 골드 설정
        Gold = 50;

        // Vector를 통해 스킬갯수 처리
        Skills.push_back(static_cast<ESkill>(ESkill::CrushingBlow));
        Skills.push_back(static_cast<ESkill>(ESkill::Earthquake));
    }
    // 소멸자 
    virtual ~LabyrinthWarden() {};

private:
    // 스킬들을 담을 vector 
    std::vector<ESkill> Skills;
};
