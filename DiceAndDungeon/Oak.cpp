#include "Oak.h"

void Oak::UseSkill()
{
	printf("%s가 [포효하기] 스킬을 사용했습니다.\n", Name.c_str());
	printf("%s의 기본 공격력이 강화됩니다 !\n", Name.c_str());
	SetAttackPower(OriginalAttackPower *1.5f);
}
