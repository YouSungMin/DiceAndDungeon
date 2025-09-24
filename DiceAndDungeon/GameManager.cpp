#include "GameManager.h"

void GameManager::GameStart()
{

	printf("Dice And Dungeon\n");
	printf("������ �����Ϸ��� �÷��̾��� �̸��� �Է����ּ���!\n");
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
		printf("�÷��̾��� HP, ���ݷ�, ������ �ֻ����� ���� �����մϴ�.\n");
		printf("HP�� �ֻ��� ���� x5 ������ �ö󰩴ϴ�.\n");
		printf("�ֻ����� ���� ������ ������ ���� ������ �ִ� 3������ �ٽ� ���� �� �� �ֽ��ϴ�.\n");
		printf("���� : �ٽ� ������ �ϰ� �Ǹ� ��� ������ �ٽ� �����մϴ�.\n\n");
		printf("���� ���� �缳�� Ƚ�� : %d\n",Reroll_Count);
		printf("�÷��̾��� ������ �����ϴ� �ֻ����� �����÷��� Y ��ư�̳� y ��ư�� �����ּ���\n");
		while(true)
		{ 
			std::cin>>Choice;
			if (Choice == 'y' || Choice == 'Y')
			{
				PlayerDiceRoll(3);
				printf("ĳ������ HP�� �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				Roll_HealthPoint = ResultDiceSum;
				PlayerDiceRoll(3);
				printf("ĳ������ ���ݷ��� �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				Roll_AttackPower = ResultDiceSum;
				PlayerDiceRoll(3);
				printf("ĳ������ ������ �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				Roll_DefensivePower = ResultDiceSum;
				break;
			}
		}

		if (Reroll_Count == 0)
		{
			printf("���� Ƚ���� ��� �����Ͽ� ���� �������� ������ �����մϴ�.\n");
			Sleep(2000);
			system("cls");
			break;
		}
		while(true)
		{
			printf("�ٽ� ������ �����Ͻðڽ��ϱ�? (Yes = Y,y/ No = N,n)�Է�\n");
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
	printf("�ֻ����� %d , %d , %d �� ���� �� %d", static_cast<int>(ResultDiceRoll[0]), static_cast<int>(ResultDiceRoll[1]), static_cast<int>(ResultDiceRoll[2]), static_cast<int>(ResultDiceSum));
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
