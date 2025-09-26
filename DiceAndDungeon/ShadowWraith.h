#pragma once
#include "Boss.h"
#include "Enemy.h"
class ShadowWraith : public Boss
{
    // Boss�� ��ӹ��� ShadowWraith Ŭ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
    virtual void UseSkill()override;

    // Enum Ŭ������ ���� ��ų ����
    enum class ESkill
    {
        ShadowCloak,
        ShadowStrike
    };

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    ShadowWraith()
        : Boss("ShadowWraith", 1000, 1000, 600, 600)
    {
        //HealthPoint �ʱ�ȭ
        HealthPoint = MaxHealth;

        // ��ų�� ����ϴ� Ȯ�� 33%�� �����ϰ� ����
        UseSkillPercent = 3;

        // ������ ���� �� ��� ��� ����
        Gold = 50;

        // Vector�� ���� ��ų���� ó��
        Skills.push_back(static_cast<ESkill>(ESkill::ShadowCloak));
        Skills.push_back(static_cast<ESkill>(ESkill::ShadowStrike));
    }
    // �Ҹ��� 
    virtual ~ShadowWraith() {};
private:
    // ��ų���� ���� vector 
    std::vector<ESkill> Skills;

    // ȸ�� ��ų�� ����� �� ���� ȸ�� ���� ��� ���� 
    static constexpr float HealingAmount = 20.0f;
};

