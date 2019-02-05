#include "Game.h"
#include "Component.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

namespace
{
    nlohmann::json LoadJsonFromFile(const std::string& filename)
    {
        nlohmann::json parsed_json = {};

        FILE* file = fopen(filename.c_str(), "r");
        Assert(file != nullptr, "Failed to open {}", filename);

        if (file)
        {
            fseek(file, 0, SEEK_END);
            auto file_size = ftell(file);
            Assert(file_size > 0, "Empty file");

            fseek(file, 0, SEEK_SET);

            std::string buffer(file_size, 0);
            fread((void*)buffer.data(), file_size, 1, file);

            fclose(file);

            parsed_json = nlohmann::json::parse(buffer.c_str());
            Assert(!parsed_json.empty(), "Failed to parse JSON");
        }

        return parsed_json;
    }
}  // namespace

bool Breakout::BreakoutGame::Init(std::shared_ptr<sf::RenderWindow>& sfWindow)
{
    bool isSuccess = false;

    _sfWindow = sfWindow;

    objectFactory = std::make_unique<ObjectFactory>();

    // make an object that would otherwise be made by a mythical objectfactory
    // Object testObject{};

    // Make a circle just because
    // auto testCircle = std::make_shared<sf::CircleShape>(1.f);
    // testCircle->setScale(
    //    sf::Vector2f(static_cast<float>(50) * 0.5f,
    //        static_cast<float>(50) * 0.5f));  // Scale the circle to make an ellipses
    // testCircle->setFillColor(sf::Color::Green);
    //
    // auto renderComponent = std::make_shared<RenderComponent>(testCircle);
    // testObject.AddComponent(renderComponent);
    //_gameObjects.push_back(testObject);

    return isSuccess;
}

void Breakout::BreakoutGame::BeginGame()
{
    EndGame();
    Init(_sfWindow);

    const auto level_filename = "../../data/level_data.json";
    auto       level          = LoadJsonFromFile(level_filename);

    Assert(level.size() > 0, "Failed to load level data from %s.", level_filename);
    if (level.size() == 0)
    {
        return;
    }

    std::vector<std::string> level_data    = level["level_data"];
    std::int32_t             brick_width   = level["brick_width"];
    std::int32_t             brick_height  = level["brick_height"];
    std::int32_t             brick_gap     = level["brick_gap"];
    float                    paddle_width  = level["paddle_width"];
    float                    paddle_height = level["paddle_height"];
    float                    paddle_x      = level["paddle_x"];
    float                    paddle_y      = level["paddle_y"];
    float                    paddle_speed  = level["paddle_speed"];
    float                    ball_radius   = level["ball_radius"];
    float                    ball_vel_x    = level["ball_vel_x"];
    float                    ball_vel_y    = level["ball_vel_y"];

    Assert(brick_width > 0, "Invalid brick width: {}", brick_width);
    Assert(brick_height > 0, "Invalid brick height: {}", brick_height);

    float       numBricks   = (float)level_data[0].length();
    float       boardWidth  = brick_width * numBricks + brick_gap * (numBricks - 1);
    const float Offset      = 20;
    float       boardHeight = paddle_y + Offset;
    // set up the paddle
    _gameObjects.push_back(objectFactory->CreatePaddle(
        paddle_x, paddle_y, paddle_width, paddle_height, paddle_speed, 0.f, boardWidth, sf::Color::Magenta));

    sf::Vector2f position(0.0f, 0.0f);

    // top
    _gameObjects.push_back(objectFactory->CreateWall(0, 0, boardWidth, 2, sf::Color::White));
    // left
    _gameObjects.push_back(objectFactory->CreateWall(0, 0, 2, boardHeight, sf::Color::White));
    // bottom
    _gameObjects.push_back(objectFactory->CreateWall(0, boardHeight, boardWidth, 2, sf::Color::White));
    // right
    _gameObjects.push_back(objectFactory->CreateWall(boardWidth, 0, 2, boardHeight, sf::Color::White));

    int offset = 15;

    for (auto& row : level_data)
    {
        position.x = 0.0f;

        for (auto element : row)
        {
            switch (element)
            {
                case 'R':
                    _gameObjects.push_back(objectFactory->CreateBrick(
                        position.x, position.y, (float)brick_width, (float)brick_height, sf::Color::Red));
                    break;
                case '-':
                    break;
                default:
                    break;
            }

            position.x += brick_width + brick_gap;
        }

        position.y += brick_height + brick_gap;
    }

    // test ball
    _gameObjects.push_back(objectFactory->CreateBall(paddle_x + paddle_width * 0.5f,
                                                     paddle_y - offset,
                                                     ball_radius,
                                                     sf::Color::Cyan,
                                                     sf::Vector2f(ball_vel_x, ball_vel_y)));

    // for (int i = 0; i < 10; ++i)
    //{
    //    for (int j = 0; j < 10; ++j)
    //    {
    //        // formatting
    //        _gameObjects.push_back(objectFactory->TestCreateBrick(i * 51.f, j * 21.f, sf::Color::Red));
    //    }
    //}
}

void Breakout::BreakoutGame::Update(float deltaTime)
{
    for (auto object : _gameObjects)
    {
        object->Update(deltaTime);
    }
}
