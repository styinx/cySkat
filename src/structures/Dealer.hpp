#ifndef CYSKAT_DEALER_HPP
#define CYSKAT_DEALER_HPP

#include "structures/Card.hpp"

namespace cyskat
{

    class Dealer
    {
    private:
        // random stuff
        Vector<Uint8> m_cards_given;
        Vector<Card>  m_cards;

    public:
        Vector<Card> give(Uint8 cards = 1);
        Uint8        take(const Vector<Card>& cards);
        Uint8        size() const;

        void print() const;
    };

}  // namespace cyskat

#endif  // CYSKAT_DEALER_HPP
