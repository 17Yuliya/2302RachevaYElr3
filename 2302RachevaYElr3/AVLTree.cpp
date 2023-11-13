#include "def.h"

avl_node* MaxElem_avl(avl_node* node) {
	if (!node) return NULL;

	while (node->right) {
		node = node->right;
	}

	return node;
}

avl_node* Search_avl(avl_node* root, int key) {

	if (!root) return root;
	if (root->key == key) return root;

	if (key < root->key) return Search_avl(root->left, key);
	else return Search_avl(root->right, key);
}

avl_node* MinElem_avl(avl_node* node) {
	if (!node) return NULL;

	while (node->left) {
		node = node->left;
	}

	return node;
}

int Height_avl(avl_node* node) {
	if (node) return node->h;
	return 0;
}

int HeightDiff_avl(avl_node* node) {
	int hr = Height_avl(node->right);
	int hl = Height_avl(node->left);
	return (hr - hl);
}

void FixHeight_avl(avl_node* node) {
	int hl = Height_avl(node->left);
	int hr = Height_avl(node->right);
	node->h = Max(hl, hr) + 1;
}

avl_node* RightRotate_avl(avl_node* node) {
	avl_node* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	FixHeight_avl(node);
	FixHeight_avl(tmp);
	return tmp;
}

avl_node* LeftRotate_avl(avl_node* node) {
	avl_node* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	FixHeight_avl(node);
	FixHeight_avl(tmp);
	return tmp;
}

avl_node* Balance_avl(avl_node* node) {
	FixHeight_avl(node);

	if (HeightDiff_avl(node) == 2) {
		if (HeightDiff_avl(node->right) < 0)
			node->right = RightRotate_avl(node->right);
		return LeftRotate_avl(node);
	}

	if (HeightDiff_avl(node) == -2)	{
		if (HeightDiff_avl(node->left) > 0)
			node->left = LeftRotate_avl(node->left);
		return RightRotate_avl(node);
	}
	return node;
}

avl_node* Insert_avl(avl_node* node, int k, ofstream& out_time) {
	if (!node) return CreateNode_avl(k);
	if (k < node->key) {
		node->left = Insert_avl(node->left, k, out_time);
	}
	else {
		node->right = Insert_avl(node->right, k, out_time);
	}

	auto begin = chrono::steady_clock::now();

	node = Balance_avl(node);

	auto end = chrono::steady_clock::now();
	auto time = end - begin;
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
	out_time << elapsed_ns.count() << "\n";

	return node;
}

avl_node* DeleteMin(avl_node* node, ofstream& out_time) {
	if (!node->left)
		return node->right;
	node->left = DeleteMin(node->left, out_time);

	auto begin = chrono::steady_clock::now();
	Balance_avl(node);

	auto end = chrono::steady_clock::now();
	auto time = end - begin;
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
	out_time << elapsed_ns.count() << "\n";

	return node;
}

avl_node* Delete_avl(avl_node* node, int k, ofstream& out_time) {
	if (!node) return NULL;

	if (k < node->key) node->left = Delete_avl(node->left, k, out_time);
	else {
		if (k > node->key) node->right = Delete_avl(node->right, k, out_time);
		else {
			avl_node* left = node->left;
			avl_node* right = node->right;
			delete node;

			if (!right) return left;

			avl_node* min = MinElem_avl(right);
			min->right = DeleteMin(right, out_time);
			min->left = left;

			auto begin = chrono::steady_clock::now();
			Balance_avl(min);

			auto end = chrono::steady_clock::now();
			auto time = end - begin;
			auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
			out_time << elapsed_ns.count() << "\n";

			return min;
		}
	}
	auto begin = chrono::steady_clock::now();
	Balance_avl(node);

	auto end = chrono::steady_clock::now();
	auto time = end - begin;
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
	out_time << elapsed_ns.count() << "\n";

	return node;
}




