#include <SDL.h>
#include <iostream>
#include <ctime>

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning = false;

bool init(const char* title, int xpos, int ypos, int height, int width, int flags){
  if(SDL_Init(SDL_INIT_EVERYTHING) >= 0)
  {
    g_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);

    if(g_pWindow != 0){
      g_pRenderer = SDL_CreateRenderer(g_pWindow, -1,0);
    }
  }
  else{
    return false;
  }
  
  return true;
}

void ColorChange(){// 색깔을 랜덤으로 바꾸었습니다
  SDL_SetRenderDrawColor(g_pRenderer, rand() % 255, rand() % 255, rand() % 255, 255);
  SDL_Delay(1000);
}

void render(){
  SDL_RenderClear(g_pRenderer); 
  SDL_RenderPresent(g_pRenderer);
}

int main(int argc, char* args[])
{
  int count = 0;

  if(init("HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 100, SDL_WINDOW_SHOWN)){
    g_bRunning = true;
  }
  else{
    return 1;
  }
  

  while(g_bRunning){
    if(count == 5){ // 카운터가 5가 넘었을때 크기가 바뀌게끔 만들었습니다.
      if(init("HelloSDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,   640, 480, SDL_WINDOW_SHOWN))
      {
        g_bRunning = true;
      }
      else{
        return 1;
      }
    }
  
    ColorChange();// 색깔 함수를 호출 합니다
    render();
    count++;
  }

  SDL_Quit();
  return 0;
}