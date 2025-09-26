#include "LabyrinthWarden.h"

void LabyrinthWarden::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::CrushingBlow:
	{
		printf("%s�� [��Ÿ] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� �⺻ ���ݷ��� ��ȭ�˴ϴ� !\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 1.5f);
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
