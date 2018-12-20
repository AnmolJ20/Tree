//This program creates the tree level wise

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

TreeNode* createLevelBT();
void printLeaves(TreeNode* root);

int main() {
	TreeNode* root = createLevelBT();
	printLeaves(root);
}

TreeNode* createLevelBT() {
	queue<TreeNode*> q;
	int input;
	cin >> input;
	TreeNode* root = new TreeNode(input);
	q.push(root);

	while (!q.empty()) {
		TreeNode* cur = q.front();
		q.pop();
		cin >> input;
		if (input != -1) {
			cur->left = new TreeNode(input);
			q.push(cur->left);
		}

		else 
			cur->left = NULL;

		cin >> input;
		if (input != -1) {
			cur->right = new TreeNode(input);
			q.push(cur->right);
		}

		else 
			cur->right = NULL;
	}

	return root;
}

void printLeaves(TreeNode* root) {
	if (root == NULL)
		return;
	if (root->left == NULL and root->right == NULL) {
		cout << root->data << " ";
		return;
	}
	printLeaves(root->left);
	printLeaves(root->right);
}
