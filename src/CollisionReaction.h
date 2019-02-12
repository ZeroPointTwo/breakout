#pragma once
#include <map>
#include <functional>

namespace Breakout::Collision
{
    enum class CollisionChannel
    {
        CC_NONE = 0
    };

    class CollisionReactions
    {
    public:
        void Init(void);
        bool GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, std::function<void(const std::string&, CollisionChannel)>& outFunc);

    private:
        std::map<std::string, std::function<void(const std::string&, CollisionChannel)>> reactionMap;
    };
}