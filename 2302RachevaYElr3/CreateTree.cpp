#include "def.h"

bst_node* CreateNode_bst(int k) {
	bst_node* tmp = new bst_node;
	tmp->key = k;
	tmp->left = tmp->right = tmp->p = NULL;
	return tmp;
}

rbt_node* CreateNode_rbt(int k) {
	rbt_node* tmp = new rbt_node;
	tmp->key = k;
	tmp->left = tmp->right = tmp->p = NULL;
	tmp->color = 1;
	return tmp;
}

avl_node* CreateNode_avl(int k) {
	avl_node* tmp = new avl_node;
	tmp->key = k;
	tmp->left = tmp->right = tmp->p = NULL;
	tmp->h = 1;
	return tmp;
}


bst_node* Create_bst(ifstream& in, ofstream& out, int& count) {
	int k;
	bst_node* root = NULL;

	in.clear();
	in.seekg(0);

	while (!in.eof()) {

		if (in >> k) {
			bst_node* node = CreateNode_bst(k);
			Insert_bst(&root, node);
		}

	}

	count = 0;
	Inorder_bst(root, out, count);

	return root;
}

rbt_node* Create_rbt(ifstream& in, ofstream& out, int& count, ofstream& out_time) {
	int k; 
	rbt_node* root = NULL;

	in.clear();
	in.seekg(0);

	while (!in.eof()) {

		if (in >> k) {
			rbt_node* node = CreateNode_rbt(k);
			Insert_rbt(&root, node, out_time);
		}

	}

	count = 0;
	Inorder_rbt(root, out, count);

	return root;
}

avl_node* Create_avl(ifstream& in, ofstream& out, int& count, ofstream& out_time) {
	int k; 
	avl_node* root = NULL;
	bool f_r = 1;

	in.clear();
	in.seekg(0);

	while (!in.eof()) {

		if (in >> k) {
			root = Insert_avl(root, k, out_time);
		}

	}

	count = 0;
	Inorder_avl(root, out, count);
	return root;
}

