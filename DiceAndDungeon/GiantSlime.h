#pragma once
#include "Boss.h"
#include "Enemy.h"
class GiantSlime : public Boss
{
    // Boss�� ��ӹ��� GiantSlime Ŭ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
    virtual void UseSkill()override;

    // Enum Ŭ������ ���� ��ų ����
    enum class ESkill
    {
        Heal,
        SplitBomb
    };

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    GiantSlime()
        : Boss("GiantSlime", 2000, 2000, 300, 400)
    {
        //HealthPoint �ʱ�ȭ
        HealthPoint = MaxHealth;

        // ��ų�� ����ϴ� Ȯ�� 33%�� �����ϰ� ����
        UseSkillPercent = 3;

        // ������ ���� �� ��� ��� ����
        Gold = 50;

        // Vector�� ���� ��ų���� ó��
        Skills.push_back(static_cast<ESkill>(ESkill::Heal));
        Skills.push_back(static_cast<ESkill>(ESkill::SplitBomb));
    }
    // �Ҹ��� 
    virtual ~GiantSlime() {};
private:
    // ��ų���� ���� vector 
    std::vector<ESkill> Skills;

    // ȸ�� ��ų�� ����� �� ���� ȸ�� ���� ��� ���� 
    static constexpr float HealingAmount = 40.0f;
};

