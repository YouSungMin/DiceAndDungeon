#include "Goblin.h"

void Goblin::UseSkill()
{
	printf("%s�� [��ź ��Ʈ����] ��ų�� ����߽��ϴ�.\n", Name.c_str());
	printf("�÷��̾�� ū �������� �޾����� ����� ����߽��ϴ�.!\n");
	SetAttackPower(50.0f);
	SetHealth(0.0f);
}
