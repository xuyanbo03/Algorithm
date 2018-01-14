#include <iostream>

using namespace std;

template<typename Key, typename Value>
class BST {
private:
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count;

public:
    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() {
        //TODO
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void insert(Key key, Value value) {
        root = insert(root, key, value);
    }

private:
    //向以node为根的二叉搜索树中插入节点(key,value)
    //返回插入新节点后的二叉搜索树的根
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }
        if (key == node->key) {
            node->value = value;
        } else if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else {
            node->right = insert(node->right, key, value);
        }
        return node;
    }
};

int main() {
    return 0;
}