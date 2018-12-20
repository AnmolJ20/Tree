// Print all nodes of a binary tree which do not have sibling
#include <iostream>
#include <iomanip>

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

node* createBT();
void sibPrint(node* root, bool flag);

int main() {
	node* root = createBT();

    // tree_print(root);
	sibPrint(root, false);
}

node* createBT() {
    int x;
    std::cin >> x;

    node* root = new node(x);

    bool child;

    std::cin >> std::boolalpha >> child;
    if (child == true)
        root->left = createBT();
    std::cin >> std::boolalpha >> child;
    if (child == true)
        root->right = createBT();

    return root;
}

void sibPrint(node* root, bool flag) {
	if (root == NULL)
		return;
	if (flag)
		std::cout << root->value << " ";
		
	if (root->left == NULL and root->right)
		sibPrint(root->right, true);

	else if (root->left and root->right == NULL)
		sibPrint(root->left, true);

	else {
		sibPrint(root->left, false);
		sibPrint(root->right, false);
	}
}
