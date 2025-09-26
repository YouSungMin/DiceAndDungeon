#include "Demon.h"

void Demon::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::Rage:
	{
		printf("%s가 [분노] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 기본 공격력이 강화됩니다 !\n", Name.c_str());
		SetOriginalAttackPower(OriginalAttackPower * 1.5f);
		SetAttackPower(OriginalAttackPower);
		break;
	}
	case ESkill::ShadowFlame:
	{
		printf("%s가 [그림자 불꽃] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 강력한 공격을 합니다!!\n", Name.c_str());
		SetAttackPower(OriginalAttackPower*1.5f);
		break;
	}
	default:
		break;
	}

}
