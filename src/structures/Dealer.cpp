#include "structures/Dealer.hpp"

namespace cyskat
{

    Vector<Card> Dealer::give(Uint8 cards)
    {
        Vector<Card> result;
        cards = std::min(cards, static_cast<Uint8>(m_cards.size()));
        while(cards--)
        {
            result.emplace_back(m_cards.front());
            m_cards.erase(m_cards.begin());
        }
        return result;
    }

    Uint8 Dealer::take(const Vector<Card>& cards)
    {
        m_cards.insert(m_cards.end(), cards.begin(), cards.end());
        return m_cards.size();
    }

    Uint8 Dealer::size() const
    {
        return m_cards.size();
    }

    void Dealer::print() const
    {
        std::cout << "Dealer: (" << std::setw(2) << (int)size() << ") \n";
        for(const auto& card : m_cards)
        {
            card.print(" - ");
        }
    }

}  // namespace cyskat
