#include "ShadowWraith.h"

void ShadowWraith::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::ShadowCloak:
	{
		printf("%s가 [그림자 은신] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 그림자에 숨으며 체력을 회복하고 크리티컬 확률을 증가시킵니다. !\n", Name.c_str());
		printf("%s의 생명력이 회복됩니다 !\n", Name.c_str());
		SetHealth(HealthPoint + HealingAmount);
		SetCriticalPercent(CriticalPercent-3);
		break;
	}
	case ESkill::ShadowStrike:
	{
		printf("%s가 [그림자 강타] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 강력한 공격을 합니다!!\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 2.0f);
		break;
	}
	default:
		break;
	}
}
