#pragma once
#include <string>
class Actor
{
public:
	Actor() = default;
	Actor(const std::string& InName) : Name(InName) {}
	/// <summary>
	/// Target���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="InTarget">���� �޴� ���</param>
	virtual ~Actor() = default;
	void Attack(Actor* InTarget, float PlusDiceDamage);
	/// <summary>
	/// ������ ���ط���ũ ���ο��� ���ظ� ����
	/// </summary>
	/// <param name="InDamage">������ ���ط�</param>
	void TakeDamage(float InDamage);

	/// <summary>
	/// ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ������� </returns>
	inline bool IsAlive()const {return HealthPoint > 0;}
	inline bool IsDamageZero(float InDamage)const{return InDamage < 0;}
	inline bool IsHealthPointZero(){return HealthPoint < 0;}

	inline int GetGold()const{return Gold;}
	inline float GetHealthPoint()const {return HealthPoint;}
	inline float GetMaxHealth()const { return MaxHealth; }
	inline float GetAttackPower()const {return AttackPower;}
	inline float GetDefensivePowert()const {return DefensivePower;}
	inline std::string GetName()const {return Name;}

protected:
	inline void SetGold(int InGold)
	{
		Gold = InGold;
	}
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

