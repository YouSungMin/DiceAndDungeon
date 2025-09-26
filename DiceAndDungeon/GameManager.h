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
	// 게임 매니저 소멸자
	~GameManager() {
		if (GamePlayer) {
			delete GamePlayer; // 메모리 할당 풀기
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

	/// <summary>
	/// 일반 몬스터를 만났을때 사용되는 함수
	/// </summary>
	void EnemyEncounter();

	/// <summary>
	/// 치유사를 만났을때 사용되는 함수
	/// </summary>
	void HealerEncounter();

	/// <summary>
	/// 상인을 만났을때 사용되는 함수
	/// </summary>
	void TraderEncounter();

	/// <summary>
	/// 함정방 구현에 사용된 함수
	/// </summary>
	void TrapEncounter();

	/// <summary>
	/// 아무것도 없는 방을 구현한 함수
	/// </summary>
	void EmptyRoom()const;

	/// <summary>
	/// 보스 방 구현 함수
	/// </summary>
	void BossRoom();

	/// <summary>
	/// 방이 완료되면 호출되는 함수
	/// </summary>
	void NextRoom()const;

	// 던전 방의 초기화가 잘되었는지 확인한 테스트 함수
	void DungeonTest();
	
	/// <summary>
	/// Enemy나 Boss를 만나게되면 호출되는 배틀을 구현한 함수
	/// </summary>
	/// <param name="InEnemy">동적으로 생성된 객체의 
	/// 메모리 관리를 자동으로 처리해주는 오른쪽 값 참조 사용</param>
	void StartBattle(std::unique_ptr<Enemy>&& InEnemy);

	/// <summary>
	/// 게임이 종료되면 호출되는 함수
	/// </summary>
	void GameEnd() const;

	/// <summary>
	/// 게임 종료 조건인 플레이어의 체력을 체크하는 함수
	/// </summary>
	/// <returns>true면 게임 오버 false면 게임 진행</returns>
	inline bool IsGameEnd() const{return GamePlayer->GetHealthPoint() < 0;}

	/// <summary>
	/// 플레이어의 상태창을 출력하는 함수
	/// </summary>
	void PrintPlayerState()const;


	void ProcessPurchaseLoop(Trader& trad);
	
private:
	// 주사위를 굴리는 이벤트가 발생 할 때 던지는 주사위 수
	static constexpr int DiceRollMaxCount = 3; 

	// 각각의 주사위 눈을 담을 배열의 최대 수
	static constexpr int RerollStateType = 3;

	// 일반 몬스터의 스폰 확률을 담은 변수, 등장하는 몬스터의 확률 다름
	static constexpr int EnemySpawnPercent = 9;

	// 보스 몬스터의 스폰 확률을 담은 변수, 보스 5개의 등장 확률 같음
	static constexpr int BossSpawnPercent = 5;

	// 치유사에게 힐을 받을 때 들어가는 골드
	static constexpr int HealCost = 10;

	// 층 클리어를 체크하기위한 변수 10번쨰 방 클리어 시 true로 바뀐다.
	bool IsFloorCleared = false;
	
	// 상인을 조우했을 때 구입을 멈추게 되면 사용할 bool타입 변수
	bool IsShopping = true;

	//y = 층 수 x = 층에 있는 방 수
	int x=0 ,y = 0; 

	// 플레이어의 이름을 담는 변수
	std::string PlayerName = ""; 

	// 주사위를 굴린 각각의 결과를 담는 변수
	float ResultDiceRoll[DiceRollMaxCount];
	
	// 주사위를 굴린 모든 결과를 더한 변수
	float ResultDiceSum = 0.0f;

	// 주사위 각각의 결과를 담은 배열
	float State[RerollStateType];

	// 캐릭터 스텟 설정이나 치유사의 치유 여부를 입력받는 변수
	char PlayerChoice = NULL;
	
	// 스탯을 설정하고 게임을 시작하기에 nullptr로 선언후 나중에 new 로 객체 생성
	Player* GamePlayer = nullptr;
};