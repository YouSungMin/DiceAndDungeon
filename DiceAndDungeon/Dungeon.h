#include <cstdint>
#include <random>
#pragma once
enum class RoomType : uint8_t
{
	Empty,  // 빈 방 1
	Healer, // 치유사 출현 1
	trap,	// 함정 방 1
	trader, // 상인 1
	Enemy,  // 몬스터 출현 2
	Boss	// 보스 방
};

class Dungeon
{
public:
	static constexpr int DungeonSize = 10; // 10개의 층에 한층당 10개의 방
	Dungeon() // 던전의 방마다 랜덤한 RoomType 등장
	{
		for (int y = 0; y < DungeonSize; y++) // y는 층의 수
		{
			for (int x = 0; x < DungeonSize; x++) // x는 방의 수
			{
				int RandomRoom = rand() % 6; 
				if(x == 9)
					RandomRoom = 6;
				switch (RandomRoom)
				{
				case 0:
					Rooms[y][x] = RoomType::Empty; // 비중 1의 빈방
					break;
				case 1:
					Rooms[y][x] = RoomType::Healer; // 비중 1의 치유사 출현
					break;
				case 2:
					Rooms[y][x] = RoomType::trap; // 비중 1의 함정 방
					break;
				case 3:
					Rooms[y][x] = RoomType::trader; // 비중 1의 상인
					break;
				case 4:
				case 5:				
					Rooms[y][x] = RoomType::Enemy; // 비중 2의 몬스터 출현
					break;
				default:
					Rooms[y][x] = RoomType::Boss; // 보스 방 x 가 9일때 RandomRoom을 6으로 설정해서 이곳으로 들어오도록 설정
					break;
				} 
			}
		}
	}
	~Dungeon() = default;
	// X와 Y의 값을 파라매터로 받는 Getter 함수를 만들어 Rooms 배열의 InX , InY 값의 enum 값을 리턴 받기
	inline const RoomType GetRoomType(int InX,int InY) const { return Rooms[InX][InY]; } 
private:
	RoomType Rooms[DungeonSize][DungeonSize]; // 층과 방 배열선언
};

