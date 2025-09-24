#include <cstdint>
#include <random>
#pragma once
enum class RoomType : uint8_t
{
	Empty,  // �� �� 1
	Healer, // ġ���� ���� 1
	trap,	// ���� �� 1
	trader, // ���� 1
	Enemy,  // ���� ���� 2
	Boss	// ���� ��
};

class Dungeon
{
public:
	static constexpr int DungeonSize = 10; // 10���� ���� ������ 10���� ��
	Dungeon() // ������ �渶�� ������ RoomType ����
	{
		for (int y = 0; y < DungeonSize; y++) // y�� ���� ��
		{
			for (int x = 0; x < DungeonSize; x++) // x�� ���� ��
			{
				int RandomRoom = rand() % 6; 
				if(x == 9)
					RandomRoom = 6;
				switch (RandomRoom)
				{
				case 0:
					Rooms[y][x] = RoomType::Empty; // ���� 1�� ���
					break;
				case 1:
					Rooms[y][x] = RoomType::Healer; // ���� 1�� ġ���� ����
					break;
				case 2:
					Rooms[y][x] = RoomType::trap; // ���� 1�� ���� ��
					break;
				case 3:
					Rooms[y][x] = RoomType::trader; // ���� 1�� ����
					break;
				case 4:
				case 5:				
					Rooms[y][x] = RoomType::Enemy; // ���� 2�� ���� ����
					break;
				default:
					Rooms[y][x] = RoomType::Boss; // ���� �� x �� 9�϶� RandomRoom�� 6���� �����ؼ� �̰����� �������� ����
					break;
				} 
			}
		}
	}
	~Dungeon() = default;
	// X�� Y�� ���� �Ķ���ͷ� �޴� Getter �Լ��� ����� Rooms �迭�� InX , InY ���� enum ���� ���� �ޱ�
	inline const RoomType GetRoomType(int InX,int InY) const { return Rooms[InX][InY]; } 
private:
	RoomType Rooms[DungeonSize][DungeonSize]; // ���� �� �迭����
};

