#include <iostream>
using namespace std;
class Node {
public:
int data;
Node* left;
Node* right;
Node(int value) {
data = value;
left = NULL;
right = NULL;
}
};
int main() {
Node* root = new Node(10);
root->left = new Node(5);
root->right = new Node(15);
cout << "Root : " << root->data << endl;
cout << "Left Child : " << root->left->data << endl;
cout << "Right Child : " << root->right->data << endl;
delete root->left;
delete root->right;
delete root;

6

return 0;
}
