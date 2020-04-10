#include "game/Game.hpp"

int main(int argc, char ** argv)
{
    using cyskat::Game;

    Game game = Game();

    game.run();

    return 0;
}
