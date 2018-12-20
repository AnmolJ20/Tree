//Prints tree from different views i.e. top, bottom, left, right

#include <iostream>
#include <set>
#include <map>
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
	//cout << "Enter the left child of " << root->data << ":\t";
	root->Left = CreateTree();
	//cout << "Enter the right child of " << root->data << ":\t";
	root->Right = CreateTree();
	return root;
}

//calculate horizontal distance 
void topView(TreeNode* root, set<int> s, int cur) {
	if (root == NULL)
		return;
	if (s.count(cur) == 0) {
		cout << root->data << endl;
		s.insert(cur);
	}

	topView(root->Left, s, cur-1);
	topView(root->Right, s, cur+1);
}

void bottomView(TreeNode* root, map<int, TreeNode*>& hash, int cur) {
	if (root == NULL)
		return;

	hash[cur] = root;
	bottomView(root->Left, hash, cur-1);
	bottomView(root->Right, hash, cur+1);
}

int levelSoFar = -1;

void leftView(TreeNode* root, int curLev) {
	if (root == NULL)
		return;
	if (curLev > levelSoFar) {
		cout << root->data;
		levelSoFar++;
	}

	leftView(root->Left, curLev+1);
	leftView(root->Right, curLev+1);
}

void rightView(TreeNode* root, int curLev) {
	if (root == NULL)
		return;

	if (curLev > levelSoFar) {
		cout << root->data << " ";
		levelSoFar++;
	}

	rightView(root->Right, curLev+1);
	rightView(root->Left, curLev+1);
}

int main() {
	TreeNode* root = CreateTree();

	//Top View
	set<int> s;
	topView(root, s, 0);

	//Bottom View
	map<int, TreeNode*> hash;
	bottomView(root, hash, 0);
  for (auto view : hash) {
    cout << view->second << " ";
  }
  
  //Left View
	leftView(root, 0);
  
  //Right View
	rightView(root, 0);
}
