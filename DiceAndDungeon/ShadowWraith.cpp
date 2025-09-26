#include "ShadowWraith.h"

void ShadowWraith::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::ShadowCloak:
	{
		printf("%s�� [�׸��� ����] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� �׸��ڿ� ������ ü���� ȸ���ϰ� ũ��Ƽ�� Ȯ���� ������ŵ�ϴ�. !\n", Name.c_str());
		printf("%s�� ������� ȸ���˴ϴ� !\n", Name.c_str());
		SetHealth(HealthPoint + HealingAmount);
		SetCriticalPercent(CriticalPercent-3);
		break;
	}
	case ESkill::ShadowStrike:
	{
		printf("%s�� [�׸��� ��Ÿ] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� ������ ������ �մϴ�!!\n", Name.c_str());
		SetAttackPower(OriginalAttackPower * 2.0f);
		break;
	}
	default:
		break;
	}
}
