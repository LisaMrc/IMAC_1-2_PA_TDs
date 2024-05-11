#include "node.hpp"
#include <vector>

int main()
{
    Node* root = create_node(5);
    root->Node::insert(3);

    std::vector<int> to_insert {7, 2, 4, 6, 8, 1, 9, 0};

    for (int i : to_insert)
    {
        root->Node::insert_from_root(i);
    }

    root->Node::display_infixe();

    std::vector<Node const *>vec = root->Node::prefixe();
    int sum{};

    for (Node const * i : vec)
    {
        sum += i->value;
    }
    
    std::cout << root->Node::height() << std::endl;

    return 0;
}