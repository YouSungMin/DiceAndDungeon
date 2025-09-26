#pragma once
#include "Enemy.h"
#include <vector>
class Boss : public Enemy
{
    // Enemy�� ��ӹ޴� Boss Ŭ���� 
    // Boss���Ϳ� �Ϲ� ���͸� �����ϱ� ���� �߰��ٸ� ������ �ϴ� Ŭ����
public:
    // ������ ��ų ����� ���� �����Լ� ó���� �Լ�
    virtual void UseSkill()override;

    // �̸�, �ּ� , �ִ� HP�� ���ݷ��� �����Ͽ� �ִ�� �ּ� ������ ������ ������
    Boss(const std::string& InName, int InMinHealth, int InMaxHealth, int InMinAttack, int InMaxAttack);

    //�Ҹ���
    virtual ~Boss() {};
protected:
    // ��ӹ��� �������� ��ų ������ ���� ����
    static const int SkillCount = 2;
};

