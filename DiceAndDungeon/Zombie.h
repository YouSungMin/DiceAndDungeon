#pragma once
#include "Enemy.h"
class Zombie : public Enemy
{
    //Enemy�� ��ӹ��� ZombieŬ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
	virtual void UseSkill()override;

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    Zombie()
        : Enemy("Zombie", 400, 600, 120, 200)
    {
        HealthPoint = MaxHealth;
    }
    // �Ҹ���
    virtual ~Zombie(){};
};

