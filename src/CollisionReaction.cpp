#include "./CollisionReaction.h"
#include "Math.h"

using namespace Breakout::Collision;

void Bounce(CollisionChannel channel, Object* owner, const Object* collidedAgainst, const Hit& hit)
{
    if (owner == nullptr || collidedAgainst == nullptr)
    {
        return;
    }

    channel;

    //sf::Vector2f speedMultipliers(1.f, 1.f);
    //speedMultipliers.y *= -1.f;
    //speedMultipliers.x *= -1.f;
    //if (const PaddleMovementComponent* paddle = collidedAgainst->GetComponent<PaddleMovementComponent>())
    //{

    //    //adjust factors

    //    if (CollisionComponent* otherCollision = collidedAgainst->GetComponent<CollisionComponent>())
    //    {
    //        //todo:  fix me.  Learn collision
    //        //otherCollision->
    //    }
    //}

    MovementComponent* ownerMoveCmp = owner->GetComponent<MovementComponent>();
    if (ownerMoveCmp != nullptr)
    {
        ownerMoveCmp->SetVelocity(Reflect(ownerMoveCmp->GetVelocity(), hit.normal));
    }
}

bool CollisionReaction::GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, CollisionReactionFunc& outFunc)
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
     reactionMap(std::map<std::string, CollisionReactionFunc>())
{
    reactionMap["Bounce"] = Bounce;
}

void CollisionReaction::Init(void)
{
    // TODO: create collision reaction definitions
    //reactionMap["bounce"] = []({})
}
