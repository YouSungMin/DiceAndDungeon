#pragma once
#include "Enemy.h"
class Oak : public Enemy
{
    //Enemy�� ��ӹ��� OakŬ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
	virtual void UseSkill()override;

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    Oak()
        : Enemy("Oak", 800, 1000, 300, 400)
    {
        HealthPoint = MaxHealth;
    }
    // �Ҹ���
    virtual ~Oak() {};
};

