#include <iostream>
#include <queue>
#include <set>
using namespace std;

class TreeNode {
public:
	int data;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int d) {
		data = d;
		Left = NULL;
		Right = NULL;
	}
};

int HeightOfTree(const TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = HeightOfTree(root->Left);
	int right = HeightOfTree(root->Right);
	return max(left ,right) + 1;
}

TreeNode* CreateTree() {
	int x; cin >> x;
	if (x == -1) {
		return NULL;
	}

	TreeNode* root = new TreeNode(x);
	cout << "Enter the left child of " << root->data << ":\t";
	root->Left = CreateTree();
	cout << "Enter the right child of " << root->data << ":\t";
	root->Right = CreateTree();
	return root;
}

int main() {
	TreeNode* root = CreateTree();
	cout << HeightOfTree(root);
}
