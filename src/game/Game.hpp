#ifndef CYSKAT_GAME_HPP
#define CYSKAT_GAME_HPP

#include "types.hpp"

namespace cyskat
{

    enum class GAME_STATE : Uint8
    {
        START,
        MENU,
        DEAL,
        BID,
        DROP,
        PLAY,
        RESULT
    };

    class Game
    {
    };

} // namespace cyskat

#endif  // CYSKAT_GAME_HPP
