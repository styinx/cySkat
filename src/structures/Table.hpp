#ifndef CYSKAT_TABLE_HPP
#define CYSKAT_TABLE_HPP

#include "Dealer.hpp"
#include "Deck.hpp"
#include "game/Player.hpp"

namespace cyskat
{
    class Table final
    {
    private:
        SharedPtr<Deck>           m_deck;
        SharedPtr<Skat>           m_skat;
        SharedPtr<Dealer>         m_dealer;
        Vector<SharedPtr<Player>> m_players;

    public:
        Table();
        virtual ~Table() = default;

        void reset();
    };
}  // namespace cyskat

#endif  // CYSKAT_TABLE_HPP
