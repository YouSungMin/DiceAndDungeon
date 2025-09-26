#include "Zombie.h"

void Zombie::UseSkill()
{
	printf("%s가 [물기] 스킬을 사용했습니다.\n", Name.c_str());
	printf("%s의 기본공격력이 상승하고 HP를 회복합니다. !\n", Name.c_str());
	SetAttackPower(AttackPower+5.0f);
	SetHealth(HealthPoint+10.0f);
}
