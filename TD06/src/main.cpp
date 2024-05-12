#include "node.hpp"
#include <vector>

int main()
{
    std::cout << "\n\n ____ EX 2 ____ \n\n" << std::endl;

    // Q1
    Node* root{create_node(5)};
    root->insert(3);
    std::vector<int> to_insert {7, 2, 4, 6, 8, 1, 9, 0};
    for (int i : to_insert)
    {
        root->insert_from_root(i);
    }

    pretty_print_left_right(*root);

    // Q2
    std::cout << "\n\nInfix display ____" << std::endl;
    root->display_infixe();

    // Q4
    std::vector<Node const *>vec = root->prefixe();
    int sum{};
    for (Node const * i : vec)
    {
        sum += i->value;
    }
    std::cout << "\n\nSum of node values : " << sum << std::endl;
    
    // Q5
    std::cout << "Tree height : " << root->height() << std::endl;

    return 0;
}