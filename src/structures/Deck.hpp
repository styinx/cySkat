#ifndef CYSKAT_DECK_HPP
#define CYSKAT_DECK_HPP

#include "structures/Card.hpp"

namespace cyskat
{

    /**
     * @brief All cards before dealing.
     */
    class Deck
    {
    private:
        static Deck s_deck;

        Deck();

    public:
        Vector<Card> m_cards;

        void init();

    public:
        static Deck& getInstance();
        virtual ~Deck() = default;

        Uint8        size() const;
        Vector<Card> give(Uint8 cards = 1);

        void print() const;
    };

}  // namespace cyskat

#endif  // CYSKAT_DECK_HPP
