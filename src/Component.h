#ifndef BREAKOUT_COMPONENT_H
#define BREAKOUT_COMPONENT_H

#include "InputSystem.h"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "CollisionReaction.h"

#include <memory>

namespace sf
{
    class Shape;
}

namespace Breakout
{
    class Object;

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
        virtual std::weak_ptr<Object> GetOwner();

      protected:
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
        MovementComponent(const std::weak_ptr<Object>& _owner, const sf::Vector2f& vel);
        virtual ~MovementComponent() = default;
        virtual bool         Init() override;
        virtual void         Update(float dt) override;
        virtual void         UnInit() override;

        inline void SetVelocity(const sf::Vector2f& newVelocity)
        {
            velocity = newVelocity;
        }

        inline void SetAcceleration(const sf::Vector2f& newAcceleration)
        {
            acceleration = newAcceleration;
        }

        virtual sf::Vector2f GetVelocity() const
        {
            return velocity;
        }
        virtual sf::Vector2f GetAcceleration() const
        {
            return acceleration;
        }

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
        CollisionComponent(const std::weak_ptr<Object>& _owner, const std::shared_ptr<sf::Shape> inCollisionShape, const std::string& inCollisionName );

        virtual ~CollisionComponent() override;
        virtual bool    Init() override;
        virtual void    Update(float dt) override;
        virtual void    UnInit() override;
        sf::Rect<float> GetTransformed();

        virtual bool Intersects(CollisionComponent* other);
        virtual void InjectReaction(const std::string& reactionId, Collision::CollisionChannel channel);

        inline const std::string& ReadCollisionReaction() const
        {
            return collisionReaction;
        }

      protected:
        sf::Rect<float> collisionRect;
        std::string collisionReaction;
    };
}  // namespace Breakout

#endif  // !BREAKOUT_COMPONENT_H
