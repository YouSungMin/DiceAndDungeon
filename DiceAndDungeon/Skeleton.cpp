#include "Skeleton.h"

void Skeleton::UseSkill()
{
	printf("%s�� [ũ��Ƽ�� ��ȭ] ��ų�� ����߽��ϴ�.\n", Name.c_str());
	printf("%s�� ũ��Ƽ�� Ȯ���� ��ȭ�˴ϴ� !\n", Name.c_str());
	SetAttackPower(CriticalPercent-3);
}
