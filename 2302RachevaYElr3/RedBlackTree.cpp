#include "def.h"

rbt_node* MaxElem_rbt(rbt_node* node) {
	if (!node) return NULL;

	while (node->right) {
		node = node->right;
	}

	return node;
}

rbt_node* Search_rbt(rbt_node* root, int key) {

	if (!root) return root;
	if (root->key == key) return root;

	if (key < root->key) return Search_rbt(root->left, key);
	else return Search_rbt(root->right, key);
}

rbt_node* MinElem_rbt(rbt_node* node) {
	if (!node) return NULL;

	while (node->left) {
		node = node->left;
	}

	return node;
}

rbt_node* Successor_rbt(rbt_node* node) {
	if (!node) return NULL;

	if (node->right)
		return MinElem_rbt(node);

	rbt_node* parent = node->p;

	//if (!parent) return node;
	while (parent && node == parent->right) {
		node = parent;
		parent = parent->p;
	}

	return parent;
}

rbt_node* Grandparent(rbt_node* node) {
	if (node->p) {
		return node->p->p;
	}
	return NULL;
}

rbt_node* Uncle(rbt_node* node) {
	rbt_node* gr = Grandparent(node);
	if (!gr) return NULL;

	if (node->p == gr->left) return gr->right;
	else return gr->left;
}

rbt_node* Sibling(rbt_node* node) {
	if (node == node->p->left)
		return node->p->right;
	return node->p->left;
}

int Height_rbt(rbt_node* root) {
	if (!root) return 0;

	int h_left = Height_rbt(root->left);
	int h_right = Height_rbt(root->right);
	return Max(h_left, h_right) + 1;
}

void Left_Rotate(rbt_node** root, rbt_node* node) {
	rbt_node* tmp = node->right;
	tmp->p = node->p; 

	if (node->p) {
		if (node == node->p->left) node->p->left = tmp;
		else node->p->right = tmp;
	}
	node->right = tmp->left;

	if (tmp->left)	tmp->left->p = node;

	node->p = tmp;
	tmp->left = node;

	if (!tmp->p) *root = tmp;
}

void Right_Rotate(rbt_node** root, rbt_node* node) {
	rbt_node* tmp = node->left;
	tmp->p = node->p; 

	if (node->p) {
		if (node == node->p->left)	node->p->left = tmp;
		else node->p->right = tmp;
	}
	node->left = tmp->right;

	if (tmp->right)	tmp->right->p = node;

	node->p = tmp;
	tmp->right = node;

	if (!tmp->p) *root = tmp;
}

void InsertFixup_rbt(rbt_node** root, rbt_node* node) {

	if (!node->p) {
		node->color = 0; 
		return;
	}

	if (node->p->color == 0) return;

	rbt_node* u, * g;
	u = Uncle(node);

	if (u && u->color == 1) {
		node->p->color = 0;
		u->color = 0;
		g = Grandparent(node);
		if (g) g->color = 1;
		InsertFixup_rbt(root, g);
	}
	else {
		g = Grandparent(node);
		if (node == node->p->right && node->p == g->left) {
			Left_Rotate(root, node->p);

			node = node->left;
		}
		else if (node == node->p->left && node->p == g->right) {
			Right_Rotate(root, node->p);

			node = node->right;
		}

		g = Grandparent(node);
		node->p->color = 0;
		g->color = 1;
		if (node == node->p->left && node->p == g->left) {
			Right_Rotate(root, g);
		}
		else {
			Left_Rotate(root, g);
		}
	}

}

void Insert_rbt(rbt_node** root, rbt_node* node, ofstream& out_time) {
	rbt_node* tmp = *root;
	rbt_node* par_tmp = NULL;

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

	auto begin = chrono::steady_clock::now();

	InsertFixup_rbt(root, node);

	auto end = chrono::steady_clock::now();
	auto time = end - begin;
	auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
	out_time  << elapsed_ns.count() << "\n";
}

void DeleteFixup_rbt(rbt_node** root, rbt_node* node) {

	while (node && node != *root && node->color == 0) {

		if (node == node->p->left) {
			rbt_node* s = node->p->right;

			if (s->color == 1) {
				s->color = 0;
				node->p->color = 1;
				Left_Rotate(root, node->p);
				s = node->p->right;
			}

			if (s->left->color == 0 && s->right->color == 0) {
				s->color = 1;
				node = node->p;
			}
			else {
				if (s->right->color == 0) {
					s->left->color = 0;
					s->color = 1;
					Right_Rotate(root, s);
					s = node->p->right;
				}

				s->color = node->p->color;
				node->p->color = 0;
				s->right->color = 0;
				Left_Rotate(root, node->p);
				node = *root;
			}
		}

		else {
			rbt_node* s = node->p->left;

			if (s->color == 1) {
				s->color = 0;
				node->p->color = 1;
				Right_Rotate(root, node->p);
				s = node->p->left;
			}

			if (s->right->color == 0 && s->left->color == 0) {
				s->color = 1;
				node = node->p;
			}
			else {
				if (s->left->color == 0) {
					s->right->color = 0;
					s->color = 1;
					Left_Rotate(root, s);
					s = node->p->left;
				}

				s->color = node->p->color;
				node->p->color = 0;
				s->left->color = 0;
				Right_Rotate(root, node->p);
				node = *root;
			}
		}
	}
	if (node) node->color = 0;
}

void Delete_rbt(rbt_node** root, rbt_node* node, ofstream& out_time) {
	rbt_node* del_elem;
	rbt_node* child;
	if (!(*root)) return;

	if (!node->left || !node->right) del_elem = node;
	else del_elem = Successor_rbt(node);

	if (del_elem->left) child = del_elem->left;
	else child = del_elem->right;

	if (child) child->p = del_elem->p;

	if (!del_elem->p) *root = child;
	else {
		if (del_elem == del_elem->p->left) del_elem->p->left = child;
		else del_elem->p->right = child;
	}

	if (del_elem->color == 0) {
		auto begin = chrono::steady_clock::now();

		DeleteFixup_rbt(root, child);

		auto end = chrono::steady_clock::now();
		auto time = end - begin;
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
		out_time << elapsed_ns.count() << "\n";
	}

	delete del_elem;
}