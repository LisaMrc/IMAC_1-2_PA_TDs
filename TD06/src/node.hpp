#pragma once
#include <string>

struct Node
{
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const
    {
        if (this->right == nullptr && this->right == nullptr)
            return true;
        return false; 
    }

    void Node::insert(int value)
    {
        if (value < Node::value)
        {
            left = create_node(value);
        }
        else
        {
            right = create_node(value);
        }
    }

    int Node::height() const
    {
        int left_height{0};
        int right_height{0};

        if (this->left != nullptr)
        {
            left_height = left->height();
        }

        if (this->right != nullptr)
        {
            left_right = left->height();
        }

        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }

    void Node::delete_childs()
    {
        delete 
    }
};

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);

Node* create_node(int value);