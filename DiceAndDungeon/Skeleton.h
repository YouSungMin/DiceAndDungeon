#pragma once
#include "Enemy.h"
class Skeleton : public Enemy
{
    //Enemy�� ��ӹ��� SkeletonŬ����
public:
    // ������ ��ų�� ���� �����Լ� ó��
	virtual void UseSkill()override;

    // �����ڸ� ���� �̸��� �ִ� �ּ� HP,������ �ʱ�ȭ
    Skeleton()
        : Enemy("Skeleton", 300, 500, 300, 350)
    {
        HealthPoint = MaxHealth;
    }

    // �Ҹ���
    virtual ~Skeleton(){};
};

