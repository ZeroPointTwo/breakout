#pragma once
#include <map>
#include <functional>
//TODO: Compile this, then finish integrating CollisionReactions
namespace Breakout::Collision
{
    enum class CollisionChannel
    {
        CC_NONE = 0
    };

    class CollisionReactions
    {
    public:
        CollisionReactions();
        void Init(void);
        bool GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, std::function<void(CollisionChannel)>& outFunc);

    private:
        std::map<std::string, std::function<void(CollisionChannel)>> reactionMap;
    };
}