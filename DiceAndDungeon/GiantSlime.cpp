#include "GiantSlime.h"

void GiantSlime::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::Heal:
	{
		printf("%s�� [ȸ��] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� ������� ȸ���˴ϴ� !\n", Name.c_str());
		SetHealth(HealthPoint + HealingAmount);
		break;
	}
	case ESkill::SplitBomb:
	{
		printf("%s�� [�п� ��ź] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� ������� �����ϰ� ������ ������ �մϴ�!!\n", Name.c_str());
		SetHealth(HealthPoint - HealingAmount);
		SetAttackPower(OriginalAttackPower * 1.5f);
		break;
	}
	default:
		break;
	}
}
