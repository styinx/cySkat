#include "structures/Deck.hpp"

namespace cyskat
{
    Deck::Deck()
    {
        init();
    }

    void Deck::init()
    {
        for(SUIT suit = SUIT::DIAMONDS; suit <= SUIT::CLUBS; ++suit)
        {
            for(CARD card = CARD::SEVEN; card <= CARD::ACE; ++card)
            {
                m_cards.emplace_back(Card{card, suit});
            }
        }
    }

    Uint8 Deck::size() const
    {
        return m_cards.size();
    }

    Vector<Card> Deck::give(Uint8 cards)
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

    void Deck::print() const
    {
        std::cout << "Deck: (" << std::setw(2) << (int)size() << ") \n";
        for(const auto& card : m_cards)
        {
            card.print(" - ");
        }
    }

} // namespace cyskat
