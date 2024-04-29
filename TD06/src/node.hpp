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
        if (is_leaf)
        {
            delete this;
        }
        else if (this->right == nullptr && this->right != nullptr)
        {
            int tmp_value = this->right;
            delete this->right;
            value = tmp_value;
        }
        else if (this->right != nullptr && this->right == nullptr)
        {
            int tmp_value = this->left;
            delete this->right;
            value = tmp_value;
        }
        else
        {
            int tmp_value {(this->left > this->right) ? this->left : this->right };

            
        }

// Le nœud à supprimer a deux fils: il faut trouver le nœud qui va remplacer le nœud à supprimer tout en conservant la relation d'ordre entre les nœuds.
    }
};

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
void pretty_print_left_right(Node const& node);

Node* create_node(int value);