#include "GameManager.h"
#include "Zombie.h"
#include "Skeleton.h"
#include "Oak.h"
#include "Slime.h"
#include "Goblin.h"
#include "GiantSlime.h"
#include "Demon.h"
#include "ShadowWraith.h"
#include "LavaGiant.h"
#include "LabyrinthWarden.h"
#include <memory>

void GameManager::GameStart()
{
	printf("==========================================================\n");
	printf("||                                                      ||\n");
	printf("||          +----+                                      ||\n");
	printf("||         /    /|                                      ||\n");
	printf("||        +----+ |  <-- ������ �ֻ����� �������ϴ�!     ||\n");
	printf("||        |    | +                                      ||\n");
	printf("||        |    |/                                       ||\n");
	printf("||        +----+                                        ||\n");
	printf("||                                                      ||\n");
	printf("||      ============================================    ||\n");
	printf("||      ||                                        ||    ||\n");
	printf("||      ||   D I C E   A N D   D U N G E O N      ||    ||\n");
	printf("||      ||                                        ||    ||\n");
	printf("||      ============================================    ||\n");
	printf("||                                                      ||\n");
	printf("==========================================================\n");
	printf("\nȯ���մϴ�! ������ ������ ����� �̸��� �Է����ּ���: ");
	std::cin>>PlayerName;
	system("cls");
	PlayerStateReroll();
	GamePlayer = new Player(PlayerName, State[0],State[1],State[2]);
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
	GamePlayer = new Player("aaa", 5.0f, 5.0f, 5.0f);
	TraderEncounter();
	int i = 0;
	delete GamePlayer;
}

void GameManager::StartBattle(std::unique_ptr<Enemy>&& InEnemy)
{
	while (GamePlayer->IsAlive() && InEnemy->IsAlive())
	{
		printf("���� �ֻ����� ����!!\n");
		PlayerDiceRoll(DiceRollMaxCount);
		PrintDiceResult();
		printf("�� �߰� ���ݷ��� ����ϴ�.\n");
		printf("�÷��̾��� ����!\n");
		Sleep(1000);
		GamePlayer->Attack(InEnemy.get(),ResultDiceSum);
		if(!InEnemy->IsAlive())
		{
			GamePlayer->SetPlayerGold(GamePlayer->GetGold()+InEnemy->GetGold());
			break;
		}
		printf("��� �ֻ����� ����!!\n");
		PlayerDiceRoll(DiceRollMaxCount);
		PrintDiceResult();
		printf("�� �߰� ������ ����ϴ�.\n");
		printf("%s�� ����!\n", (InEnemy->GetName()).c_str());
		if (rand() % InEnemy->GetUseSkillPercent() == 0)
		{
			InEnemy->UseSkill();
		}
		Sleep(1000);
		InEnemy->Attack(GamePlayer,ResultDiceSum);
		Sleep(2000);
		system("cls");
		PrintPlayerState();
	}
	
}

void GameManager::GameEnd() const
{
	if (GamePlayer->IsAlive())
	{
		printf("�����մϴ�! ������ �����ϼ̽��ϴ�.!!!!\n");
		exit(0);
	}
	else
	{
		printf("���� ���� ����..... ������ȸ�� �������ּ���\n");
		exit(0);
	}
}

void GameManager::PrintPlayerState()const
{
	printf("%d �� %d ���� \n\n", y + 1, x + 1);
	printf("==================================================================================\n");
	printf("�̸� : %s , HP : [% .1f / % .1f], ���ݷ� : %.1f, ���� : %.1f, ���� ��� : %2d\n"
		, (GamePlayer->GetName()).c_str(),GamePlayer->GetHealthPoint()
		, GamePlayer->GetMaxHealth(), GamePlayer->GetAttackPower()
		, GamePlayer->GetDefensivePower(), GamePlayer->GetGold());
	printf("==================================================================================\n");
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

	for (y = 0; y < InDungeon.DungeonSize; y++)
	{
		for (x = 0; x < InDungeon.DungeonSize; x++)
		{
			PrintPlayerState();
			switch (InDungeon.GetRoomType(y,x))
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
				BossRoom();
				break;
			default:
				break;
			}
				
		}
	}
	GameEnd();
}

void GameManager::EnemyEncounter()
{	
	int EnemySpawn = rand() % EnemySpawnPercent;
	// ���͸� ���� ������ ����
	// �������� ������ ��ü�� �޸� ������ �ڵ����� ó��
	// case ���� �ٸ� ������ ���͸� �����ϴ��� Enemy �����ͷ� �����ȴ�.
	std::unique_ptr<Enemy> NewEnemy = nullptr;

	switch (EnemySpawn)
	{
	case 0:
	case 1:
		NewEnemy = std::make_unique<Zombie>();
		break;
	case 2:
	case 3:
		NewEnemy = std::make_unique<Slime>();
		break;
	case 4:
	case 5:
		NewEnemy = std::make_unique<Goblin>();
		break;
	case 6:
	case 7:
		NewEnemy = std::make_unique<Skeleton>();
		break;
	case 8:
		NewEnemy = std::make_unique<Oak>();
		break;
	default:
		break;
	}
	printf("���� �ִ� �濡 ���Խ��ϴ�.\n");
	printf("%s�� �����ƽ��ϴ�.\n",(NewEnemy->GetName()).c_str());
	printf("���� ����!\n");
	//������ ����
	StartBattle(std::move(NewEnemy));
	if (!(GamePlayer->IsAlive()))
	{
		GameEnd();
	}
	NextRoom();
}

