#include "LabyrinthWarden.h"

void LabyrinthWarden::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::CrushingBlow:
	{
		printf("%s가 [강타] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 기본 공격력이 강화됩니다 !\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 1.5f);
		break;
	}
	case ESkill::Earthquake:
	{
		printf("%s가 [지진] 스킬을 사용했습니다.\n", Name.c_str());
		printf("%s의 강력한 공격을 합니다!!\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 1.8f);
		break;
	}
	default:
		break;
	}
}
