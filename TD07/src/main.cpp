#include "node.hpp"
#include <vector>

int main()
{
    Node* root = create_node(5);
    root->insert(3);

    std::vector<int> to_insert {7, 2, 4, 6, 8, 1, 9, 0};

    for (int i : to_insert)
    {
        root->insert_from_root(i);
    }

    root->display_infixe();

    std::vector<Node const *>vec = root->prefixe();
    int sum{};

    for (Node const * i : vec)
    {
        sum += i->value;
    }
    
    std::cout << root->height() << std::endl;

    return 0;
}