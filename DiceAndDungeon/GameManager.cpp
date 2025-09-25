#include "GameManager.h"
#include "Trader.h"


void GameManager::GameStart()
{
	printf("Dice And Dungeon\n");
	printf("������ �����Ϸ��� �÷��̾��� �̸��� �Է����ּ���!\n");
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
		printf("�÷��̾��� HP, ���ݷ�, ������ �ֻ����� ���� �����մϴ�.\n");
		printf("HP�� �ֻ��� ���� x5 ������ �ö󰩴ϴ�.\n");
		printf("�ֻ����� ���� ������ ������ ���� ������ �ִ� 3������ �ٽ� ���� �� �� �ֽ��ϴ�.\n");
		printf("���� : �ٽ� ������ �ϰ� �Ǹ� ��� ������ �ٽ� �����մϴ�.\n\n");
		printf("���� ���� �缳�� Ƚ�� : %d\n",Reroll_Count);
		printf("�÷��̾��� ������ �����ϴ� �ֻ����� �����÷��� Y ��ư�̳� y ��ư�� �����ּ���\n");
		while(true)
		{ 
			std::cin>> PlayerChoice;
			if (PlayerChoice == 'y' || PlayerChoice == 'Y')
			{
				PlayerDiceRoll(DiceRollMaxCount);
				printf("ĳ������ HP�� �����ϴ�");
				PrintDiceResult();
				printf("x5 = %d �����ϴ�.\n",static_cast<int>(ResultDiceSum*5.0f));
				State[0] = ResultDiceSum * 5.0f;
				PlayerDiceRoll(DiceRollMaxCount);
				printf("ĳ������ ���ݷ��� �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				State[1] = ResultDiceSum;
				PlayerDiceRoll(DiceRollMaxCount);
				printf("ĳ������ ������ �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				State[2] = ResultDiceSum;
				break;
			}
		}

		if (Reroll_Count == 0)
		{
			printf("���� Ƚ���� ��� �����Ͽ� ���� �������� ������ �����մϴ�.\n");
			Sleep(2000);
			break;
		}
		while(true)
		{
			printf("�ٽ� ������ �����Ͻðڽ��ϱ�? (Yes = Y,y/ No = N,n)�Է�\n");
			std::cin >> PlayerChoice;
			if (PlayerChoice == 'y' || PlayerChoice == 'Y')
			{
				Reroll_Count--;
				break;
			}
			if (PlayerChoice == 'n' || PlayerChoice == 'N')
			{
				Reroll_Count = -1;
				printf("���� �������� ������ �����մϴ�.\n");
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
	printf("�ֻ����� %d , %d , %d �� ���� �� %d", static_cast<int>(ResultDiceRoll[0]), static_cast<int>(ResultDiceRoll[1]), static_cast<int>(ResultDiceRoll[2]), static_cast<int>(ResultDiceSum));
}

void GameManager::DungeonStart()
{
	Dungeon InDungeon;

	for (int y = 0; y < InDungeon.DungeonSize; y++)
	{
		for (int x = 0; x < InDungeon.DungeonSize; x++)
		{
			printf("%d �� %d ���� \n\n",y+1,x+1);
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
	printf("�ƹ��͵� ���� ����Դϴ�.\n");
	printf("���� ������ �̵��մϴ�.\n");
	Sleep(2000);
	system("cls");
	return;
}

void GameManager::HealerEncounter()
{
	printf("ġ���縦 �������ϴ�.\n");
	printf("ġ���� �������� 10��尡 �ʿ��ϸ� ġ������ �ֻ����� ���� �������ϴ�\n");
	printf("ġ������ �ִ� �ַ��� ���� �� �����ϴ�.\n");
	printf("��尡 ����ϸ� ������ ġ���� ���� �� �ֽ��ϴ�.\n");
	if(GamePlayer.GetGold() < HealCost)
		printf("ġ���� �ʿ��� ��尡 �����մϴ�.\n");
	while (GamePlayer.GetGold() >= HealCost)
	{
		printf("ġ���� �����ðڽ��ϱ�? (Yes = Y,y , No = N,n)\n");
		std::cin>> PlayerChoice;
		if (PlayerChoice == 'n' || PlayerChoice == 'N')
		{
			printf("ġ���� �����ϼ̽��ϴ�.");
			break;
		}
		if (PlayerChoice == 'y' || PlayerChoice == 'Y')
		{
			printf("ġ���� �����ϼ̽��ϴ�.\n");
			PlayerDiceRoll(DiceRollMaxCount);
			PrintDiceResult();
			printf("�� ġ���˴ϴ�\n");
			GamePlayer.SetPlayerHealth(ResultDiceSum+(GamePlayer.GetHealthPoint()));
			printf("���� ü�� : %f\n",GamePlayer.GetHealthPoint());
			int i=0;
		}
	}
	NextRoom();
	return;
}

void GameManager::TraderEncounter()
{
	printf("������ �������ϴ�.\n");
	Trader trad;
	trad.GetStorList();
	printf("���� ���\n");

	return;
}

void GameManager::TrapEncounter()
{
	int TrapActivate = 0;
	TrapActivate = rand() % 3 ;
	printf("�ƹ��͵� ���� ����Դϴ�.\n");
	if (TrapActivate == 0)
	{
		printf("������ �ߵ��Ͽ����ϴ�! HP�� �����մϴ�.\n");

	}
	return;
}

void GameManager::EmptyRoom()
{
	printf("�ƹ��͵� ���� ����Դϴ�.\n");
	NextRoom();
	return;
}

void GameManager::NextRoom()
{
	printf("���� ������ �̵��մϴ�.\n");
	Sleep(2000);
	system("cls");
}