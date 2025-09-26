#include "Skeleton.h"

void Skeleton::UseSkill()
{
	printf("%s가 [크리티컬 강화] 스킬을 사용했습니다.\n", Name.c_str());
	printf("%s의 크리티컬 확률이 강화됩니다 !\n", Name.c_str());
	SetAttackPower(CriticalPercent-3);
}
