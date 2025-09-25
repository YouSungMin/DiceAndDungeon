#pragma once
#include <string>
class Actor
{
public:
	Actor() = default;
	
	/// <summary>
	/// Target���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="InTarget">���� �޴� ���</param>
	void Attack(Actor* InTarget);

	/// <summary>
	/// ������ ���ط���ũ ���ο��� ���ظ� ����
	/// </summary>
	/// <param name="InDamage">������ ���ط�</param>
	void TakeDamage(float InDamage);

	/// <summary>
	/// ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ������� </returns>
	inline bool IsAlive(){return HealthPoint > 0;}

	inline int GetGold(){return Gold;}
	inline float GetHealthPoint(){return HealthPoint;}

protected:
	inline void SetHealth(float InHealth)
	{
		if (InHealth > MaxHealth)
		{
			HealthPoint = MaxHealth;
		}
		else
		{
			HealthPoint = InHealth;
		}
	}
	std::string Name = "Actor";
	float HealthPoint = 100.0f;
	float AttackPower = 10.0f;
	float DefensivePower = 5.0f;
	float MaxHealth = 100.0f;
	int Gold = 10;

};

