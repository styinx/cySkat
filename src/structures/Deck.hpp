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
        Vector<Card> m_cards;

    public:
        Deck();
        virtual ~Deck() = default;

        void         init();
        Uint8        size() const;
        Vector<Card> give(Uint8 cards = 1);

        void print() const;
    };

}  // namespace cyskat

#endif  // CYSKAT_DECK_HPP
