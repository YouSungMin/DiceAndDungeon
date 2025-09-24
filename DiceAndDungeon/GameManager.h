#pragma once
#include <Windows.h>
#include "Player.h"
#include <iostream>
#include <cstdlib>
#include "Dungeon.h"
class GameManager
{
public:
	void GameStart(); // 게임 시작 함수
	void PlayerStateReroll(); // 게임 시작 후 주사위를 굴려 캐릭터의 MaxHealthPoint, AttackPower, DefensivePower를 정할 예정
	void DungeonTest(); // 던전 방의 초기화가 잘되었는지 확인한 테스트 함수
	
	/// <summary>
	/// 플레이어가 주사위를 굴리는 함수
	/// </summary>
	/// <param name="DiceRollCount">주사위를 굴리는 횟수</param>
	/// <returns>주사위 눈의 합</returns>
	void PlayerDiceRoll(int DiceRollCount);

	const void PrintDiceResult()const;
private:
	std::string PlayerName = "";
	float ResultDiceRoll[4] = {0.0f};
};

