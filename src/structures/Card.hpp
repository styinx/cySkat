#ifndef CYSKAT_CARD_HPP
#define CYSKAT_CARD_HPP

#include "types.hpp"

#include <iomanip>
#include <iostream>

namespace cyskat
{

    enum class SUIT : Uint8
    {
        DIAMONDS = 0x00,
        HEARTS   = 0x01,
        SPADES   = 0x02,
        CLUBS    = 0x03,
    };

    enum class CARD : Uint8
    {
        SEVEN = 0x00,
        EIGHT = 0x01,
        NINE  = 0x02,
        QUEEN = 0x03,
        KING  = 0x04,
        TEN   = 0x05,
        JACK  = 0x06,
        ACE   = 0x07
    };

    static const Map<SUIT, Uint8> c_suit_value = {
        {SUIT::DIAMONDS, 0x09},
        {SUIT::HEARTS, 0xA0},
        {SUIT::SPADES, 0xB0},
        {SUIT::CLUBS, 0xC0},
    };

    static const Map<CARD, Uint8> c_card_value = {
        {CARD::SEVEN, 0x00},
        {CARD::EIGHT, 0x00},
        {CARD::NINE, 0x00},
        {CARD::JACK, 0x02},
        {CARD::QUEEN, 0x03},
        {CARD::KING, 0x04},
        {CARD::TEN, 0x0A},
        {CARD::ACE, 0x0B},
    };

    static const Map<SUIT, String> c_suit_name = {
        {SUIT::DIAMONDS, "Diamonds"},
        {SUIT::HEARTS, "Hearts"},
        {SUIT::SPADES, "Spades"},
        {SUIT::CLUBS, "Clubs"},
    };

    static const Map<CARD, String> c_card_name = {
        {CARD::SEVEN, "Seven"},
        {CARD::EIGHT, "Eight"},
        {CARD::NINE, "Nine"},
        {CARD::JACK, "Jack"},
        {CARD::QUEEN, "Queen"},
        {CARD::KING, "King"},
        {CARD::TEN, "Ten"},
        {CARD::ACE, "Ace"},
    };

    template<typename E>
    E operator++(E& x)
    {
        x = static_cast<E>(static_cast<typename std::underlying_type<E>::type>(x) + 1);
        return x;
    }

    class Card final
    {
    private:
        CARD m_card;
        SUIT m_suit;

    public:
        explicit Card(const CARD card, const SUIT suit);
        virtual ~Card() = default;

        bool operator<(const Card& other) const;
        bool operator>(const Card& other) const;

        void print(const String& prefix = "") const;
    };

}  // namespace cyskat

#endif  // CYSKAT_CARD_HPP
