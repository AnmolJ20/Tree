#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <climits>

class node {
public:
	int value;
	node* left;
	node* right;
	node(int d) {
		value = d;
		left = NULL;
		right = NULL;
	}
};

node* CreateTree() {
	int x; std::cin >> x;
	if (x == -1) {
		return NULL;
	}

	node* root = new node(x);
	//std::cout << "Enter the left child of " << root->data << ":\t";
	root->left = CreateTree();
	//std::cout << "Enter the right child of " << root->data << ":\t";
	root->right = CreateTree();
	return root;
}

node* arrToTree(int arr[], int be, int en) {
    if (be > en) { return NULL; /* no elements in the array*/ }

    int* idx = std::max_element(arr + be, arr + en + 1);
    int i = idx - arr;
    node* root = new node(arr[i]);
    root->left = arrToTree(arr, be, i - 1);
    root->right = arrToTree(arr, i + 1, en);
    return root;
}

int left = 0;
int right = 0;
int height = 0;

void extreme_points(node *root, int w, int h) {
	if (root == nullptr)
		return;

	left = (w < left) ? w : left;
	right = (w > right) ? w : right;
	height = (h > height) ? h : height;
	extreme_points(root->left, w-1, h+1);
	extreme_points(root->right, w+1, h+1);
}

void tree_points(node *root, std::map<std::pair<int, int>, int> &points, std::queue<std::pair<int, int> > &links, int x, int y) {
	points[std::make_pair(x, y)] = root->value;
	if (root->left) {
		links.push(std::make_pair(x-1, y+1));
		tree_points(root->left, points, links, x-2, y+2);
	}

	if (root->right) {
		links.push(std::make_pair(x+1, y+1));
		tree_points(root->right, points, links, x+2, y+2);
	}
}

void tree_print(node *root) {
	extreme_points(root, 0, 0);
	left = abs(left);

	std::map<std::pair<int, int>, int> points;
	std::queue<std::pair<int, int> > links;
	tree_points(root, points, links, left*2, 0);

	int row = height * 2 + 1;
	int column = (left + right) * 2 + 1;
	int tree[row][column];

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			tree[i][j] = INT_MIN;
		}
	}

	for (std::pair<std::pair<int, int>, int> point : points) {
		tree[point.first.second][point.first.first] = point.second;
	}

	while (!links.empty()) {
		std::pair<int, int> link = links.front();
		links.pop();
		tree[link.second][link.first] = INT_MAX;
	}

	std::cout << std::endl;
	for (int i = 0; i < row; i++) {
		std::cout << "  ";
		for (int j = 0; j < column; j++) {
			if (tree[i][j] == INT_MAX) 
				std::cout << (char)249;
			else if (tree[i][j] != INT_MIN)
				std::cout << tree[i][j];
			else
				std::cout << ' ';
		}

		std::cout << std::endl;
	}
}

int main() {
	int arr[] = {5, 10, 40, 30, 28};
	// node* root = CreateTree();
	node *root = arrToTree(arr, 0, 4);
	tree_print(root);

}
