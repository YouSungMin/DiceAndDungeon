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

	// 생성자를 통해 랜덤 포션 가격과 상태 초기화
	Trader()
	{
		RandomStoreList = rand() % StoreListMaxSize;

		MaxHealthPointUPPotionPrice = rand() % (MaxPotionPrice - MinPotionPrice +1) + MinPotionPrice;
		MaxAttackPowerUPPotionPrice = rand() % (MaxPotionPrice - MinPotionPrice + 1) + MinPotionPrice;
		MaxDefensivePowerUPPotionPrice = rand() % (MaxPotionPrice - MinPotionPrice + 1) + MinPotionPrice;
	}
	inline int GetStorList(){return RandomStoreList;}
	// 최대 체력 물약 가격을 반환하는 getter
	inline int GetMaxHealthPotionPrice() const {return MaxHealthPointUPPotionPrice;}

	// 공격력 물약 가격을 반환하는 getter
	inline int GetAttackPotionPrice() const {return MaxAttackPowerUPPotionPrice;}

	// 방어력 물약 가격을 반환하는 getter
	inline int GetDefensePotionPrice() const {return MaxDefensivePowerUPPotionPrice;}
	~Trader() = default;

	// 포션을 구입하면 다시 못사게 할 비트 연산 함수
	inline void RemoveItem(StoreList item)
	{
		int itemFlag = static_cast<int>(item);
		RandomStoreList &= ~itemFlag;
	}

	// 상점을 그만이용하게 되면 호출될 함수
	inline void StopShopping() { IsShopping = false; }

	// 상점을 계속 이용할 것인지 확인 할 함수
	inline bool IsTraderShopping() const { return IsShopping; }

	// 포션이 상인에게 존재하는지 물어보는 비트 연산 함수
	bool HasPotion(StoreList InPotion)const {return (RandomStoreList & static_cast<int>(InPotion)) != 0;}
private:
	
	//비트 플래그로 표현할 0~7까지의 상황을 표현하기 위한 최대 수
	static constexpr int StoreListMaxSize = 8;

	// 물약가격의 최소 최대값을 랜덤으로 하기위한 최대, 최소값 변수
	static constexpr int MaxPotionPrice = 150; 
	static constexpr int MinPotionPrice = 80;

	// 비트플래그를 통한 랜덤한 값을 담을 변수
	int RandomStoreList = 0;

	// 랜덤한 가격이 담길 변수들
	int MaxHealthPointUPPotionPrice = 0;
	int MaxAttackPowerUPPotionPrice = 0;
	int MaxDefensivePowerUPPotionPrice = 0;

	// 상점을 계속 이용할 것인지 확인 할 변수
	bool IsShopping = true;

};

