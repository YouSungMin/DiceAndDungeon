#define _CRTDBG_MAP_ALLOC
//#define TEST_MODE
#include <crtdbg.h>
#include <iostream>
#include "GameManager.h"
int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    srand(time(NULL)); //시드 값 변경

#ifdef TEST_MODE
    GameManager test;
    test.DungeonTest();
#endif //

#ifndef TEST_MODE
    GameManager Game; // 게임 매니저 객체 생성
    Game.GameStart(); // 객체를 통한 게임시작
#endif // !TEST_MODE 
}

