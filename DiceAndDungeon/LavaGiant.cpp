#include "LavaGiant.h"

void LavaGiant::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::LavaEruption:
	{
		printf("%s�� [��� ����] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� ���� �������ϸ� �⺻ ���ݷ��� ��ȭ�˴ϴ� !\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 1.5f);
		SetOriginalAttackPower(OriginalAttackPower * 1.5f);
		break;
	}
	case ESkill::Earthquake:
	{
		printf("%s�� [����] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� ������ ������ �մϴ�!!\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 1.8f);
		break;
	}
	default:
		break;
	}
}
