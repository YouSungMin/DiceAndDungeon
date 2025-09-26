#pragma once
#include "Enemy.h"
class Slime : public Enemy
{
    //Enemy�� ��ӹ��� SlimeŬ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
	virtual void UseSkill()override;

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    Slime()
        : Enemy(" Slime", 200, 300, 200, 250)
    {
        HealthPoint = MaxHealth;
    }

    // �Ҹ���
    virtual ~Slime() {};
};

