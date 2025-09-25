#pragma once
#include <Windows.h>
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include "Dungeon.h"
class GameManager
{
public:
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

	void TraderStoreList();
	
private:
	static const int DiceRollMaxCount = 3;
	static const int RerollStateType = 3;
	std::string PlayerName = ""; // �÷��̾��� �̸��� ��� ����
	float ResultDiceRoll[DiceRollMaxCount]; // �ֻ����� ���� ������ ����� ��� ����
	float ResultDiceSum = 0.0f;// �ֻ����� ���� ��� ����� ���� ����
	float State[RerollStateType];
	char PlayerChoice = NULL;
	static const int HealCost = 10;

	Player GamePlayer;
};