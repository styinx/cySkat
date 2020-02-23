#include "structures/Card.hpp"

namespace cyskat
{

    Card::Card(const CARD card, const SUIT suit)
        : m_card(card)
        , m_suit(suit)
    {
    }



    bool Card::operator<(const Card& other) const
    {
        return m_card < other.m_card && m_suit <= other.m_suit;
    }

    bool Card::operator>(const Card& other) const
    {
        return m_card > other.m_card && m_suit >= other.m_suit;
    }

    void Card::print(const String& prefix) const
    {
        std::cout << prefix << c_card_name.at(m_card) << " of " << c_suit_name.at(m_suit) << "\n";
    }

}  // namespace cyskat
