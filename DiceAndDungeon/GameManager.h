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
	void PlayerStateReroll(); // ���� ���� �� �ֻ����� ���� ĳ������ MaxHealthPoint, AttackPower, DefensivePower�� ���� ����
	void DungeonTest(); // ���� ���� �ʱ�ȭ�� �ߵǾ����� Ȯ���� �׽�Ʈ �Լ�
	
	/// <summary>
	/// �÷��̾ �ֻ����� ������ �Լ�
	/// </summary>
	/// <param name="DiceRollCount">�ֻ����� ������ Ƚ��</param>
	/// <returns>�ֻ��� ���� ��</returns>
	void PlayerDiceRoll(int DiceRollCount);

	const void PrintDiceResult()const;
private:
	std::string PlayerName = "";
	float ResultDiceRoll[4] = {0.0f};
};

