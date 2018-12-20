#include <iostream>
#include <queue>
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

TreeNode* insertBST(TreeNode* root, int number);
TreeNode* deleteFromBst(TreeNode* root, int key);
TreeNode* getSuccessor(TreeNode* root, TreeNode* &successorParent);
void preorder(TreeNode* root);

int main() {
    int testCases;
    TreeNode* root = NULL;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int numberOfElements;
        cin >> numberOfElements;

        int input;

        for (int j = 0; j < numberOfElements; j++) {
            cin >> input;
            root = insertBST(root, input);
        }

        cin >> numberOfElements;
        for (int j = 0; j < numberOfElements; j++) {
            cin >> input;
            root = deleteFromBst(root, input);
        }

        preorder(root);
    }
}

TreeNode* insertBST(TreeNode* root, int number) {
    if (root == NULL) {
        TreeNode* ptr = new TreeNode(number);
        return ptr;
    }

    if (number < root->data)
        root->left = insertBST(root->left, number);
    else
        root->right = insertBST(root->right, number);

    return root;
}

TreeNode* deleteFromBst(TreeNode* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteFromBst(root->left, key);
        return root;
    }

    if (key > root->data) {
        root->right = deleteFromBst(root->right, key);
        return root;
    }

    if (key == root->data) {
        // root has to be deleted
        // if root has only left child
        if (root->left == NULL) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        }

        if (root->right == NULL) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }

        // root has 2 children
        TreeNode* successorParent = NULL;
        TreeNode* successor = getSuccessor(root, successorParent);
        if (successorParent == root) {
            successor->right = root->right;
            delete root;
            return successor;
        }
        else {
            successorParent->right = successor->left;
            successor->left = root->left;
            successor->right = root->right;
            delete root;
            return successor;
        }
    }
}

TreeNode* getSuccessor(TreeNode* root, TreeNode* &successorParent) {
    if (root == NULL) return root;
    successorParent = root;
    TreeNode* successor = root->left ? root->left : NULL;
    while (successor && successor->right) {
        successorParent = successor;
        successor = successor->right;
    }
    return successor;
}

void preorder(TreeNode* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
