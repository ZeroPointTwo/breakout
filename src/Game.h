#pragma once

#include <memory>
#include "Object.h"
#include "ObjectFactory.h"
#include "SFML/Graphics.hpp"

namespace Breakout
{
    class Game
    {
      public:
        virtual ~Game(){};

        virtual bool Init(std::shared_ptr<sf::RenderWindow>& sfWindow) = 0;
        virtual void Update(float deltaTime)                           = 0;
        virtual void BeginGame()                                       = 0;
        virtual void EndGame()                                         = 0;

        virtual std::vector<std::shared_ptr<Object>>& GetGameObjects()
        {
            return _gameObjects;
        }

      protected:
        std::shared_ptr<sf::RenderWindow>    _sfWindow;
        std::vector<std::shared_ptr<Object>> _gameObjects;
        std::unique_ptr<ObjectFactory>       objectFactory;
    };

    class BreakoutGame : public Game
    {
      public:
        virtual ~BreakoutGame(){};

        bool Init(std::shared_ptr<sf::RenderWindow>& sfWindow) override;

        void Update(float deltaTime) override;

        void BeginGame() override;

        void EndGame() override{};
    };
}  // namespace Breakout
