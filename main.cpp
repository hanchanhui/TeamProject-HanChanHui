#include "Game.h"
Game* g_game = 0;

// 10월 22일 (유일 객체, 추상 클래스) 완료

int main(int argc, char* args[])
{
  if(TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
  {
    while (TheGame::Instance()->running()){
      TheGame::Instance()->handleEvent();
      TheGame::Instance()->update();
      TheGame::Instance()->render();
      SDL_Delay(10);
    }
  }else {
    std::cout << "game init failure " << SDL_GetError() << "\n";
    return -1;
  }
  TheGame::Instance()->clean();
  return 0;
  
}