#pragma once
#include "Boss.h"
class Demon : public Boss
{
    // Boss�� ��ӹ��� Demon Ŭ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
    virtual void UseSkill()override;

    // Enum Ŭ������ ���� ��ų ����
    enum class ESkill
    {
        Rage,
        ShadowFlame
    };

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    Demon()
        : Boss("Demon", 1300, 1300, 500, 500)
    {
        //HealthPoint �ʱ�ȭ
        HealthPoint = MaxHealth;

        // ��ų�� ����ϴ� Ȯ�� 33%�� �����ϰ� ����
        UseSkillPercent = 3;

        // ������ ���� �� ��� ��� ����
        Gold = 50;

        // Vector�� ���� ��ų���� ó��
        Skills.push_back(static_cast<ESkill>(ESkill::Rage));
        Skills.push_back(static_cast<ESkill>(ESkill::ShadowFlame));
    }
    // �Ҹ��� 
    virtual ~Demon() {};
private:
    // ��ų���� ���� vector 
    std::vector<ESkill> Skills;
};

