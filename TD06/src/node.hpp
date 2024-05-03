#pragma once
#include <string>
#include <iostream>
#include <vector>

struct Node
{
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const
    {
        if (this->left == nullptr && this->right == nullptr)
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
            right_height = right->height();
        }

        if (left_height >= right_height)
        {
            return left_height + 1;
        }

        else
        {
            return right_height + 1;
        }
    } 

    void Node::delete_childs() 
    {
        if(left)
        {
            left->delete_childs();
            delete this->left;
            left = nullptr;
        }

        if(right)
        {
            right->delete_childs();
            delete this->right;
            right = nullptr;
        }
    }

    void Node::display_infixe() const 
    {
        if(left) left->display_infixe();
        if(right) right->display_infixe();

        std::cout << this->value << std::endl;
    }

    std::vector<Node const *> Node::prefixe()  const 
    {
        std::vector<Node const*> node_list{};
        node_list.push_back(this);

       if (!is_leaf())
        {
            if(left) left->prefixe();
            if(right) right->prefixe();
        }

        return node_list;
    }
};

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);

Node* create_node(int value);