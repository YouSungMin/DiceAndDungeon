#pragma once
#include "Boss.h"
#include "Enemy.h"
class LavaGiant : public Boss
{
    // Boss�� ��ӹ��� LavaGiant Ŭ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
    virtual void UseSkill()override;

    // Enum Ŭ������ ���� ��ų ����
    enum class ESkill
    {
        LavaEruption,
        Earthquake
    };

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    LavaGiant()
        : Boss("LavaGiant", 1800, 1800, 400, 400)
    {
        //HealthPoint �ʱ�ȭ
        HealthPoint = MaxHealth;

        // ��ų�� ����ϴ� Ȯ�� 33%�� �����ϰ� ����
        UseSkillPercent = 3;

        // ������ ���� �� ��� ��� ����
        Gold = 50;

        // Vector�� ���� ��ų���� ó��
        Skills.push_back(static_cast<ESkill>(ESkill::LavaEruption));
        Skills.push_back(static_cast<ESkill>(ESkill::Earthquake));
    }

    // �Ҹ��� 
    virtual ~LavaGiant() {};
private:
    // ��ų���� ���� vector
    std::vector<ESkill> Skills;
};

