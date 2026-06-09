#include <iostream>
#include <vector>
using namespace std;
class TreeNode {
public:
string data;
vector<TreeNode*> children;
TreeNode(string value) {
data = value;
}
};
int main() {
TreeNode* root = new TreeNode("A");

3

TreeNode* b = new TreeNode("B");
TreeNode* c = new TreeNode("C");
TreeNode* d = new TreeNode("D");
root->children.push_back(b);
root->children.push_back(c);
root->children.push_back(d);
cout << "Root : " << root->data << endl;
return 0;
}
