#include "def.h"

void Preorder_bst(bst_node* root, ofstream& out) {
	if (!root) return;

	out << root->key << ' ';
	Preorder_bst(root->left, out);
	Preorder_bst(root->right, out);
}

void Postorder_bst(bst_node* root, ofstream& out) {
	if (!root) return;

	Postorder_bst(root->left, out);
	Postorder_bst(root->right, out);
	out << root->key << ' ';
}

void Inorder_bst(bst_node* root, ofstream& out, int& count) {
	if (!root);

	Inorder_bst(root->left, out, count);

	out << root->key << ' ';
	count += 1;

	Inorder_bst(root->right, out, count);
}

void Wide_bst(bst_node* root, ofstream& out) {
	if (!root) return;

    std::queue<bst_node*> q;
    q.push(root);
	bst_node* node;

    while (!q.empty()) {
        node = q.front();
		out << node->key << ' ';
        q.pop();
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

}

void Inorder_rbt(rbt_node* root, ofstream& out, int& count) {
	if (!root);

	Inorder_rbt(root->left, out, count);

	//out << root->key << ',' << root->color << ' ';
	out << root->key << ' ';
	count += 1;

	Inorder_rbt(root->right, out, count);
}

void Preorder_rbt(rbt_node* root, ofstream& out) {
	if (!root) return;

	out << root->key << ' ';
	Preorder_rbt(root->left, out);
	Preorder_rbt(root->right, out);
}

void Postorder_rbt(rbt_node* root, ofstream& out) {
	if (!root) return;

	Postorder_rbt(root->left, out);
	Postorder_rbt(root->right, out);
	out << root->key << ' ';
}

void Wide_rbt(rbt_node* root, ofstream& out) {
	if (!root) return;

	std::queue<rbt_node*> q;
	q.push(root);
	rbt_node* node;

	while (!q.empty()) {
		node = q.front();
		out << node->key << ' ';
		q.pop();
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
}

void Inorder_avl(avl_node* root, ofstream& out, int& count) {
	if (!root);

	Inorder_avl(root->left, out, count);

	out << root->key << ',' << root->h-1 << ' ';
	//out << root->key << ' ';
	count += 1;

	Inorder_avl(root->right, out, count);
}

void Preorder_avl(avl_node* root, ofstream& out) {
	if (!root) return;

	out << root->key << ' ';
	Preorder_avl(root->left, out);
	Preorder_avl(root->right, out);
}

void Postorder_avl(avl_node* root, ofstream& out) {
	if (!root) return;

	Postorder_avl(root->left, out);
	Postorder_avl(root->right, out);
	out << root->key << ' ';
}

void Wide_avl(avl_node* root, ofstream& out) {
	if (!root) return;

	std::queue<avl_node*> q;
	q.push(root);
	avl_node* node;

	while (!q.empty()) {
		node = q.front();
		out << node->key << ' ';
		q.pop();
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
}