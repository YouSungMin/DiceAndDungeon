#pragma once
#include "Actor.h"
class Player : public Actor
{
public:
	Player() = default;
	// 플레이어 생성자 주사위를 굴려서 얻은 수치를 추가해 초기화
	Player(const std::string InName, float InHealth, float InAttackPower, float InDefensivePower)
	{
		Name = InName;
		HealthPoint += InHealth;
		//HealthPoint = 0.1f; //GameOver 테스트
		MaxHealth = HealthPoint;
		AttackPower += InAttackPower;
		DefensivePower += InDefensivePower;
		OriginalAttackPower = AttackPower;
	}
	/// <summary>
	/// 플레이어의 현재체력이 최대체력인지 확인하는 함수
	/// </summary>
	/// <returns>true면 현재 체력이 최대 체력</returns>
	bool IsHealthPointFull(){return HealthPoint == MaxHealth;}
public:
	// 상위 클래스(Actor)의 protected 멤버에 접근이 안되서 만든 Setter 들
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

