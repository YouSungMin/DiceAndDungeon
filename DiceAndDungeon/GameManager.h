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
	// ���� �Ŵ��� �Ҹ���
	~GameManager() {
		if (GamePlayer) {
			delete GamePlayer; // �޸� �Ҵ� Ǯ��
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

	/// <summary>
	/// �Ϲ� ���͸� �������� ���Ǵ� �Լ�
	/// </summary>
	void EnemyEncounter();

	/// <summary>
	/// ġ���縦 �������� ���Ǵ� �Լ�
	/// </summary>
	void HealerEncounter();

	/// <summary>
	/// ������ �������� ���Ǵ� �Լ�
	/// </summary>
	void TraderEncounter();

	/// <summary>
	/// ������ ������ ���� �Լ�
	/// </summary>
	void TrapEncounter();

	/// <summary>
	/// �ƹ��͵� ���� ���� ������ �Լ�
	/// </summary>
	void EmptyRoom()const;

	/// <summary>
	/// ���� �� ���� �Լ�
	/// </summary>
	void BossRoom();

	/// <summary>
	/// ���� �Ϸ�Ǹ� ȣ��Ǵ� �Լ�
	/// </summary>
	void NextRoom()const;

	// ���� ���� �ʱ�ȭ�� �ߵǾ����� Ȯ���� �׽�Ʈ �Լ�
	void DungeonTest();
	
	/// <summary>
	/// Enemy�� Boss�� �����ԵǸ� ȣ��Ǵ� ��Ʋ�� ������ �Լ�
	/// </summary>
	/// <param name="InEnemy">�������� ������ ��ü�� 
	/// �޸� ������ �ڵ����� ó�����ִ� ������ �� ���� ���</param>
	void StartBattle(std::unique_ptr<Enemy>&& InEnemy);

	/// <summary>
	/// ������ ����Ǹ� ȣ��Ǵ� �Լ�
	/// </summary>
	void GameEnd() const;

	/// <summary>
	/// ���� ���� ������ �÷��̾��� ü���� üũ�ϴ� �Լ�
	/// </summary>
	/// <returns>true�� ���� ���� false�� ���� ����</returns>
	inline bool IsGameEnd() const{return GamePlayer->GetHealthPoint() < 0;}

	/// <summary>
	/// �÷��̾��� ����â�� ����ϴ� �Լ�
	/// </summary>
	void PrintPlayerState()const;


	void ProcessPurchaseLoop(Trader& trad);
	
private:
	// �ֻ����� ������ �̺�Ʈ�� �߻� �� �� ������ �ֻ��� ��
	static constexpr int DiceRollMaxCount = 3; 

	// ������ �ֻ��� ���� ���� �迭�� �ִ� ��
	static constexpr int RerollStateType = 3;

	// �Ϲ� ������ ���� Ȯ���� ���� ����, �����ϴ� ������ Ȯ�� �ٸ�
	static constexpr int EnemySpawnPercent = 9;

	// ���� ������ ���� Ȯ���� ���� ����, ���� 5���� ���� Ȯ�� ����
	static constexpr int BossSpawnPercent = 5;

	// ġ���翡�� ���� ���� �� ���� ���
	static constexpr int HealCost = 10;

	// �� Ŭ��� üũ�ϱ����� ���� 10���� �� Ŭ���� �� true�� �ٲ��.
	bool IsFloorCleared = false;
	
	// ������ �������� �� ������ ���߰� �Ǹ� ����� boolŸ�� ����
	bool IsShopping = true;

	//y = �� �� x = ���� �ִ� �� ��
	int x=0 ,y = 0; 

	// �÷��̾��� �̸��� ��� ����
	std::string PlayerName = ""; 

	// �ֻ����� ���� ������ ����� ��� ����
	float ResultDiceRoll[DiceRollMaxCount];
	
	// �ֻ����� ���� ��� ����� ���� ����
	float ResultDiceSum = 0.0f;

	// �ֻ��� ������ ����� ���� �迭
	float State[RerollStateType];

	// ĳ���� ���� �����̳� ġ������ ġ�� ���θ� �Է¹޴� ����
	char PlayerChoice = NULL;
	
	// ������ �����ϰ� ������ �����ϱ⿡ nullptr�� ������ ���߿� new �� ��ü ����
	Player* GamePlayer = nullptr;
};