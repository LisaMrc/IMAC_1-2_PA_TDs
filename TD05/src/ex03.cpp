#include <string>
#include <vector>
#include <iostream>

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;

    int hash() const 
    {
        int cardHash{};

        switch (kind)
        {
        case CardKind::Heart:
            cardHash = 0 + static_cast<int>(value);
            break;

        case CardKind::Diamond:
            cardHash = 13 + static_cast<int>(value);
            break;

        case CardKind::Club:
            cardHash = 26 + static_cast<int>(value);
            break;

        case CardKind::Spade:
            cardHash = 39 + static_cast<int>(value);
            break;

        default:
            break;
        }
        return cardHash;
    }
};

bool operator==(Card a, Card b)
{
    return a.kind == b.kind && a.value == b.value;
}

namespace std 
{
    // faire en sorte que la bibliothèque standard utilise notre méthode hash pour la structure Card
    template<>
    struct hash<Card>
    {
        size_t operator()(Card const& card) const
        {
            return card.hash();
        }
    };
}

std::vector<Card> get_cards(size_t const size)
{
    // générer une liste de cartes aléatoires
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card)
{
    std::string name {};
    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }

    return name;
}

int main()
{
    std::vector<Card> deck = get_cards(100);

    for (Card card : deck)
    {
        std::cout << card_name(card) << std::endl;
    }
}