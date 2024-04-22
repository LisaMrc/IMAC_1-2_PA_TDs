#include <string>
#include <vector>

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

    int hash()
    {
        int cardHash{};

        int ck = static_cast<int>(CardKind);
        int cv = static_cast<int>(CardValue);
        cardHash = (ck * cv + 1) % 52;

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