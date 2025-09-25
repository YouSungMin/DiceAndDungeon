#include "GameManager.h"
#include "Trader.h"


void GameManager::GameStart()
{
	printf("Dice And Dungeon\n");
	printf("게임을 시작하려면 플레이어의 이름을 입력해주세요!\n");
	std::cin>>PlayerName;
	system("cls");
	PlayerStateReroll();
	Player GamePlayer(PlayerName, State[0],State[1],State[2]);
	DungeonStart();
}

void GameManager::PlayerStateReroll()
{
	int Reroll_Count = 3;

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
			std::cin>> PlayerChoice;
			if (PlayerChoice == 'y' || PlayerChoice == 'Y')
			{
				PlayerDiceRoll(DiceRollMaxCount);
				printf("캐릭터의 HP를 설정하는");
				PrintDiceResult();
				printf("x5 = %d 오릅니다.\n",static_cast<int>(ResultDiceSum*5.0f));
				State[0] = ResultDiceSum * 5.0f;
				PlayerDiceRoll(DiceRollMaxCount);
				printf("캐릭터의 공격력을 설정하는");
				PrintDiceResult();
				printf("이 오릅니다.\n");
				State[1] = ResultDiceSum;
				PlayerDiceRoll(DiceRollMaxCount);
				printf("캐릭터의 방어력을 설정하는");
				PrintDiceResult();
				printf("이 오릅니다.\n");
				State[2] = ResultDiceSum;
				break;
			}
		}

		if (Reroll_Count == 0)
		{
			printf("리롤 횟수를 모두 소진하여 현재 스탯으로 게임을 시작합니다.\n");
			Sleep(2000);
			break;
		}
		while(true)
		{
			printf("다시 스탯을 설정하시겠습니까? (Yes = Y,y/ No = N,n)입력\n");
			std::cin >> PlayerChoice;
			if (PlayerChoice == 'y' || PlayerChoice == 'Y')
			{
				Reroll_Count--;
				break;
			}
			if (PlayerChoice == 'n' || PlayerChoice == 'N')
			{
				Reroll_Count = -1;
				printf("현재 스탯으로 게임을 시작합니다.\n");
				Sleep(2000);
				break;
			}
		}
		system("cls");
	}
	system("cls");
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
			printf("%d 층 %d 번방 \n\n",y+1,x+1);
			switch (InDungeon.GetRoomType(x,y))
			{
			case RoomType::Empty:
				EmptyRoom();
				break;
			case RoomType::Healer:
				HealerEncounter();
				break;
			case RoomType::trap:
				TrapEncounter();
				break;
			case RoomType::trader:
				TraderEncounter();
				break;
			case RoomType::Enemy:
				EnemyEncounter();
				break;
			case RoomType::Boss:
				break;
			default:
				break;
			}
		}
	}
}

void GameManager::EnemyEncounter()
{
	printf("아무것도 없는 빈방입니다.\n");
	printf("다음 방으로 이동합니다.\n");
	Sleep(2000);
	system("cls");
	return;
}

void GameManager::HealerEncounter()
{
	printf("치유사를 만났습니다.\n");
	printf("치유를 받으려면 10골드가 필요하며 치유량은 주사위를 통해 정해집니다\n");
	printf("치유량은 최대 최력을 넘을 수 없습니다.\n");
	printf("골드가 충분하면 여러번 치유를 받을 수 있습니다.\n");
	if(GamePlayer.GetGold() < HealCost)
		printf("치유에 필요한 골드가 부족합니다.\n");
	while (GamePlayer.GetGold() >= HealCost)
	{
		printf("치유를 받으시겠습니까? (Yes = Y,y , No = N,n)\n");
		std::cin>> PlayerChoice;
		if (PlayerChoice == 'n' || PlayerChoice == 'N')
		{
			printf("치유를 거절하셨습니다.");
			break;
		}
		if (PlayerChoice == 'y' || PlayerChoice == 'Y')
		{
			printf("치유를 선택하셨습니다.\n");
			PlayerDiceRoll(DiceRollMaxCount);
			PrintDiceResult();
			printf("가 치유됩니다\n");
			GamePlayer.SetPlayerHealth(ResultDiceSum+(GamePlayer.GetHealthPoint()));
			printf("현재 체력 : %f\n",GamePlayer.GetHealthPoint());
			int i=0;
		}
	}
	NextRoom();
	return;
}

void GameManager::TraderEncounter()
{
	printf("상인을 만났습니다.\n");
	Trader trad;
	trad.GetStorList();
	printf("상점 목록\n");

	return;
}

void GameManager::TrapEncounter()
{
	int TrapActivate = 0;
	TrapActivate = rand() % 3 ;
	printf("아무것도 없는 빈방입니다.\n");
	if (TrapActivate == 0)
	{
		printf("함정이 발동하였습니다! HP가 감소합니다.\n");

	}
	return;
}

void GameManager::EmptyRoom()
{
	printf("아무것도 없는 빈방입니다.\n");
	NextRoom();
	return;
}

void GameManager::NextRoom()
{
	printf("다음 방으로 이동합니다.\n");
	Sleep(2000);
	system("cls");
}