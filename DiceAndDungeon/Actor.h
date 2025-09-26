#pragma once
#include <string>
class Actor
{
public:
	//�⺻ ������
	Actor() = default;

	//�⺻ �Ҹ���
	virtual ~Actor() = default;

	//�̸��� �Ķ���ͷ� �޴� ������ �ʱ�ȭ����
	Actor(const std::string& InName) : Name(InName) {}

	/// <summary>
	/// Target���� �����ϴ� �Լ�
	/// </summary>
	/// <param name="InTarget">���� �޴� ���</param>
	void Attack(Actor* InTarget, float PlusDiceDamage);

	/// <summary>
	/// ������ ���ط���ũ ���ο��� ���ظ� ����
	/// </summary>
	/// <param name="InDamage">������ ���ط�</param>
	void TakeDamage(float InDamage);

	/// <summary>
	/// ���� ���θ� �˷��ִ� �Լ�
	/// </summary>
	/// <returns>true�� ������� </returns>
	inline bool IsAlive()const {return HealthPoint > 0;}

	/// <summary>
	/// �������� 0�������� üũ�ϴ� �Լ�
	/// </summary>
	/// <param name="InDamage">üũ�� ������</param>
	/// <returns>true�� 0����</returns>
	inline bool IsDamageZero(float InDamage)const{return InDamage < 0;}

	/// <summary>
	/// HealthPoint�� 0 �������� üũ�ϴ� �Լ�
	/// </summary>
	/// <returns>true�� 0����</returns>
	inline bool IsHealthPointZero(){return HealthPoint < 0;}

	/// <summary>
	/// ��ü�� ��带 �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� ���</returns>
	inline int GetGold()const{return Gold;}

	/// <summary>
	/// ��ü�� HealthPoint�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� HealthPoint</returns>
	inline float GetHealthPoint()const {return HealthPoint;}

	/// <summary>
	/// ��ü�� MaxHealth�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� MaxHealth</returns>
	inline float GetMaxHealth()const { return MaxHealth; }

	/// <summary>
	/// ��ü�� AttackPower�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� AttackPower</returns>
	inline float GetAttackPower()const {return AttackPower;}

	/// <summary>
	/// ��ü�� OriginalAttackPower�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� OriginalAttackPower</returns>
	inline float GetOriginalAttackPower()const {return OriginalAttackPower;}

	/// <summary>
	/// ��ü�� DefensivePower�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� DefensivePower</returns>
	inline float GetDefensivePower()const {return DefensivePower;}

	/// <summary>
	/// ��ü�� CriticalPercent�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� CriticalPercent</returns>
	inline int GetCriticalPercent()const {return CriticalPercent;}

	/// <summary>
	/// ��ü�� Name�� �޾ƿ��� Getter
	/// </summary>
	/// <returns>��ü�� Name</returns>
	inline std::string GetName()const {return Name;}

protected:
	/// <summary>
	/// ��ü�� CriticalPercent�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ CriticalPercent</param>
	inline void SetCriticalPercent(int InCriticalPercent)
	{
		CriticalPercent = InCriticalPercent;
	}

	/// <summary>
	/// ��ü�� Gold�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ Gold</param>
	inline void SetGold(int InGold)
	{
		Gold = InGold;
	}

	/// <summary>
	/// ��ü�� Health�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ Health</param>
	inline void SetHealth(float InHealth)
	{
		if (InHealth > MaxHealth)
		{
			HealthPoint = MaxHealth;
		}
		else
		{
			HealthPoint = InHealth;
		}
	}

	/// <summary>
	/// ��ü�� AttackPower�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ AttackPower</param>
	inline void SetAttackPower(float InAttackPower)
	{
		AttackPower = InAttackPower;
	}

	/// <summary>
	/// ��ü�� OriginalAttackPower�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ OriginalAttackPower</param>
	inline void SetOriginalAttackPower(float InOriginalAttackPower)
	{
		OriginalAttackPower = InOriginalAttackPower;
	}

	/// <summary>
	/// ��ü�� MaxHealth�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ MaxHealth</param>
	inline void SetMaxHealth(float InMaxHealth)
	{
		MaxHealth = InMaxHealth;
	}

	/// <summary>
	/// ��ü�� InCriticalPercent�� �����ϴ� Setter
	/// </summary>
	/// <param name="InCriticalPercent">������ InCriticalPercent</param>
	inline void SetDefensivePower(float InDefensivePower)
	{
		DefensivePower = InDefensivePower;
	}

	// ��ü�� �̸��� ���� ����
	std::string Name = "Actor";

	// ũ��Ƽ�� Ȯ���� ���� ����
	int CriticalPercent = 5;

	// HP�� ���� ����
	float HealthPoint = 100.0f;

	// ���ݷ��� ���� ����
	float AttackPower = 10.0f;

	// ������ ���� ����
	float DefensivePower = 5.0f;

	// �ִ� ü���� ���� ����
	float MaxHealth = 100.0f;

	// ��� �縦 ���� ����
	int Gold = 10;

	//ũ��Ƽ���� �������� Ȯ���ϴ� ����
	bool IsCritical = false;

	// ��ü�� ���� ���ݷ� 
	//ex) ���ݷ� ������ ��ų ���� AttackPower�� �����ϱ⿡ ��� �� ���� ���ݷ����� �ʱ�ȭ
	float OriginalAttackPower = 0.0f;
};

