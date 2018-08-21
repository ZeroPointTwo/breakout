#ifndef BREAKOUT_COMPONENT_H
#define BREAKOUT_COMPONENT_H

namespace Breakout
{
  class BaseComponent
  {
    public:
    BaseComponent();
    virtual ~BaseComponent() = 0;

    virtual bool Init()           = 0;
    virtual void Update(float dt) = 0;
    virtual void UnInit()         = 0;

    private:
  };

  class RenderComponent : public BaseComponent
  {
    public:
    BaseComponent();
    virtual ~BaseComponent() = 0;

    virtual bool Init()           = 0;
    virtual void Update(float dt) = 0;
    virtual void UnInit()         = 0;
  };

  class PositionComponent : public BaseComponent
  {
    public:
    BaseComponent();
    virtual ~BaseComponent() = 0;

    virtual bool Init()           = 0;
    virtual void Update(float dt) = 0;
    virtual void UnInit()         = 0;
  };

}  // namespace Breakout

#endif  // !BREAKOUT_COMPONENT_H
