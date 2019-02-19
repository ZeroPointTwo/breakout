#include "./CollisionReaction.h"

using namespace Breakout::Collision;

void Bounce(CollisionChannel channel)
{

}

bool CollisionReactions::GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, std::function<void(CollisionChannel)>& outFunc)
{
    bool ret = false;

    auto iter = reactionMap.find(reactionName);
    if (iter != reactionMap.end())
    {
        outFunc = iter->second;
        ret = true;
    }

    return ret;
}

CollisionReactions::CollisionReactions() :
     reactionMap(std::map<std::string, std::function<void(Collision::CollisionChannel)>>())
{
    reactionMap["Bounce"] = Bounce;
}

void CollisionReactions::Init(void)
{
    // TODO: create collision reaction definitions
    //reactionMap["bounce"] = []({})
}
