#include "structures/Deck.hpp"
#include "structures/Dealer.hpp"
#include "structures/Hand.hpp"

int main(int argc, char ** argv)
{
    using cyskat::Deck;
    using cyskat::Dealer;
    using cyskat::Hand;

    Dealer dealer{};
    Deck deck = Deck::getInstance();

    auto s = cyskat::c_card_name;

    Hand hand1{};
    Hand hand2{};
    Hand hand3{};

    dealer.take(deck.give(40));

    hand1.take(dealer.give());
    hand2.take(dealer.give());
    hand3.take(dealer.give());

    return 0;
}
