#include <iostream>
#include <iomanip>
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

// GLOBAL VARIABLES
TreeNode* lca = NULL;
bool aPresent, bPresent;

TreeNode* createBT();
void findLcaBT(TreeNode* root, int a, int b);

int main() {
    TreeNode* root = createBT();
    int a, b;
    cin >> a >> b;
    findLcaBT(root, a, b);
    cout << lca->data;
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

void findLcaBT(TreeNode* root, int a, int b) {
    if (root == NULL) return;

    findLcaBT(root->left, a, b);
    if (aPresent && bPresent) return;   // lca was there in left subtree

    if (root->data == a) aPresent = true;
    if (root->data == b) bPresent = true;

    bool maybe = false;
    if (aPresent or bPresent) {
        maybe = true;
    }
    
    findLcaBT(root->right, a, b);

    if (maybe && aPresent && bPresent) {lca = root; return;}
}
