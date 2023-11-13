#include "def.h"

bst_node* MinElem_bst(bst_node* node) {
	if (!node) return NULL;

	while (node->left) {
		node = node->left;
	}

	return node;
}

bst_node* MaxElem_bst(bst_node* node) {
	if (!node) return NULL;

	while (node->right) {
		node = node->right;
	}

	return node;
}

bst_node* Successor_bst(bst_node* node) {
	if (!node) return NULL;

	if (node->right)
		return MinElem_bst(node);

	bst_node* parent = node->p;

	if (!parent) return node;
	while (parent && node == parent->right) {
		node = parent;
		parent = parent->p;
	}

	return parent;
}

bst_node* Search_bst(bst_node* root, int key) {

	if (!root) return root;
	if (root->key == key) return root;

	if (key < root->key) return Search_bst(root->left, key);
	else return Search_bst(root->right, key);
}

void Insert_bst(bst_node** root, bst_node* node) {
	bst_node* tmp = *root;
	bst_node* par_tmp = NULL;

	while (tmp) {
		par_tmp = tmp;

		if (node->key < tmp->key) tmp = tmp->left;
		else tmp = tmp->right;
	}

	node->p = par_tmp;

	if (!par_tmp) *root = node;
	else {
		if (node->key < par_tmp->key) par_tmp->left = node;
		else par_tmp->right = node;
	}
}

void Delete_bst(bst_node** root, bst_node* node) {
	bst_node* del_elem;
	bst_node* tmp;

	if (!node->left || !node->right) del_elem = node;
	else del_elem = Successor_bst(node);

	if (del_elem->left) tmp = del_elem->left;
	else tmp = del_elem->right;

	if (tmp) tmp->p = del_elem->p;

	if (!del_elem->p) *root = tmp;
	else {
		if (del_elem == del_elem->p->left) del_elem->p->left = tmp;
		else del_elem->p->right = tmp;
	}

	if (del_elem != node) { //Successor_bst
		node->key = del_elem->key;
	}

	//delete del_elem;
}

int Max(int a, int b) {
	return (a > b) ? a : b;
}

int Height_bst(bst_node* root) {
	if (!root) return 0;

	int h_left = Height_bst(root->left);
	int h_right = Height_bst(root->right);
	return Max(h_left, h_right) + 1;
}