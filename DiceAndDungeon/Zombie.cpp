#include "Zombie.h"

void Zombie::UseSkill()
{
	printf("%s�� [����] ��ų�� ����߽��ϴ�.\n", Name.c_str());
	printf("%s�� �⺻���ݷ��� ����ϰ� HP�� ȸ���մϴ�. !\n", Name.c_str());
	SetAttackPower(AttackPower+5.0f);
	SetHealth(HealthPoint+10.0f);
}
