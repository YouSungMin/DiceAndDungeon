#include "GiantSlime.h"

void GiantSlime::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::Heal:
	{
		printf("%s가 [회복] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 생명력이 회복됩니다 !\n", Name.c_str());
		SetHealth(HealthPoint + HealingAmount);
		break;
	}
	case ESkill::SplitBomb:
	{
		printf("%s가 [분열 폭탄] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 생명력이 감소하고 강력한 공격을 합니다!!\n", Name.c_str());
		SetHealth(HealthPoint - HealingAmount);
		SetAttackPower(OriginalAttackPower * 1.5f);
		break;
	}
	default:
		break;
	}
}
