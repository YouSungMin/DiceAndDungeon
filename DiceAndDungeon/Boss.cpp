#include "Boss.h"

void Boss::UseSkill()
{
}
Boss::Boss(const std::string& InName, int InMinHealth, int InMaxHealth, int InMinAttack, int InMaxAttack)
    : Enemy(InName, InMinHealth, InMaxHealth, InMinAttack, InMaxAttack)
{
}
