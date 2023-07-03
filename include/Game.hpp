//
// Created by laugh on 03/07/2023.
//

#ifndef TETRIS_GAME_HPP
#define TETRIS_GAME_HPP


#include <string>

class Game {
public:
    Game(int width, int height, const std::string& title);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;

    bool GameShouldClose() const;

    void Tick();

private:
    void Draw();
    void Update();
};


#endif //TETRIS_GAME_HPP
