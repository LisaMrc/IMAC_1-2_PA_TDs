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
    return root;
}

bool Node::is_leaf() const
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
    if (this == nullptr)
    {
        return 0;
    }
    else
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
    std::cout << this->value << std::endl;
    if(right) right->display_infixe();
}

std::vector<Node const *> Node::prefixe() const 
{
    std::vector<Node const*> nodes{};
    nodes.push_back(this);
    
    if(left)
    {
        auto left_nodes {left->prefixe()};
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }

    if(right)
    {
        auto right_nodes {right->prefixe()};
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }

    return nodes;
}

Node*& most_left(Node*& node)
{
    if (node->left != nullptr)
    {
        most_left(node->left);
    }
    else
    {
        return node;
    }

    return node;
}

bool remove(Node*& node, int value)
{  
    if (value == node->value && node->is_leaf())
    {
        // On supprime le nœud courant
        delete node;
        // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
        // Ainsi le parent du nœud courant aura un pointeur vers nullptr
        node = nullptr;
        // on retourne true car la suppression a été effectuée
        return true;
    }
    else if (value == node->value && (node->right == nullptr && node->left != nullptr))
    {
        auto tmp_L_Value = node->left->value;
        node->left->delete_childs();
        node->value = tmp_L_Value;
    }
    else if (value == node->value && ((node->right != nullptr && node->left == nullptr)))
    {
        auto tmp_R_Value = node->right->value;
        node->left->delete_childs();
        node->value = tmp_R_Value;
    }
    else if (value == node->value && (node->right != nullptr && node->left != nullptr))
    {
        auto tmp_most_L_value = most_left(node->right)->value;
        remove(most_left(node->right), tmp_most_L_value);
        node->value = tmp_most_L_value;
    }
    else if (value > node->value)
    {
        remove(node->right, value);
    }
    else if (value < node->value)
    {
        remove(node->left, value);
    }
    else
    {
        return false;
    }

    return true;
}

void delete_tree(Node* node)
{
    if (node == nullptr)
    {
        std::cout << "Tree already deleted" << std::endl;
        return;
    }

    // first delete both subtrees if needed
    if(node->left)
    {
      delete_tree(node->left); 
    }

    if(node->right) {
      delete_tree(node->right); 
    }

    // delete the node
    std::cout << "Deleting node : " << node->value << std::endl; 
    delete node;
}

void Node::insert_from_root(int value)
{
    if (value < this->value)
    {
        if (this->left == nullptr)
        {
            Node* new_node { create_node(value) };
            this->left = new_node;
        }
        else
        {
            this->left->insert_from_root(value);
        }
    }
    else
    {
        if (this->right == nullptr)
        {
            Node* new_node { create_node(value) };
            this->right = new_node;
        }
        else
        {
            this->right->insert_from_root(value);
        }
    }
}