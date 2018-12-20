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

void levelPrint(TreeNode* root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(q.empty() == false) {
		TreeNode* cur = q.front();
		q.pop();
		if (cur == NULL) {
			cout << endl;
			if (q.empty() == false)
				q.push(NULL);
			continue;
		}
		cout << cur->data << " ";
		if (cur->Left)
			q.push(cur->Left);
		if (cur->Right)
			q.push(cur->Right);
	}
}

int main() {
	TreeNode* root = CreateTree();
  levelPrint(root);
}
