#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    string to_string() {
        ostringstream os;
        to_stringRec(root, os);
        return os.str();
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void to_stringRec(Node* node, ostringstream& os) {
        if (node == nullptr) {
            os << "NULL\n";
            return;
        }

        os << node->value << '\n';
        to_stringRec(node->left, os);
        to_stringRec(node->right, os);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(30);
    bst.insert(15);
    bst.insert(4);
    // The NULLs suggest that we're looking at the output of a traversal,
    // not input for the tree. So they are not inserted.
    bst.insert(20);
    bst.insert(18);
    bst.insert(19);
    bst.insert(35);
    bst.insert(32);
    bst.insert(38);

    cout << bst.to_string();
    return 0;
}
