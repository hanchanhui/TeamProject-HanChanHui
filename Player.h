#include "SDLGameObject.h"
#include "SDL.h"



class Player : public SDLGameObject
{
  public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};