void GameManager::HealerEncounter()
{
	printf("ġ���縦 �������ϴ�.\n");
	printf("ġ���� �������� 10��尡 �ʿ��ϸ� ġ������ �ֻ����� ���� �������ϴ�\n");
	printf("ġ������ �ִ� �ַ��� ���� �� �����ϴ�.\n");
	printf("��尡 ����ϸ� ������ ġ���� ���� �� �ֽ��ϴ�.\n");

	if(GamePlayer->GetGold() < HealCost)
	{ 
		printf("ġ���� �ʿ��� ��尡 �����մϴ�.\n");
	}
	if (GamePlayer->IsHealthPointFull())
	{
		printf("HP�� ���� �� �����Դϴ�.\n");
	}
	while (GamePlayer->GetGold() >= HealCost && !GamePlayer->IsHealthPointFull())
	{
		printf("ġ���� �����ðڽ��ϱ�? (���� ��� : %d)(Yes = Y,y , No = N,n)\n",GamePlayer->GetGold());
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
			GamePlayer->SetPlayerHealth(ResultDiceSum+(GamePlayer->GetHealthPoint()));
			printf("���� ü�� : %.1f\n",GamePlayer->GetHealthPoint());
			GamePlayer->SetPlayerGold(GamePlayer->GetGold()- HealCost);
		}
	}
	NextRoom();
	return;
}

void GameManager::TraderEncounter()
{
	printf("������ �������ϴ�.\n");
	Trader trad;
	if (trad.GetStorList() == static_cast<int>(StoreList::None))
	{
		printf("������ ���� ��� ������ ���Ѱ��... �� �� �ִ� ������ ����\n");
		NextRoom();
	}
	else
	{
		while(trad.GetStorList() != 0 && trad.IsTraderShopping())
		{
			printf("���� ���\n");
			printf("========================================================\n");
		
			if (trad.HasPotion(StoreList::MaxHealthPointUPPotion))
			{
				printf("- �ִ� ü�� 10 ���� ���� [%dG] \n",trad.GetMaxHealthPotionPrice());
			}
			if (trad.HasPotion(StoreList::AttackPowerUPPotion))
			{
				printf("- ���ݷ� ���� 5 ���� [%dG] \n",trad.GetAttackPotionPrice());
			}
			if (trad.HasPotion(StoreList::DefensivePowerUPPotion))
			{
				printf("- ���� ���� 5 ���� [%dG] \n",trad.GetDefensePotionPrice());
			}
			printf("========================================================\n");
			if (trad.HasPotion(StoreList::MaxHealthPointUPPotion))
			{
				printf("H �Է� : �ִ� ü�� 10 ���� ���� ����\n");
			}
			if (trad.HasPotion(StoreList::AttackPowerUPPotion))
			{
				printf("A �Է� : ���ݷ� 5  ���� ���� ����\n");
			}
			if (trad.HasPotion(StoreList::DefensivePowerUPPotion))
			{
				printf("D �Է� : ���� 5 ���� ���� ����\n");
			}
			printf("0 �Է� : ���� �ݱ�\n");
			printf("========================================================\n");
			printf("���� ��� : %d\n",GamePlayer->GetGold());
			printf("========================================================\n");
			ProcessPurchaseLoop(trad);
		}
		NextRoom();
	}
}
void GameManager::ProcessPurchaseLoop(Trader& trad)
{
	char Choice = NULL;
	while (true)
	{
		printf("�����Ͻ� ������ �Է����ּ���\n");
		std::cin >> Choice;
		switch (Choice)
		{
		case 'H':
			if (trad.HasPotion(StoreList::MaxHealthPointUPPotion))
			{
				if (GamePlayer->GetGold() < trad.GetMaxHealthPotionPrice())
				{
					printf("�����Ͻ� ��尡 �����Ͽ� ���Կ� �����Ͽ����ϴ�\n");
				}
				else
				{
					printf("�ִ� ü�� 10 ���� ������ %d ��忡 �����ϼ̽��ϴ�.\n", trad.GetMaxHealthPotionPrice());
					printf("�ִ� ü���� 10 �����Ͽ����ϴ�.\n");
					GamePlayer->SetPlayerGold(GamePlayer->GetGold() - trad.GetMaxHealthPotionPrice());
					GamePlayer->SetPlayerMaxHealth(GamePlayer->GetMaxHealth()+10);
					trad.RemoveItem(StoreList::MaxHealthPointUPPotion);
					return;
				}
			}
			else
			{
				printf("�̹� �����ϼ̰ų�, ���� ��Ͽ� ���� �����Դϴ�.\n");
			}
			break;
		case 'A':
			if (trad.HasPotion(StoreList::AttackPowerUPPotion))
			{
				if (GamePlayer->GetGold() < trad.GetAttackPotionPrice())
				{
					printf("�����Ͻ� ��尡 �����Ͽ� ���Կ� �����Ͽ����ϴ�\n");
				}
				else
				{
					printf("���ݷ� 5 ���� ������ %d ��忡 �����ϼ̽��ϴ�.\n", trad.GetAttackPotionPrice());
					printf("���ݷ� 5 �����Ͽ����ϴ�.\n");
					GamePlayer->SetPlayerGold(GamePlayer->GetGold() - trad.GetAttackPotionPrice());
					GamePlayer->SetPlayerAttackPower(GamePlayer->GetAttackPower() + 5);
					GamePlayer->SetPlayerOriginalAttackPower(GamePlayer->GetOriginalAttackPower() + 5);
					trad.RemoveItem(StoreList::AttackPowerUPPotion);
					return;
				}
			}
			else
			{
				printf("�̹� �����ϼ̰ų�, ���� ��Ͽ� ���� �����Դϴ�.\n");
			}
			break;
		case 'D':
			if (trad.HasPotion(StoreList::DefensivePowerUPPotion))
			{
				if (GamePlayer->GetGold() < trad.GetDefensePotionPrice())
				{
					printf("�����Ͻ� ��尡 �����Ͽ� ���Կ� �����Ͽ����ϴ�\n");
				}
				else
				{
					printf("���� 5 ���� ������ %d ��忡 �����ϼ̽��ϴ�.\n", trad.GetDefensePotionPrice());
					printf("���� 5 �����Ͽ����ϴ�.\n");
					GamePlayer->SetPlayerGold(GamePlayer->GetGold() - trad.GetDefensePotionPrice());
					GamePlayer->SetPlayerDefensivePower(GamePlayer->GetDefensivePower() + 5);
					trad.RemoveItem(StoreList::DefensivePowerUPPotion);
					return;
				}
			}
			else
			{
				printf("�̹� �����ϼ̰ų�, ���� ��Ͽ� ���� �����Դϴ�.\n");
			}
			break;
		case '0':
		{
			printf("���ο��� �λ� �� �� ���������ϴ�.\n");
			trad.StopShopping();
			return;
		}
		default:
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			break;
		}
	}
}


