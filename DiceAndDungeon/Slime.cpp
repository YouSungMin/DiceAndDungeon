#include "Slime.h"

void Slime::UseSkill()
{
	printf("%s�� [ȸ��] ��ų�� ����߽��ϴ�.\n", Name.c_str());
	printf("%s�� ������� ȸ���˴ϴ� !\n", Name.c_str());
	SetHealth(HealthPoint+ 10.0f);
}
