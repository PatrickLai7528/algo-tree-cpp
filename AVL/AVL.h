#include "BST_for_AVL.h"

template<typename Key, typename Value>
class AVLTree : public BST<Key, Value> {

    using typename BST<Key, Value>::Node;
    using BST<Key, Value>::root;
    using BST<Key, Value>::count;

    struct AVLNode : public Node {
        int height;
        AVLNode(Key key, Value value)
            : Node(key, value), height(1) {}
    };

public:
    void insert(Key key, Value value) {
        root = insert(dynamic_cast<AVLNode*>(root), key, value);
    }

private:
    int getHeight(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalanceFactor(AVLNode* node) {
        return node ? getHeight((AVLNode*)node->left) - getHeight((AVLNode*)node->right) : 0;
    }

    void updateHeight(AVLNode* node) {
        node->height = 1 + max(getHeight((AVLNode*)node->left), getHeight((AVLNode*)node->right));
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = (AVLNode*)y->left;
        AVLNode* T2 = (AVLNode*)x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = (AVLNode*)x->right;
        AVLNode* T2 = (AVLNode*)y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* insert(AVLNode* node, Key key, Value value) {
        if (!node) {
            count++;
            return new AVLNode(key, value);
        }

        if (key < node->key)
            node->left = insert((AVLNode*)node->left, key, value);
        else if (key > node->key)
            node->right = insert((AVLNode*)node->right, key, value);
        else
            node->value = value;

        updateHeight(node);

        int balance = getBalanceFactor(node);

        // LL
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        // RR
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        // LR
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate((AVLNode*)node->left);
            return rightRotate(node);
        }
        // RL
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate((AVLNode*)node->right);
            return leftRotate(node);
        }

        return node;
    }
};
