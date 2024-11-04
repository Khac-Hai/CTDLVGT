#include <iostream>
struct Node {
    char data;
    Node* left;
    Node* right;
};

Node* CreateNode(Node* parent, const char value, const char lr) {
    Node* node = new Node;
    node->left = node->right = nullptr;
    node->data = value;

    if (parent == nullptr) {
        return node;
    } else {
        Node* ptr;
        if (lr == 'l')
            ptr = parent->left;
        else if (lr == 'r') {
            ptr = parent->right;
        } else {
            std::cerr << "Error lr = " << " not supported." << std::endl;
            delete node;
            return nullptr;
        }
        if (ptr != nullptr) {
            std::cerr << "Error: can not create node with value " << value << std::endl;
            delete node;
            return nullptr;
        }
        if (lr == 'l') {
            parent->left = node;
        } else if (lr == 'r') {
            parent->right = node;
        }
        return node;
    }
}

void PreorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << ", ";
    PreorderPrint(root->left);
    PreorderPrint(root->right);
}

void InorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }
    InorderPrint(root->left);
    std::cout << root->data << ", ";
    InorderPrint(root->right);
}

void PostorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }
    PostorderPrint(root->left);
    PostorderPrint(root->right);
    std::cout << root->data << ", ";
}

char toUpperCase(char c) {
    if (std::islower(c)) {
        return std::toupper(c);
    }
    return c;
}

void UppercaseTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    root->data = toUpperCase(root->data);
    UppercaseTree(root->left);
    UppercaseTree(root->right);
}

int main() {
    Node* root = CreateNode(nullptr, 'a', 'r');
    Node* ptr = root;
    ptr = CreateNode(ptr, 'b', 'l');
    CreateNode(ptr, 'd', 'l');
    CreateNode(ptr, 'e', 'r');
    ptr = ptr->left;
    CreateNode(ptr, 'h', 'l');
    CreateNode(ptr, 'i', 'r');

    ptr = CreateNode(root, 'c', 'r');
    CreateNode(ptr, 'g', 'r');
    ptr = CreateNode(ptr, 'f', 'l');
    CreateNode(ptr, 'k', 'l');
    CreateNode(ptr, 'l', 'r');
    ptr = root->right->right;
    CreateNode(ptr, 'm', 'r');

    std::cout << "Kiem tra cay ban dau" << std::endl;
    PreorderPrint(root);
    std::cout << std::endl;

    UppercaseTree(root);
    std::cout << "Kiem tra cay sau khi chuyen ve chu hoa" << std::endl;
    PreorderPrint(root);
    std::cout << std::endl;

    return 0;
}