#include "Goblin.h"

void Goblin::UseSkill()
{
	printf("%s가 [폭탄 터트리기] 스킬을 사용했습니다.\n", Name.c_str());
	printf("플레이어는 큰 데미지를 받았지만 고블린은 사망했습니다.!\n");
	SetAttackPower(50.0f);
	SetHealth(0.0f);
}
