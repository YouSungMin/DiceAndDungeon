#pragma once
#include <string>
class Actor
{
public:
	Actor() = default;
	
	/// <summary>
	/// Target에게 공격하는 함수
	/// </summary>
	/// <param name="InTarget">공격 받는 대상</param>
	void Attack(Actor* InTarget);

	/// <summary>
	/// 지정된 피해량만크 본인에게 피해를 적용
	/// </summary>
	/// <param name="InDamage">적용할 피해량</param>
	void TakeDamage(float InDamage);

	/// <summary>
	/// 생존 여부를 알려주는 함수
	/// </summary>
	/// <returns>true면 살아있음 </returns>
	inline bool IsAlive(){return HealthPoint > 0;}

protected:
	std::string Name = "Actor";
	float HealthPoint = 100.0f;
	float AttackPower = 10.0f;
	float DefensivePower = 5.0f;
	float MaxHealth = 100.0f;
	int Gold = 0;

};

