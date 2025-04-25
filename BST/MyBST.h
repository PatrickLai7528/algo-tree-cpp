#include "IBST.h"

template <typename Key, typename Value>
class BST : public IBST<Key, Value>
{

    private:
    // 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node
    {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value)
        {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }

        Node(Node *node)
        {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    Node *root; // 根节点
    int count;  // 树中的节点个数
public :
    int size() override {
        return this->count;
    }

    int 
};