#pragma once
#pragma once
#include "Boss.h"
#include "Enemy.h"
class LabyrinthWarden : public Boss
{
    // Boss�� ��ӹ��� LabyrinthWarden Ŭ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
    virtual void UseSkill()override;

    // Enum Ŭ������ ���� ��ų ����
    enum class ESkill
    {
        CrushingBlow,
        Earthquake
    };

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    LabyrinthWarden()
        : Boss("LabyrinthWarden", 1500, 1500, 400, 500)
    {
        //HealthPoint �ʱ�ȭ
        HealthPoint = MaxHealth;

        // ��ų�� ����ϴ� Ȯ�� 33%�� �����ϰ� ����
        UseSkillPercent = 3;

        // ������ ���� �� ��� ��� ����
        Gold = 50;

        // Vector�� ���� ��ų���� ó��
        Skills.push_back(static_cast<ESkill>(ESkill::CrushingBlow));
        Skills.push_back(static_cast<ESkill>(ESkill::Earthquake));
    }
    // �Ҹ��� 
    virtual ~LabyrinthWarden() {};

private:
    // ��ų���� ���� vector 
    std::vector<ESkill> Skills;
};
