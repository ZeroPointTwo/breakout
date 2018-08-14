#ifndef BREAKOUT_OBJECT_H
#define BREAKOUT_OBJECT_H

#include "SDL2/SDL.h"

namespace Breakout
{
  class Object
  {
    public:
    Object();
    virtual ~Object() = default;

    const SDL_Point& GetPos() const;
    void             SetPos(const SDL_Point& pos);

    private:
    SDL_Point pos;
  };
}  // namespace Breakout

#endif  // !BREAKOUT_OBJECT_H
