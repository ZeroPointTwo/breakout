#include "Object.h"

using Breakout::Object;

Object::Object() : _pos({0, 0}) {}

const SDL_Point& Object::GetPos() const { return _pos; }

void Object::SetPos(const SDL_Point& pos) { _pos = pos; }
