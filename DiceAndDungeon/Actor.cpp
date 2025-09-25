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
		printf("��� �߽��ϴ�.\n");
	else
	{
		SetHealth(HealthPoint - InDamage);
		printf("%s�� %.1f�� ���ظ� �Ծ����ϴ�.\n", Name.c_str(), InDamage);
		if(IsHealthPointZero())
			HealthPoint = 0.0f;

		printf("(%.1f/%.1f)\n", HealthPoint, MaxHealth);
	}
	if (!IsAlive())
	{
		printf("%s�� �׾����ϴ�.\n", Name.c_str());
	}
}