void GameManager::TrapEncounter()
{
	int TrapActivate = 0;
	int TrapPercent = 3;
	float TrapDamage = 0.0f;
	int TrapDamage_Int = rand() % 50 + 50;

	TrapActivate = rand() % TrapPercent;
	TrapDamage = static_cast<float>(TrapDamage_Int)/10.0f;
	//TrapDamage = round(TrapDamage* 10.0f) / 10.0f;

	printf("�ƹ��͵� ���� ����Դϴ�.\n");
	if (TrapActivate == 0)
	{
		Sleep(1000);
		printf("������ �ߵ��Ͽ����ϴ�! HP�� �����մϴ�.\n");
		GamePlayer->TakeDamage(TrapDamage);
		if (!GamePlayer->IsAlive())
		{
			GameEnd();
		}
	}
	NextRoom();
}

void GameManager::EmptyRoom()const
{
	printf("�ƹ��͵� ���� ����Դϴ�.\n");
	NextRoom();
}

void GameManager::BossRoom()
{
	printf("������ �ִ� �濡 ���Խ��ϴ�\n");
	int EnemySpawn = rand() % BossSpawnPercent;
	// ���͸� ���� ������ ����
	// �������� ������ ��ü�� �޸� ������ �ڵ����� ó��
	// case ���� �ٸ� ������ ���͸� �����ϴ��� Enemy �����ͷ� �����ȴ�.
	std::unique_ptr<Enemy> NewEnemy = nullptr;

	switch (EnemySpawn)
	{
	case 0:
		NewEnemy = std::make_unique<Demon>();
		break;
	case 1:
		NewEnemy = std::make_unique<GiantSlime>();
		break;
	case 2:
		NewEnemy = std::make_unique<LabyrinthWarden>();
		break;
	case 3:
		NewEnemy = std::make_unique<LavaGiant>();
		break;
	case 4:
		NewEnemy = std::make_unique<ShadowWraith>();
		break;
	default:
		break;
	}
	printf("%s�� �����ƽ��ϴ�.\n", (NewEnemy->GetName()).c_str());
	printf("���� ����!\n");
	//������ ����
	StartBattle(std::move(NewEnemy));
	if (!(GamePlayer->IsAlive()))
	{
		GameEnd();
	}
	printf("���� ������ óġ�ϼ̽��ϴ�. ����������!\n");
	IsFloorCleared = true;
	NextRoom();
}

void GameManager::NextRoom()const
{
	if (IsFloorCleared == true)
	{
		printf("���� ������ �̵��մϴ�.\n");
		IsFloorCleared == false;
	}
	else
	{
		printf("���� ������ �̵��մϴ�.\n");
	}
	Sleep(2000);
	system("cls");
}