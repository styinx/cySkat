#include "structures/Hand.hpp"

namespace cyskat
{
    Hand::Hand(const Vector<Card>& cards)
        : m_cards(cards)
    {
    }

    Uint8 Hand::size() const
    {
        return m_cards.size();
    }

    Uint8 Hand::take(const Vector<Card>& cards)
    {
        m_cards.insert(m_cards.end(), cards.begin(), cards.end());
        return m_cards.size();
    }

    Vector<Card> Hand::cards() const
    {
        return cyskat::Vector<Card>();
    }

    void Hand::print() const
    {
        std::cout << "Hand: (" << std::setw(2) << (int)size() << ") \n";
        for(const auto& card : m_cards)
        {
            card.print(" - ");
        }
    }

    Skat::Skat(const Vector<Card>& cards)
        : Hand(cards)
    {
    }

}  // namespace cyskat
