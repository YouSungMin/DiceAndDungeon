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
	void GameStart(); // ���� ���� �Լ�

	/// <summary>
	/// ���� ���� �� �ֻ����� ���� ĳ������ MaxHealthPoint, AttackPower, DefensivePower�� ���� ����
	/// </summary>
	void PlayerStateReroll();

	/// <summary>
	/// �÷��̾ �ֻ����� ������ �Լ�
	/// </summary>
	/// <param name="DiceRollCount">�ֻ����� ������ Ƚ��</param>
	/// <returns>�ֻ��� ���� ��</returns>
	void PlayerDiceRoll(int DiceRollCount);

	/// <summary>
	/// �ֻ��� ����� ������ִ� �Լ�
	/// </summary>
	/// <returns></returns>
	const void PrintDiceResult()const;

	/// <summary>
	/// ���� ��ü�� �����ϰ� ������ �濡 ���� �ʱ�ȭ�� �̺�Ʈ���� ó��
	/// </summary>
	void DungeonStart();

	void EnemyEncounter();
	void HealerEncounter();
	void TraderEncounter();
	void TrapEncounter();
	void EmptyRoom();
	void BossRoom();

	void NextRoom();
	void DungeonTest(); // ���� ���� �ʱ�ȭ�� �ߵǾ����� Ȯ���� �׽�Ʈ �Լ�
	// ������ �� ����
	void StartBattle(std::unique_ptr<Enemy>&& InEnemy);
	void GameEnd() const;
	inline bool IsGameEnd() const{return GamePlayer->GetHealthPoint() < 0;}
	void TraderStoreList();
	void PrintPlayerState();
	
private:
	static const int DiceRollMaxCount = 3;
	static const int RerollStateType = 3;
	std::string PlayerName = ""; // �÷��̾��� �̸��� ��� ����
	float ResultDiceRoll[DiceRollMaxCount]; // �ֻ����� ���� ������ ����� ��� ����
	float ResultDiceSum = 0.0f;// �ֻ����� ���� ��� ����� ���� ����
	float State[RerollStateType];
	char PlayerChoice = NULL;
	static const int HealCost = 10;
	static const int EnemySpawnPercent = 9;

	Player* GamePlayer = nullptr;
};