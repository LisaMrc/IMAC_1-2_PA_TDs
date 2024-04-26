#include "node.hpp"
#include <string>
#include <iostream>

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left)
{
    if (node.right)
    {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }

    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    
    if (node.left)
    {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node)
{
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value)
{
    Node* root { new Node {value, nullptr, nullptr}};
}