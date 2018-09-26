#ifndef BREAKOUT_COMPONENT_H
#define BREAKOUT_COMPONENT_H

#include "SFML/System/Vector2.hpp"

#include <memory>

namespace sf
{
    class Shape;
}

namespace Breakout
{
    enum EComponentType
    {
        CT_INVALID         = -1,
        CT_RENDERCOMPONENT = 0,
        CT_POSITIONCOMPONENT,
        CT_END,
        CT_COUNT = CT_END
    };

    class BaseComponent
    {
      public:
        BaseComponent();
        virtual ~BaseComponent() {}

        virtual bool           Init()           = 0;
        virtual void           Update(float dt) = 0;
        virtual void           UnInit()         = 0;
        virtual EComponentType GetType();

      protected:
        EComponentType type;
    };

    class RenderComponent : public BaseComponent
    {
      public:
        RenderComponent(const std::shared_ptr<sf::Shape>& inRenderObject);
        virtual ~RenderComponent() override;

        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

      protected:
        std::shared_ptr<sf::Shape> RenderObject;
    };

    class PositionComponent : public BaseComponent
    {
      public:
        PositionComponent();
        virtual ~PositionComponent() override;

        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

        void                SetPosition(const sf::Vector2f& newPosition);
        const sf::Vector2f& GetPosition() const;

      protected:
        sf::Vector2f Position;
    };

}  // namespace Breakout

#endif  // !BREAKOUT_COMPONENT_H
