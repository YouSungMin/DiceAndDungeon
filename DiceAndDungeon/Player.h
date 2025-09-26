#pragma once
#include "Actor.h"
class Player : public Actor
{
public:
	Player() = default;
	// �÷��̾� ������ �ֻ����� ������ ���� ��ġ�� �߰��� �ʱ�ȭ
	Player(const std::string InName, float InHealth, float InAttackPower, float InDefensivePower)
	{
		Name = InName;
		HealthPoint += InHealth;
		//HealthPoint = 0.1f; //GameOver �׽�Ʈ
		MaxHealth = HealthPoint;
		AttackPower += InAttackPower;
		DefensivePower += InDefensivePower;
		OriginalAttackPower = AttackPower;
	}
	/// <summary>
	/// �÷��̾��� ����ü���� �ִ�ü������ Ȯ���ϴ� �Լ�
	/// </summary>
	/// <returns>true�� ���� ü���� �ִ� ü��</returns>
	bool IsHealthPointFull(){return HealthPoint == MaxHealth;}
public:
	// ���� Ŭ����(Actor)�� protected ����� ������ �ȵǼ� ���� Setter ��
	void SetPlayerHealth(float InHealth)
	{
		SetHealth(InHealth); 
	}
	void SetPlayerGold(int InGold)
	{
		SetGold(InGold);
	}
	void SetPlayerMaxHealth(int InMaxHealth)
	{
		SetMaxHealth(InMaxHealth);
	}
	void SetPlayerAttackPower(int InAttackPower)
	{
		SetAttackPower(InAttackPower);
	}
	void SetPlayerDefensivePower(int InDefensivePower)
	{
		SetDefensivePower(InDefensivePower);
	}
	void SetPlayerOriginalAttackPower(int InOriginalAttackPower)
	{
		SetOriginalAttackPower(InOriginalAttackPower);
	}
private:
};

