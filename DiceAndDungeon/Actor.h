#pragma once
#include <string>
class Actor
{
public:
	Actor() = default;
	Actor(const std::string& InName) : Name(InName) {}
	/// <summary>
	/// Target에게 공격하는 함수
	/// </summary>
	/// <param name="InTarget">공격 받는 대상</param>
	virtual ~Actor() = default;
	void Attack(Actor* InTarget, float PlusDiceDamage);
	/// <summary>
	/// 지정된 피해량만크 본인에게 피해를 적용
	/// </summary>
	/// <param name="InDamage">적용할 피해량</param>
	void TakeDamage(float InDamage);

	/// <summary>
	/// 생존 여부를 알려주는 함수
	/// </summary>
	/// <returns>true면 살아있음 </returns>
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

