#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createBT();
int balanced(TreeNode* root, bool& flag);

int main() {
    TreeNode* root = createBT();
    bool flag = true;
    balanced(root, flag);
    cout << boolalpha << flag;
}

TreeNode* createBT() {
    int x;
    cin >> x;

    TreeNode* root = new TreeNode(x);

    bool child;

    cin >> boolalpha >> child;
    if (child == true)
        root->left = createBT();
    cin >> boolalpha >> child;
    if (child == true)
        root->right = createBT();

    return root;
}

int balanced(TreeNode* root, bool& flag) {
    if (root == NULL)
        return 0;
    int left = balanced(root->left, flag);
    int right = balanced(root->right, flag);

    if (abs(left - right) > 1)
        flag = false;
    return max(left, right) + 1;
}
