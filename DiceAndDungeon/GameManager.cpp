#include "GameManager.h"

void GameManager::GameStart()
{

	printf("Dice And Dungeon\n");
	printf("게임을 시작하려면 플레이어의 이름을 입력해주세요!\n");
	std::cin>>PlayerName;
	system("cls");
	PlayerStateReroll();

}

void GameManager::PlayerStateReroll()
{
	int Reroll_Count = 3;
	float Roll_HealthPoint = 0;
	float Roll_AttackPower = 0;
	float Roll_DefensivePower = 0;
	char Choice = NULL;

	while (Reroll_Count >= 0)
	{
		printf("플레이어의 HP, 공격력, 방어력을 주사위를 굴려 설정합니다.\n");
		printf("HP는 주사위 눈의 x5 배율로 올라갑니다.\n");
		printf("주사위를 굴린 스탯이 마음에 들지 않으면 최대 3번까지 다시 설정 할 수 있습니다.\n");
		printf("주의 : 다시 설정을 하게 되면 모든 스탯을 다시 설정합니다.\n\n");
		printf("현재 남은 재설정 횟수 : %d\n",Reroll_Count);
		printf("플레이어의 스탯을 설정하는 주사위를 굴리시려면 Y 버튼이나 y 버튼을 눌려주세요\n");
		while(true)
		{ 
			std::cin>>Choice;
			if (Choice == 'y' || Choice == 'Y')
			{
				PlayerDiceRoll(3);
				printf("캐릭터의 HP를 설정하는");
				PrintDiceResult();
				printf("가 오릅니다.\n");
				Roll_HealthPoint = ResultDiceSum;
				PlayerDiceRoll(3);
				printf("캐릭터의 공격력을 설정하는");
				PrintDiceResult();
				printf("가 오릅니다.\n");
				Roll_AttackPower = ResultDiceSum;
				PlayerDiceRoll(3);
				printf("캐릭터의 방어력을 설정하는");
				PrintDiceResult();
				printf("가 오릅니다.\n");
				Roll_DefensivePower = ResultDiceSum;
				break;
			}
		}

		if (Reroll_Count == 0)
		{
			printf("리롤 횟수를 모두 소진하여 현재 스탯으로 게임을 시작합니다.\n");
			Sleep(2000);
			system("cls");
			break;
		}
		while(true)
		{
			printf("다시 스탯을 설정하시겠습니까? (Yes = Y,y/ No = N,n)입력\n");
			std::cin >> Choice;
			if (Choice == 'y' || Choice == 'Y')
			{
				Reroll_Count--;
				break;
			}
			if (Choice == 'n' || Choice == 'N')
			{
				Reroll_Count = -1;
				break;
			}
		}
		system("cls");
	}
	Player GamePlayer(PlayerName, Roll_HealthPoint, Roll_AttackPower, Roll_DefensivePower);
}

void GameManager::DungeonTest()
{
	Dungeon TestDungeon;
}

void GameManager::PlayerDiceRoll(int DiceRollCount)
{	
	ResultDiceSum = 0.0f;
	for (int i = 0; i < DiceRollCount; i++)
	{
		ResultDiceRoll[i] = static_cast<float>(rand() % 6 + 1);
		ResultDiceSum += ResultDiceRoll[i];
	}
}

const void GameManager::PrintDiceResult() const
{
	printf("주사위는 %d , %d , %d 가 나와 총 %d", static_cast<int>(ResultDiceRoll[0]), static_cast<int>(ResultDiceRoll[1]), static_cast<int>(ResultDiceRoll[2]), static_cast<int>(ResultDiceSum));
}

void GameManager::DungeonStart()
{
	Dungeon InDungeon;

	for (int y = 0; y < InDungeon.DungeonSize; y++)
	{
		for (int x = 0; x < InDungeon.DungeonSize; x++)
		{
			
		}
	}
}
