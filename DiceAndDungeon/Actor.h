#pragma once
#include <string>
class Actor
{
public:
	//기본 생성자
	Actor() = default;

	//기본 소멸자
	virtual ~Actor() = default;

	//이름을 파라미터로 받는 생성자 초기화까지
	Actor(const std::string& InName) : Name(InName) {}

	/// <summary>
	/// Target에게 공격하는 함수
	/// </summary>
	/// <param name="InTarget">공격 받는 대상</param>
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

	/// <summary>
	/// 데미지가 0이하인지 체크하는 함수
	/// </summary>
	/// <param name="InDamage">체크할 데미지</param>
	/// <returns>true면 0이하</returns>
	inline bool IsDamageZero(float InDamage)const{return InDamage < 0;}

	/// <summary>
	/// HealthPoint가 0 이하인지 체크하는 함수
	/// </summary>
	/// <returns>true면 0이하</returns>
	inline bool IsHealthPointZero(){return HealthPoint < 0;}

	/// <summary>
	/// 객체의 골드를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 골드</returns>
	inline int GetGold()const{return Gold;}

	/// <summary>
	/// 객체의 HealthPoint를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 HealthPoint</returns>
	inline float GetHealthPoint()const {return HealthPoint;}

	/// <summary>
	/// 객체의 MaxHealth를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 MaxHealth</returns>
	inline float GetMaxHealth()const { return MaxHealth; }

	/// <summary>
	/// 객체의 AttackPower를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 AttackPower</returns>
	inline float GetAttackPower()const {return AttackPower;}

	/// <summary>
	/// 객체의 OriginalAttackPower를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 OriginalAttackPower</returns>
	inline float GetOriginalAttackPower()const {return OriginalAttackPower;}

	/// <summary>
	/// 객체의 DefensivePower를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 DefensivePower</returns>
	inline float GetDefensivePower()const {return DefensivePower;}

	/// <summary>
	/// 객체의 CriticalPercent를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 CriticalPercent</returns>
	inline int GetCriticalPercent()const {return CriticalPercent;}

	/// <summary>
	/// 객체의 Name를 받아오는 Getter
	/// </summary>
	/// <returns>객체의 Name</returns>
	inline std::string GetName()const {return Name;}

protected:
	/// <summary>
	/// 객체의 CriticalPercent를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 CriticalPercent</param>
	inline void SetCriticalPercent(int InCriticalPercent)
	{
		CriticalPercent = InCriticalPercent;
	}

	/// <summary>
	/// 객체의 Gold를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 Gold</param>
	inline void SetGold(int InGold)
	{
		Gold = InGold;
	}

	/// <summary>
	/// 객체의 Health를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 Health</param>
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

	/// <summary>
	/// 객체의 AttackPower를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 AttackPower</param>
	inline void SetAttackPower(float InAttackPower)
	{
		AttackPower = InAttackPower;
	}

	/// <summary>
	/// 객체의 OriginalAttackPower를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 OriginalAttackPower</param>
	inline void SetOriginalAttackPower(float InOriginalAttackPower)
	{
		OriginalAttackPower = InOriginalAttackPower;
	}

	/// <summary>
	/// 객체의 MaxHealth를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 MaxHealth</param>
	inline void SetMaxHealth(float InMaxHealth)
	{
		MaxHealth = InMaxHealth;
	}

	/// <summary>
	/// 객체의 InCriticalPercent를 설정하는 Setter
	/// </summary>
	/// <param name="InCriticalPercent">설정할 InCriticalPercent</param>
	inline void SetDefensivePower(float InDefensivePower)
	{
		DefensivePower = InDefensivePower;
	}

	// 객체의 이름을 담을 변수
	std::string Name = "Actor";

	// 크리티컬 확률을 담은 변수
	int CriticalPercent = 5;

	// HP를 담은 변수
	float HealthPoint = 100.0f;

	// 공격력을 담은 변수
	float AttackPower = 10.0f;

	// 방어력을 담은 변수
	float DefensivePower = 5.0f;

	// 최대 체력을 담은 변수
	float MaxHealth = 100.0f;

	// 골드 양를 담은 변수
	int Gold = 10;

	//크리티컬이 터졌는지 확인하는 변수
	bool IsCritical = false;

	// 객체의 원래 공격력 
	//ex) 공격력 증가나 스킬 사용시 AttackPower을 조절하기에 사용 후 원래 공격력으로 초기화
	float OriginalAttackPower = 0.0f;
};

