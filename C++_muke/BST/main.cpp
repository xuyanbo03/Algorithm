#include <iostream>
#include <queue>
#include <cassert>

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

        Node(Node *node) {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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
        destroy(root);
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

    bool contain(Key key) {
        return contain(root, key);
    }

    Value *search(Key key) {
        return search(root, key);
    }

    //深度优先遍历
    //前序遍历
    void preOrder() {
        preOrder(root);
    }

    //中序遍历
    void inOrder() {
        inOrder(root);
    }

    //后序遍历
    void postOrder() {
        postOrder(root);
    }

    //广度优先遍历：层序遍历
    void levelOrder() {
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *node = q.front();
            q.pop();
            cout << node->key << endl;
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }

    //寻找最小键值
    Key minimum() {
        assert(count != 0);
        Node *minNode = minimum(root);
        return minNode->key;
    }

    //寻找最大键值
    Key maximum() {
        assert(count != 0);
        Node *maxNode = maximum(root);
        return maxNode->key;
    }

    //从二叉树中删除最小值所在节点
    void removeMin() {
        if (root) {
            root = removeMin(root);
        }
    }

    //从二叉树中删除最大值所在节点
    void removeMax() {
        if (root) {
            root = removeMax(root);
        }
    }

    //从二叉树中删除键值为key的节点
    void remove(Key key) {
        root = remove(root, key);
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

    //查找以node为根的二叉搜索树中是否包含键值为key的节点
    bool contain(Node *node, Key key) {
        if (node == NULL) {
            return false;
        }
        if (node->key == key) {
            return true;
        } else if (node->key > key) {
            return contain(node->left, key);
        } else {
            return contain(node->right, key);
        }
    }

    //查找以node为根的二叉搜索树中键值为key的节点的value
    Value *search(Node *node, Key key) {
        if (node == NULL) {
            return NULL;
        }
        if (node->key == key) {
            return &(node->value);
        } else if (node->key > key) {
            return search(node->left, key);
        } else {
            return search(node->right, key);
        }
    }

    //前序遍历
    void preOrder(Node *node) {
        if (node != NULL) {
            cout << node->key << endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    //中序遍历
    void inOrder(Node *node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->key << endl;
            inOrder(node->right);
        }
    }

    //后序遍历
    void postOrder(Node *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->key << endl;
        }
    }

    void destroy(Node *node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            count--;
        }
    }

    //返回最小键值
    Node *minimum(Node *node) {
        if (node->left == NULL) {
            return node;
        }
        return minimum(node->left);
    }

    //返回最大键值
    Node *maximum(Node *node) {
        if (node->right == NULL) {
            return node;
        }
        return maximum(node->right);
    }

    //从二叉树中删除最小值所在节点
    //返回删除节点后新的二叉搜索树的根
    Node *removeMin(Node *node) {
        if (node->left == NULL) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    //从二叉树中删除最大值所在节点
    //返回删除节点后新的二叉搜索树的根
    Node *removeMax(Node *node) {
        if (node->right == NULL) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
        }
        node->right = removeMin(node->right);
        return node;
    }

    //从二叉树中删除键值为key的节点
    //返回删除节点后新的二叉搜索树的根
    Node *remove(Node *node, Key key) {
        if (node == NULL) {
            return NULL;
        }
        if (key < node->key) {
            node->left = remove(node->left, key);
            return node;
        } else if (key > node->key) {
            node->right = remove(node->right, key);
            return node;
        } else {
            //key == node->key
            if (node->left == NULL) {
                Node *rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            if (node->right == NULL) {
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }

            //node->left != NULL&&node->right != NULL
            Node *successor = new Node(minimum(node->right));
            count++;
            successor->right = removeMin(node->right);
            successor->left = node->left;
            delete node;
            count--;
            return successor;
        }
    }
};

int main() {
    return 0;
}