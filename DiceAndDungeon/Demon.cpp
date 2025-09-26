#include "Demon.h"

void Demon::UseSkill()
{
	ESkill RandomSkill = static_cast<ESkill>(rand() % SkillCount);

	switch (RandomSkill)
	{
	case ESkill::Rage:
	{
		printf("%s�� [�г�] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� �⺻ ���ݷ��� ��ȭ�˴ϴ� !\n", Name.c_str());
		SetOriginalAttackPower(OriginalAttackPower * 1.5f);
		SetAttackPower(OriginalAttackPower);
		break;
	}
	case ESkill::ShadowFlame:
	{
		printf("%s�� [�׸��� �Ҳ�] ��ų�� ����߽��ϴ�.\n", Name.c_str());
		printf("%s�� ������ ������ �մϴ�!!\n", Name.c_str());
		SetAttackPower(OriginalAttackPower*1.5f);
		break;
	}
	default:
		break;
	}

}
