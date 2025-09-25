#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Dungeon.h"
#include "Trader.h"
#include "Enemy.h"

class GameManager
{
public:
	~GameManager() {
		if (GamePlayer) {
			delete GamePlayer;
		}
	}
	void GameStart(); // 게임 시작 함수

	/// <summary>
	/// 게임 시작 후 주사위를 굴려 캐릭터의 MaxHealthPoint, AttackPower, DefensivePower를 정할 예정
	/// </summary>
	void PlayerStateReroll();

	/// <summary>
	/// 플레이어가 주사위를 굴리는 함수
	/// </summary>
	/// <param name="DiceRollCount">주사위를 굴리는 횟수</param>
	/// <returns>주사위 눈의 합</returns>
	void PlayerDiceRoll(int DiceRollCount);

	/// <summary>
	/// 주사위 결과를 출력해주는 함수
	/// </summary>
	/// <returns></returns>
	const void PrintDiceResult()const;

	/// <summary>
	/// 던전 객체를 생성하고 던전의 방에 각각 초기화된 이벤트들을 처리
	/// </summary>
	void DungeonStart();

	void EnemyEncounter();
	void HealerEncounter();
	void TraderEncounter();
	void TrapEncounter();
	void EmptyRoom();
	void BossRoom();

	void NextRoom();
	void DungeonTest(); // 던전 방의 초기화가 잘되었는지 확인한 테스트 함수
	// 오른쪽 값 참조
	void StartBattle(std::unique_ptr<Enemy>&& InEnemy);
	void GameEnd() const;
	inline bool IsGameEnd() const{return GamePlayer->GetHealthPoint() < 0;}
	void TraderStoreList();
	void PrintPlayerState();
	
private:
	static const int DiceRollMaxCount = 3;
	static const int RerollStateType = 3;
	std::string PlayerName = ""; // 플레이어의 이름을 담는 변수
	float ResultDiceRoll[DiceRollMaxCount]; // 주사위를 굴린 각각의 결과를 담는 변수
	float ResultDiceSum = 0.0f;// 주사위를 굴린 모든 결과를 더한 변수
	float State[RerollStateType];
	char PlayerChoice = NULL;
	static const int HealCost = 10;
	static const int EnemySpawnPercent = 9;

	Player* GamePlayer = nullptr;
};