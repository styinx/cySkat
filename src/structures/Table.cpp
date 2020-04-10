#include "Table.hpp"

namespace cyskat
{

    Table::Table()
        : m_deck(std::make_shared<Deck>())
        , m_skat(std::make_shared<Skat>())
        , m_dealer(std::make_shared<Dealer>())
    {
        m_players.emplace_back(std::make_shared<Player>());
        m_players.emplace_back(std::make_shared<Player>());
        m_players.emplace_back(std::make_shared<Player>());
    }

    void Table::reset()
    {
        m_deck->init();
        if(m_dealer->take(m_deck->give(32)) != 32)
        {
            // err
        }

        if(m_players.size() == 3)
        {
            // All players get 3 cards.
            for(auto& player : m_players)
            {
                if(player->hand().take(m_dealer->give(3)) != 3)
                {
                    // err
                }
            }

            // Set the skat
            if(m_skat->take(m_dealer->give(2)) != 2)
            {
                // err
            }

            // All players get 4 cards.
            for(auto& player : m_players)
            {
                if(player->hand().take(m_dealer->give(4)) != 4)
                {
                    // err
                }
            }

            // All players get 3 cards.
            for(auto& player : m_players)
            {
                if(player->hand().take(m_dealer->give(3)) != 3)
                {
                    // err
                }
            }
        }

        // Deck should be empty
        if(m_deck->size() != 0)
        {
            // err
        }

        // Dealer should have no cards
        if(m_dealer->size() != 0)
        {
            // err
        }

        // All players should have 10 cards
        for(auto& player : m_players)
        {
            if(player->hand().size() != 10)
            {
                // err
            }
        }

        // Skat should have 2 cards
        if(m_skat->size() != 2)
        {
            // err
        }
    }

} // namespace cyskat
