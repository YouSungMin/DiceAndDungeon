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

	// �����ڸ� ���� ���� ���� ���ݰ� ���� �ʱ�ȭ
	Trader()
	{
		RandomStoreList = rand() % StoreListMaxSize;

		MaxHealthPointUPPotionPrice = rand() % (MaxPotionPrice - MinPotionPrice +1) + MinPotionPrice;
		MaxAttackPowerUPPotionPrice = rand() % (MaxPotionPrice - MinPotionPrice + 1) + MinPotionPrice;
		MaxDefensivePowerUPPotionPrice = rand() % (MaxPotionPrice - MinPotionPrice + 1) + MinPotionPrice;
	}
	inline int GetStorList(){return RandomStoreList;}
	// �ִ� ü�� ���� ������ ��ȯ�ϴ� getter
	inline int GetMaxHealthPotionPrice() const {return MaxHealthPointUPPotionPrice;}

	// ���ݷ� ���� ������ ��ȯ�ϴ� getter
	inline int GetAttackPotionPrice() const {return MaxAttackPowerUPPotionPrice;}

	// ���� ���� ������ ��ȯ�ϴ� getter
	inline int GetDefensePotionPrice() const {return MaxDefensivePowerUPPotionPrice;}
	~Trader() = default;

	// ������ �����ϸ� �ٽ� ����� �� ��Ʈ ���� �Լ�
	inline void RemoveItem(StoreList item)
	{
		int itemFlag = static_cast<int>(item);
		RandomStoreList &= ~itemFlag;
	}

	// ������ �׸��̿��ϰ� �Ǹ� ȣ��� �Լ�
	inline void StopShopping() { IsShopping = false; }

	// ������ ��� �̿��� ������ Ȯ�� �� �Լ�
	inline bool IsTraderShopping() const { return IsShopping; }

	// ������ ���ο��� �����ϴ��� ����� ��Ʈ ���� �Լ�
	bool HasPotion(StoreList InPotion)const {return (RandomStoreList & static_cast<int>(InPotion)) != 0;}
private:
	
	//��Ʈ �÷��׷� ǥ���� 0~7������ ��Ȳ�� ǥ���ϱ� ���� �ִ� ��
	static constexpr int StoreListMaxSize = 8;

	// ���డ���� �ּ� �ִ밪�� �������� �ϱ����� �ִ�, �ּҰ� ����
	static constexpr int MaxPotionPrice = 150; 
	static constexpr int MinPotionPrice = 80;

	// ��Ʈ�÷��׸� ���� ������ ���� ���� ����
	int RandomStoreList = 0;

	// ������ ������ ��� ������
	int MaxHealthPointUPPotionPrice = 0;
	int MaxAttackPowerUPPotionPrice = 0;
	int MaxDefensivePowerUPPotionPrice = 0;

	// ������ ��� �̿��� ������ Ȯ�� �� ����
	bool IsShopping = true;

};

