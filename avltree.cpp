#include <iostream>
#include <stack>

using namespace std;

class AVLNode
{
    friend class AVLTree;

private:
    int key_;
    int height_;

    AVLNode* left_node_;
    AVLNode* right_node_;

public:
    AVLNode(int key, AVLNode* left_node=nullptr, AVLNode* right_node=nullptr)
    {
        key_= key;
        left_node_ = left_node;
        right_node_ = right_node;
        height_ = 0;
    }
    ~AVLNode()
    {

    }
};

class AVLTree
{
private:
    AVLNode* root_;

    AVLNode* right_rotation(AVLNode* p)
    {
        AVLNode* new_p = p->left_node_;
        p->left_node_ = new_p->right_node_;
        new_p->right_node_ = p;

        p->height_ = max(sub_tree_height(p->left_node_), sub_tree_height(p->right_node_));
        new_p->height_ = max(sub_tree_height(new_p->left_node_), sub_tree_height(new_p->right_node_));

        return new_p;
    }

    AVLNode* left_rotation(AVLNode* p)
    {
        AVLNode* new_p = p->right_node_;
        p->right_node_ = new_p->left_node_;
        new_p->left_node_ = p;

        p->height_ = max(sub_tree_height(p->left_node_), sub_tree_height(p->right_node_));
        new_p->height_ = max(sub_tree_height(new_p->left_node_), sub_tree_height(new_p->right_node_));

        return new_p;
    }

    AVLNode* maximum_node_of_tree(AVLNode* node)
    {
        if(node->right_node_ == nullptr) return node;
        else return maximum_node_of_tree(node->right_node_);
    }

    int sub_tree_height(AVLNode* node)
    {
        return (node != nullptr)?node->height_ + 1:0;
    }

    AVLNode* insert_(int key, AVLNode* node)
    {
        if(node == nullptr)
        {
            return node = new AVLNode(key);
        }

        if(key < node->key_) 
        {
            node->left_node_ = insert_(key, node->left_node_);
        }
        else if(key > node->key_) 
        {
            node->right_node_ = insert_(key, node->right_node_);
        }
        else if(node->key_ == key) return node;

        int height_L = sub_tree_height(node->left_node_);
        int height_R = sub_tree_height(node->right_node_);

        node->height_ = max(height_L, height_R);
        
        int balance_factor = height_L - height_R;

        if(balance_factor > 1)//L
        {
            if(key < node->left_node_->key_)//L
            {
                return node = right_rotation(node);
            }
            else//R
            {
                node->left_node_ = left_rotation(node->left_node_);
                return node = right_rotation(node);
            }
        }
        else if(balance_factor < -1)//R
        {
            if(key < node->right_node_->key_)//L
            {
                node->right_node_ = right_rotation(node->right_node_);
                return node = left_rotation(node);
            }
            else//R
            {
                return node = left_rotation(node);
            }
        }

        return node;
    }

    AVLNode* pop_(int key, AVLNode* node)
    {
        if(node == nullptr) return nullptr;

        if(key < node->key_) 
        {
            node->left_node_ = pop_(key, node->left_node_);
        }
        else if(key > node->key_) 
        {
            node->right_node_ = pop_(key, node->right_node_);
        }
        else //if(node->key_ == key) 
        {
            if(node->left_node_ == nullptr && node->right_node_ == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if(node->left_node_ == nullptr && node->right_node_ != nullptr)
            {
                AVLNode* sub_right_tree = node->right_node_;
                delete node;
                return sub_right_tree;
            }
            else if(node->left_node_ != nullptr && node->right_node_ == nullptr)
            {
                AVLNode* sub_left_tree = node->left_node_;
                delete node;
                return sub_left_tree;
            }
            else            
            {
                AVLNode* maxium_node_in_sub_left_tree = maximum_node_of_tree(node->left_node_);
                node->key_ = maxium_node_in_sub_left_tree->key_;
                node->left_node_ = pop_(maxium_node_in_sub_left_tree->key_, node->left_node_);
            }
        }

        int height_L = sub_tree_height(node->left_node_);
        int height_R = sub_tree_height(node->right_node_);

        node->height_ = max(height_L, height_R);
        
        int balance_factor = height_L - height_R;

        if(balance_factor > 1)//L
        {
            if(sub_tree_height(node->left_node_->left_node_) > sub_tree_height(node->left_node_->right_node_))//L
            {
                return node = right_rotation(node);
            }
            else//R
            {
                node->left_node_ = left_rotation(node->left_node_);
                return node = right_rotation(node);
            }
        }
        else if(balance_factor < -1)//R
        {
            if(sub_tree_height(node->right_node_->left_node_) > sub_tree_height(node->right_node_->right_node_))//L
            {
                node->right_node_ = right_rotation(node->right_node_);
                return node = left_rotation(node);
            }
            else//R
            {
                return node = left_rotation(node);
            }
        }

        return node;
    }

public:

    AVLTree()
    {
        root_ = nullptr;
    }

    ~AVLTree()
    {

    }

    void insert(int key)
    {
        root_ = insert_(key, root_);
    }

    void pop(int key)
    {
        root_ = pop_(key, root_);
    }
};

using namespace std;

int main()
{
    AVLTree avltree;


    avltree.insert(20);
    avltree.insert(25);
    avltree.insert(15);
    avltree.insert(10);
    avltree.insert(30);
    avltree.insert(5);
    avltree.insert(35);
    avltree.insert(67);
    avltree.insert(43);
    avltree.insert(21);
    avltree.insert(10);
    avltree.insert(89);
    avltree.insert(38);
    avltree.insert(69);
    avltree.pop(5);
    avltree.pop(35);
    avltree.pop(65);
    avltree.pop(89);
    avltree.pop(43);
    avltree.pop(88);
    avltree.pop(20);
    avltree.pop(38);

  
    return 0;
}
