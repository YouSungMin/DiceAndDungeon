#pragma once
#include "Enemy.h"
class Goblin : public Enemy
{
    //Enemy�� ��ӹ��� GoblinŬ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
    virtual void UseSkill()override;

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    Goblin()
        : Enemy("Goblin", 300, 400, 120, 180)
    {   //HealthPoint �ʱ�ȭ
        HealthPoint = MaxHealth;
    }
    // �Ҹ��� 
    virtual ~Goblin() {};
};

