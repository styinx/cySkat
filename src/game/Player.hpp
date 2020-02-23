#ifndef CYSKAT_PLAYER_HPP
#define CYSKAT_PLAYER_HPP

#include "types.hpp"
#include "structures/Hand.hpp"

namespace cyskat
{

    enum class PLAYER_TYPE : Uint8
    {
        GIVE,
        HEAR,
        SAY
    };

    enum class BID : Uint8
    {
        EIGHTEEN     = 0x12,
        TWENTY       = 0x14,
        TWENTYTWO    = 0x16,
        TWENTYTHREE  = 0x17,
        TWENTYFOUR   = 0x18,
        TWENTYSEVEN  = 0x1B,
        THIRTY       = 0x1E,
        THIRTYTHREE  = 0x21,
        THIRTYFIVE   = 0x23,
        THIRTYSIX    = 0x24,
        FOURTY       = 0x28,
        FOURTYFOUR   = 0x2C,
        FOURTYFIVE   = 0x2D,
        FOURTYSIX    = 0x2E,
        FOURTYEIGHT  = 0x30,
        FIFTY        = 0x32,
        FIFTYFOUR    = 0x36,
        FIFTYFIVE    = 0x37,
        FIFTYNINE    = 0x3C,
        SIXTY        = 0x3D,
        SIXTYTHREE   = 0x3B,
        SIXTYSIX     = 0x3E,
        SEVENTY      = 0x46,
        SEVENTYTWO   = 0x48,
        SEVENTYSEVEN = 0x4D,
        EIGHTY       = 0x50,
        EIGHTYONE    = 0x51,
        EIGHTYFOUR   = 0x54,
        EIGHTYEIGHT  = 0x58,
        NINETY       = 0xFA,
        NINETYSIX    = 0x60,
        NINETYNINE   = 0x63,
    };

    class Player
    {
    private:
        Hand        m_hand;
        PLAYER_TYPE m_type;
    };

    class AI : public Player
    {
    private:
    };

} // namespace cyskat

#endif  // CYSKAT_PLAYER_HPP
