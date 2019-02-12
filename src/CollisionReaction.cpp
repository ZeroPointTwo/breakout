#include "./CollisionReaction.h"

using namespace Breakout::Collision;

bool CollisionReactions::GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, std::function<void(const std::string&, CollisionChannel)>& outFunc)
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

void CollisionReactions::Init(void)
{
    // TODO: create collision reaction definitions
    //reactionMap["bounce"] = []({})
}
