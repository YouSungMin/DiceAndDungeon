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
	printf("||        +----+ |  <-- 모험의 주사위가 굴러갑니다!     ||\n");
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
	printf("\n환영합니다! 던전에 도전할 용사의 이름을 입력해주세요: ");
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
	GamePlayer = new Player("aaa", 5.0f, 5.0f, 5.0f);
	TraderEncounter();
	int i = 0;
	delete GamePlayer;
}

void GameManager::StartBattle(std::unique_ptr<Enemy>&& InEnemy)
{
	while (GamePlayer->IsAlive() && InEnemy->IsAlive())
	{
		printf("공격 주사위를 굴림!!\n");
		PlayerDiceRoll(DiceRollMaxCount);
		PrintDiceResult();
		printf("을 추가 공격력을 얻습니다.\n");
		printf("플레이어의 공격!\n");
		Sleep(1000);
		GamePlayer->Attack(InEnemy.get(),ResultDiceSum);
		if(!InEnemy->IsAlive())
		{
			GamePlayer->SetPlayerGold(GamePlayer->GetGold()+InEnemy->GetGold());
			break;
		}
		printf("방어 주사위를 굴림!!\n");
		PlayerDiceRoll(DiceRollMaxCount);
		PrintDiceResult();
		printf("을 추가 방어력을 얻습니다.\n");
		printf("%s의 공격!\n", (InEnemy->GetName()).c_str());
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
		printf("축하합니다! 던전을 정복하셨습니다.!!!!\n");
		exit(0);
	}
	else
	{
		printf("던전 정복 실패..... 다음기회에 도전해주세요\n");
		exit(0);
	}
}

void GameManager::PrintPlayerState()const
{
	printf("%d 층 %d 번방 \n\n", y + 1, x + 1);
	printf("==================================================================================\n");
	printf("이름 : %s , HP : [% .1f / % .1f], 공격력 : %.1f, 방어력 : %.1f, 소유 골드 : %2d\n"
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
	printf("주사위는 %d , %d , %d 가 나와 총 %d", static_cast<int>(ResultDiceRoll[0]), static_cast<int>(ResultDiceRoll[1]), static_cast<int>(ResultDiceRoll[2]), static_cast<int>(ResultDiceSum));
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
	// 몬스터를 담을 포인터 선언
	// 동적으로 생성된 객체의 메모리 관리를 자동으로 처리
	// case 별로 다른 종류의 몬스터를 생성하더라도 Enemy 포인터로 관리된다.
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
	printf("적이 있는 방에 들어왔습니다.\n");
	printf("%s를 마주쳤습니다.\n",(NewEnemy->GetName()).c_str());
	printf("전투 시작!\n");
	//소유권 이전
	StartBattle(std::move(NewEnemy));
	if (!(GamePlayer->IsAlive()))
	{
		GameEnd();
	}
	NextRoom();
}

void GameManager::HealerEncounter()
{
	printf("치유사를 만났습니다.\n");
	printf("치유를 받으려면 10골드가 필요하며 치유량은 주사위를 통해 정해집니다\n");
	printf("치유량은 최대 최력을 넘을 수 없습니다.\n");
	printf("골드가 충분하면 여러번 치유를 받을 수 있습니다.\n");

	if(GamePlayer->GetGold() < HealCost)
	{ 
		printf("치유에 필요한 골드가 부족합니다.\n");
	}
	if (GamePlayer->IsHealthPointFull())
	{
		printf("HP가 가득 찬 상태입니다.\n");
	}
	while (GamePlayer->GetGold() >= HealCost && !GamePlayer->IsHealthPointFull())
	{
		printf("치유를 받으시겠습니까? (현재 골드 : %d)(Yes = Y,y , No = N,n)\n",GamePlayer->GetGold());
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
			printf("이 치유됩니다\n");
			GamePlayer->SetPlayerHealth(ResultDiceSum+(GamePlayer->GetHealthPoint()));
			printf("현재 체력 : %.1f\n",GamePlayer->GetHealthPoint());
			GamePlayer->SetPlayerGold(GamePlayer->GetGold()- HealCost);
		}
	}
	NextRoom();
	return;
}

