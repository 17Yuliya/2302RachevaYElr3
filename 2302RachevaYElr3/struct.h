#pragma once

struct bst_node {
	int key;
	bst_node* left;
	bst_node* right;
	bst_node* p;
};

struct rbt_node {
	int key;
	rbt_node* left;
	rbt_node* right;
	rbt_node* p;
	bool color; //0 - черный, 1 - красный
};

struct avl_node {
	int key;
	avl_node* left;
	avl_node* right;
	avl_node* p;
	int h;
};