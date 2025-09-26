#include "Slime.h"

void Slime::UseSkill()
{
	printf("%s가 [회복] 스킬을 사용했습니다.\n", Name.c_str());
	printf("%s의 생명력이 회복됩니다 !\n", Name.c_str());
	SetHealth(HealthPoint+ 10.0f);
}
