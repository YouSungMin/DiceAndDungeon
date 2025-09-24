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
				Roll_HealthPoint = ResultDiceRoll[3];
				PlayerDiceRoll(3);
				printf("ĳ������ ���ݷ��� �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				Roll_AttackPower = ResultDiceRoll[3];
				PlayerDiceRoll(3);
				printf("ĳ������ ������ �����ϴ�");
				PrintDiceResult();
				printf("�� �����ϴ�.\n");
				Roll_DefensivePower = ResultDiceRoll[3];
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
			printf("�ٽ� ������ �����Ͻðڽ��ϱ�? (Yes = Y,y/ No = X,x)�Է�\n");
			std::cin >> Choice;
			if (Choice == 'y' || Choice == 'Y')
			{
				Reroll_Count--;
				break;
			}
			if (Choice == 'x' || Choice == 'X')
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
	ResultDiceRoll[3] = 0.0f;
	for (int i = 0; i < DiceRollCount; i++)
	{
		ResultDiceRoll[i] = static_cast<float>(rand() % 6 + 1);
		ResultDiceRoll[3] += ResultDiceRoll[i];
	}
}

const void GameManager::PrintDiceResult() const
{
	printf("�ֻ����� %d , %d , %d �� ���� �� %d", static_cast<int>(ResultDiceRoll[0]), static_cast<int>(ResultDiceRoll[1]), static_cast<int>(ResultDiceRoll[2]), static_cast<int>(ResultDiceRoll[3]));
}