void GameManager::TraderEncounter()
{
	printf("상인을 만났습니다.\n");
	Trader trad;
	if (trad.GetStorList() == static_cast<int>(StoreList::None))
	{
		printf("도적을 만나 모든 물건을 빼앗겼네... 팔 수 있는 물건이 없소\n");
		NextRoom();
	}
	else
	{
		while(trad.GetStorList() != 0 && trad.IsTraderShopping())
		{
			printf("상점 목록\n");
			printf("========================================================\n");
		
			if (trad.HasPotion(StoreList::MaxHealthPointUPPotion))
			{
				printf("- 최대 체력 10 증가 물약 [%dG] \n",trad.GetMaxHealthPotionPrice());
			}
			if (trad.HasPotion(StoreList::AttackPowerUPPotion))
			{
				printf("- 공격력 증가 5 물약 [%dG] \n",trad.GetAttackPotionPrice());
			}
			if (trad.HasPotion(StoreList::DefensivePowerUPPotion))
			{
				printf("- 방어력 증가 5 물약 [%dG] \n",trad.GetDefensePotionPrice());
			}
			printf("========================================================\n");
			if (trad.HasPotion(StoreList::MaxHealthPointUPPotion))
			{
				printf("H 입력 : 최대 체력 10 증가 물약 구입\n");
			}
			if (trad.HasPotion(StoreList::AttackPowerUPPotion))
			{
				printf("A 입력 : 공격력 5  증가 물약 구입\n");
			}
			if (trad.HasPotion(StoreList::DefensivePowerUPPotion))
			{
				printf("D 입력 : 방어력 5 증가 물약 구입\n");
			}
			printf("0 입력 : 상점 닫기\n");
			printf("========================================================\n");
			printf("보유 골드 : %d\n",GamePlayer->GetGold());
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
		printf("구매하실 포션을 입력해주세요\n");
		std::cin >> Choice;
		switch (Choice)
		{
		case 'H':
			if (trad.HasPotion(StoreList::MaxHealthPointUPPotion))
			{
				if (GamePlayer->GetGold() < trad.GetMaxHealthPotionPrice())
				{
					printf("보유하신 골드가 부족하여 구입에 실패하였습니다\n");
				}
				else
				{
					printf("최대 체력 10 증가 물약을 %d 골드에 구입하셨습니다.\n", trad.GetMaxHealthPotionPrice());
					printf("최대 체력이 10 증가하였습니다.\n");
					GamePlayer->SetPlayerGold(GamePlayer->GetGold() - trad.GetMaxHealthPotionPrice());
					GamePlayer->SetPlayerMaxHealth(GamePlayer->GetMaxHealth()+10);
					trad.RemoveItem(StoreList::MaxHealthPointUPPotion);
					return;
				}
			}
			else
			{
				printf("이미 구매하셨거나, 상점 목록에 없는 물건입니다.\n");
			}
			break;
		case 'A':
			if (trad.HasPotion(StoreList::AttackPowerUPPotion))
			{
				if (GamePlayer->GetGold() < trad.GetAttackPotionPrice())
				{
					printf("보유하신 골드가 부족하여 구입에 실패하였습니다\n");
				}
				else
				{
					printf("공격력 5 증가 물약을 %d 골드에 구입하셨습니다.\n", trad.GetAttackPotionPrice());
					printf("공격력 5 증가하였습니다.\n");
					GamePlayer->SetPlayerGold(GamePlayer->GetGold() - trad.GetAttackPotionPrice());
					GamePlayer->SetPlayerAttackPower(GamePlayer->GetAttackPower() + 5);
					GamePlayer->SetPlayerOriginalAttackPower(GamePlayer->GetOriginalAttackPower() + 5);
					trad.RemoveItem(StoreList::AttackPowerUPPotion);
					return;
				}
			}
			else
			{
				printf("이미 구매하셨거나, 상점 목록에 없는 물건입니다.\n");
			}
			break;
		case 'D':
			if (trad.HasPotion(StoreList::DefensivePowerUPPotion))
			{
				if (GamePlayer->GetGold() < trad.GetDefensePotionPrice())
				{
					printf("보유하신 골드가 부족하여 구입에 실패하였습니다\n");
				}
				else
				{
					printf("방어력 5 증가 물약을 %d 골드에 구입하셨습니다.\n", trad.GetDefensePotionPrice());
					printf("방어력 5 증가하였습니다.\n");
					GamePlayer->SetPlayerGold(GamePlayer->GetGold() - trad.GetDefensePotionPrice());
					GamePlayer->SetPlayerDefensivePower(GamePlayer->GetDefensivePower() + 5);
					trad.RemoveItem(StoreList::DefensivePowerUPPotion);
					return;
				}
			}
			else
			{
				printf("이미 구매하셨거나, 상점 목록에 없는 물건입니다.\n");
			}
			break;
		case '0':
		{
			printf("상인에게 인사 한 후 지나갔습니다.\n");
			trad.StopShopping();
			return;
		}
		default:
			printf("잘못 입력하셨습니다.\n");
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

	printf("아무것도 없는 빈방입니다.\n");
	if (TrapActivate == 0)
	{
		Sleep(1000);
		printf("함정이 발동하였습니다! HP가 감소합니다.\n");
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
	printf("아무것도 없는 빈방입니다.\n");
	NextRoom();
}

void GameManager::BossRoom()
{
	printf("보스가 있는 방에 들어왔습니다\n");
	int EnemySpawn = rand() % BossSpawnPercent;
	// 몬스터를 담을 포인터 선언
	// 동적으로 생성된 객체의 메모리 관리를 자동으로 처리
	// case 별로 다른 종류의 몬스터를 생성하더라도 Enemy 포인터로 관리된다.
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
	printf("%s를 마주쳤습니다.\n", (NewEnemy->GetName()).c_str());
	printf("전투 시작!\n");
	//소유권 이전
	StartBattle(std::move(NewEnemy));
	if (!(GamePlayer->IsAlive()))
	{
		GameEnd();
	}
	printf("층의 보스를 처치하셨습니다. 다음층으로!\n");
	IsFloorCleared = true;
	NextRoom();
}

void GameManager::NextRoom()const
{
	if (IsFloorCleared == true)
	{
		printf("다음 층으로 이동합니다.\n");
		IsFloorCleared == false;
	}
	else
	{
		printf("다음 방으로 이동합니다.\n");
	}
	Sleep(2000);
	system("cls");
}