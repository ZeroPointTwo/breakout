#ifndef BREAKOUT_COMPONENT_H
#define BREAKOUT_COMPONENT_H

#include <memory>
#include "SFML/System/Vector2.hpp"

namespace sf
{
    class Shape;
}

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
        RenderComponent(const std::shared_ptr<sf::Shape>& inRenderObject);
        virtual ~RenderComponent();

        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

      private:
        std::shared_ptr<sf::Shape> RenderObject;
    };

    class PositionComponent : public BaseComponent
    {
      public:
        PositionComponent();
        virtual ~PositionComponent();

        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

        void                SetPosition(const sf::Vector2f& newPosition);
        const sf::Vector2f& GetPosition() const;

      private:
        sf::Vector2f Position;
    };

}  // namespace Breakout

#endif  // !BREAKOUT_COMPONENT_H
