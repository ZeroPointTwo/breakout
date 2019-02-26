#pragma once
#include <map>
#include <functional>

namespace Breakout
{
    namespace Collision
    {
        enum class CollisionChannel
        {
            CC_NONE = 0
        };

        class CollisionReaction
        {
        public:
            CollisionReaction();
            void Init(void);
            bool GetCollisionReaction(const std::string& reactionName, CollisionChannel channel, std::function<void(CollisionChannel, Object*, const Object*)>& outFunc);

        private:
            std::map<std::string, std::function<void(CollisionChannel, Object*, const Object*)>> reactionMap;
        };
    }
}