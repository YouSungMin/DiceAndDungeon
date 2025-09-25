#include <cstdint>
#include <random>
#pragma once
enum class StoreList : uint8_t
{
	None = 0,
	MaxHealthPointUPPotion = 1 << 0,
	AttackPowerUPPotion = 1 << 1,
	DefensivePowerUPPotion = 1 << 2
};
class Trader
{
public:
	Trader()
	{
		RandomStoreList = rand() % StoreListMaxSize;
	}
	inline int GetStorList(){return RandomStoreList;}
	~Trader() = default;
private:
	static const int StoreListMaxSize = 8;
	int RandomStoreList = 0;
};

