#pragma once

#include <memory>
#include "SFML/Graphics.hpp"

namespace Breakout
{
    class Game
    {
      public:
        virtual ~Game(){};

        virtual bool Init(std::shared_ptr<sf::RenderWindow>& sfWindow) = 0;
        virtual void Update()                                          = 0;
        virtual void BeginGame()                                       = 0;
        virtual void EndGame()                                         = 0;

        std::shared_ptr<sf::RenderWindow> _sfWindow;
    };

    class BreakoutGame : public Game
    {
      public:
        virtual ~BreakoutGame(){};

        bool Init(std::shared_ptr<sf::RenderWindow>& sfWindow) override;

        void Update() override{};

        void BeginGame() override;

        void EndGame() override{};
    };
}  // namespace Breakout
