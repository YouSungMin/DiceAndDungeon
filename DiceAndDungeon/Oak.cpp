#include "Oak.h"

void Oak::UseSkill()
{
	printf("%s�� [��ȿ�ϱ�] ��ų�� ����߽��ϴ�.\n", Name.c_str());
	printf("%s�� �⺻ ���ݷ��� ��ȭ�˴ϴ� !\n", Name.c_str());
	SetAttackPower(OriginalAttackPower *1.5f);
}
