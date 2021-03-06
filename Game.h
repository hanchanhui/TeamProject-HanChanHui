#include "SDL.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>



class Game{
  public:
    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvent();
    void clean();
    
  
    static Game* Instance()
    {
      if (s_pInstance == 0){
        s_pInstance = new Game();
        return s_pInstance;
      }
      return s_pInstance;
    }
    SDL_Renderer* getRenderer() const {return m_pRenderer; } ;
    
  private:
    Game() {}
    
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;

    std::vector<GameObject*> m_gameObjects;

    bool m_bRunning;
    int m_currentFrame;

    static Game* s_pInstance;
   
};

typedef Game TheGame;