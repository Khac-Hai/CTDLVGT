#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *left;
    Node *right;
};

void DeleteTree(Node *root){
    if (root == NULL){
        return;
    }
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
}
// duyệt trc
std::string PreorderPrint(Node *root){
    if(root == NULL){
        return "";
    }
    string Preorder;
    Preorder += root->data;
    Preorder += PreorderPrint(root->left);
    Preorder += PreorderPrint(root->right);
    return Preorder;
}
// duyệt giữa
std::string InorderPrint(Node *root){
    if (root == NULL){
        return "";
    }
    string Inorder;
    Inorder += InorderPrint(root->left);
    Inorder += root->data;
    Inorder += InorderPrint(root->right);
    return Inorder;
}
// duyêtj sau
std::string PostorderPrint(Node *root){
    if (root == NULL){
        return "";
    }
    string Postorder;
    Postorder += PostorderPrint(root->left);
    Postorder += PostorderPrint(root->right);
    Postorder += root->data;
    return Postorder;
}

int CountLeaves(Node *root){
    if(root == NULL) {
        return 0;
    }

    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else{
        return CountLeaves(root->left) + CountLeaves(root->right);
    }    
}

Node *Search(Node *root, const char c){
    if(root == NULL) {
        return NULL;
    }
    Node *leftResult = Search(root->left, c);
    if(leftResult == NULL) {
        return leftResult;
    }
    Node *rightResult = Search(root->right, c);
    return rightResult;   
}

int main(){
    Node *root = new Node{'*', new Node{'a', NULL, NULL}, new Node{'+', new Node{'b', NULL, NULL}, new Node{'c', NULL, NULL}}};

    DeleteTree(root);

    cout << "Preorder: " << PreorderPrint(root) << endl;
    cout << "Inorder: " << InorderPrint(root) << endl;
    cout << "Postorder: " << PostorderPrint(root) << endl;

    cout << "Leaf count of the tree is: " << CountLeaves(root) << endl;

    char searchValue = 'c';
    Node *result = Search(root, searchValue);

    if(result != NULL){
        cout << "Node with value " << searchValue << " found at depth" << result << endl;
    } 
    else{
        cout << "Node with value " << searchValue << " not found" << endl;
    }
    return 0;
}