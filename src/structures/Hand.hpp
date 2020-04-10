#ifndef CYSKAT_HAND_HPP
#define CYSKAT_HAND_HPP

#include "structures/Card.hpp"
#include "types.hpp"

namespace cyskat
{

    /**
     * @brief The deck of a player.
     */
    class Hand
    {
    private:
        Vector<Card> m_cards;

    public:
        Hand() = default;
        explicit Hand(const Vector<Card>& cards);
        virtual ~Hand() = default;

        Uint8        size() const;
        Uint8        take(const Vector<Card>& cards);
        Vector<Card> cards() const;

        void print() const;
    };

    class Skat final : public Hand
    {
    public:
        Skat() = default;
        explicit Skat(const Vector<Card>& cards);
    };

}  // namespace cyskat

#endif  // CYSKAT_HAND_HPP
