#ifndef BREAKOUT_COMPONENT_H
#define BREAKOUT_COMPONENT_H

#include "InputSystem.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"

#include <memory>

namespace sf
{
    class Shape;
}

namespace Breakout
{
    class Object;

    enum EComponentType
    {
        CT_INVALID         = -1,
        CT_RENDERCOMPONENT = 0,
        CT_POSITIONCOMPONENT,
        CT_INPUTCOMPONENT,
        CT_COLLISIONCOMPONENT,
        CT_MOVEMENTCOMPONENT,
        CT_PADDLEMOVEMENTCOMPONENT,
        CT_END,
        CT_COUNT = CT_END
    };

    class BaseComponent
    {
      public:
        BaseComponent(const std::weak_ptr<Object>& _owner);
        virtual ~BaseComponent()
        {
        }

        virtual bool                  Init()           = 0;
        virtual void                  Update(float dt) = 0;
        virtual void                  UnInit()         = 0;
        virtual EComponentType        GetType();
        virtual std::weak_ptr<Object> GetOwner();

      protected:
        EComponentType        type;
        std::weak_ptr<Object> owner;
    };

    class RenderComponent : public BaseComponent
    {
      public:
        RenderComponent(const std::weak_ptr<Object>& _owner, const std::shared_ptr<sf::Shape>& inRenderObject);
        virtual ~RenderComponent() override;

        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

        sf::Shape* GetShape();

      protected:
        std::shared_ptr<sf::Shape> RenderObject;
    };

    class PositionComponent : public BaseComponent
    {
      public:
        PositionComponent(const std::weak_ptr<Object>& _owner);
        virtual ~PositionComponent() override;

        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

        void                SetPosition(const sf::Vector2f& newPosition);
        const sf::Vector2f& GetPosition() const;

      protected:
        sf::Vector2f Position;
    };

    class InputComponent : public BaseComponent
    {
      public:
        InputComponent(const std::weak_ptr<Object>& _owner);
        virtual ~InputComponent() = default;
        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

        void       SetInputs(GameInputs inputs);
        GameInputs GetInputs();

      private:
        GameInputs currentInputs;
    };

    class MovementComponent : public BaseComponent
    {
      public:
        MovementComponent(const std::weak_ptr<Object>& _owner);
        virtual ~MovementComponent() = default;
        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

      protected:
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
    };

    class PaddleMovementComponent : public MovementComponent
    {
      public:
        PaddleMovementComponent(const std::weak_ptr<Object>& _owner, float _speed, float _boundLeft, float _boundRight);
        virtual ~PaddleMovementComponent() = default;
        virtual bool Init() override;
        virtual void Update(float dt) override;
        virtual void UnInit() override;

      protected:
        float speed;
        float boundLeft;
        float boundRight;
    };

    class CollisionComponent : public BaseComponent
    {
      public:
        CollisionComponent(const std::weak_ptr<Object>& _owner, const std::shared_ptr<sf::Shape> inCollisionShape);

        virtual ~CollisionComponent() override;
        virtual bool    Init() override;
        virtual void    Update(float dt) override;
        virtual void    UnInit() override;
        sf::Rect<float> CollisionComponent::GetTransformed();

        virtual bool Intersects(CollisionComponent* other) const;

      protected:
        sf::Rect<float> collisionRect;
    };
}  // namespace Breakout

#endif  // !BREAKOUT_COMPONENT_H
