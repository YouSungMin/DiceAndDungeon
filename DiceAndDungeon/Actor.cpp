#include "Actor.h"
#include "Player.h"
void Actor::Attack(Actor* InTarget, float PlusDicePower)
{
	if(Player* playerTarget = dynamic_cast<Player*>(InTarget))
	{
		InTarget->TakeDamage(AttackPower - ( PlusDicePower + InTarget->DefensivePower));
	}
	else
	{
		InTarget->TakeDamage(AttackPower + PlusDicePower);
	}
}

void Actor::TakeDamage(float InDamage)
{
	if(IsDamageZero(InDamage))
		printf("방어 했습니다.\n");
	else
	{
		SetHealth(HealthPoint - InDamage);
		printf("%s가 %.1f의 피해를 입었습니다.\n", Name.c_str(), InDamage);
		if(IsHealthPointZero())
			HealthPoint = 0.0f;

		printf("(%.1f/%.1f)\n", HealthPoint, MaxHealth);
	}
	if (!IsAlive())
	{
		printf("%s가 죽었습니다.\n", Name.c_str());
	}
}
