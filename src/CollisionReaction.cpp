#include "./CollisionReaction.h"

using namespace Breakout::Collision;

//todo:  move this to correct place
sf::Vector2f operator* (const sf::Vector2f& a, const sf::Vector2f& b)
{
    return sf::Vector2f(a.x * b.x, a.y * b.y);
}


void Bounce(CollisionChannel channel, Object* owner, const Object* collidedAgainst)
{
    if (owner == nullptr || collidedAgainst == nullptr)
    {
        return;
    }

    channel;

    sf::Vector2f speedMultipliers(1.f, 1.f);
    if (const PaddleMovementComponent* paddle = collidedAgainst->GetComponent<PaddleMovementComponent>())
    {
        //adjust factors
    }

    MovementComponent* vel = owner->GetComponent<MovementComponent>();
    if (vel != nullptr)
    {
        vel->SetVelocity(vel->GetVelocity() * speedMultipliers);
    }
}

bool CollisionReaction::GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, std::function<void(CollisionChannel, Object*, const Object*)>& outFunc)
{
    channel;
    bool ret = false;

    auto iter = reactionMap.find(reactionName);
    if (iter != reactionMap.end())
    {
        outFunc = iter->second;
        ret = true;
    }

    return ret;
}

CollisionReaction::CollisionReaction() :
     reactionMap(std::map<std::string, std::function<void(Collision::CollisionChannel, Object*, const Object*)>>())
{
    reactionMap["Bounce"] = Bounce;
}

void CollisionReaction::Init(void)
{
    // TODO: create collision reaction definitions
    //reactionMap["bounce"] = []({})
}
