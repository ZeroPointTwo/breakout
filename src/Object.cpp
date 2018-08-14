#include "Object.h"

using namespace Breakout;

Object::Object() : pos({0, 0}) {}

const SDL_Point& Object::GetPos() const { return pos; }

void Object::SetPos(const SDL_Point& _pos) { pos = _pos; }
