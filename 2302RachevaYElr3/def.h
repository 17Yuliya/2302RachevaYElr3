#pragma once

#include "struct.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <chrono>

using namespace std;

int Max(int a, int b);

void Preorder_bst(bst_node* root, ofstream& out);
void Postorder_bst(bst_node* root, ofstream& out);
void Inorder_bst(bst_node* root, ofstream& out, int& count);
void Wide_bst(bst_node* root, ofstream& out);

void Preorder_rbt(rbt_node* root, ofstream& out);
void Postorder_rbt(rbt_node* root, ofstream& out);
void Inorder_rbt(rbt_node* root, ofstream& out, int& count);
void Wide_rbt(rbt_node* root, ofstream& out);

void Preorder_avl(avl_node* root, ofstream& out);
void Postorder_avl(avl_node* root, ofstream& out);
void Inorder_avl(avl_node* root, ofstream& out, int& count);
void Wide_avl(avl_node* root, ofstream& out);

void Insert_bst(bst_node** root, bst_node* node);
void Insert_rbt(rbt_node** root, rbt_node* node, ofstream& out_time);
avl_node* Insert_avl(avl_node* root, int k, ofstream& out_time);

void Delete_bst(bst_node** root, bst_node* node);
void Delete_rbt(rbt_node** root, rbt_node* node, ofstream& out_time);
avl_node* Delete_avl(avl_node* node, int k, ofstream& out_time);

bst_node* Create_bst(ifstream& in, ofstream& out, int& count);
rbt_node* Create_rbt(ifstream& in, ofstream& out, int& count, ofstream& out_time);
avl_node* Create_avl(ifstream& in, ofstream& out, int& count, ofstream& out_time);
avl_node* CreateNode_avl(int k);

int Height_bst(bst_node* root);
int Height_rbt(rbt_node* root);

int Height_avl(avl_node* node);
void FixHeight_avl(avl_node* node);

bst_node* CreateNode_bst(int k);
rbt_node* CreateNode_rbt(int k);
avl_node* CreateNode_avl(int k);

bst_node* Search_bst(bst_node* root, int key);
rbt_node* Search_rbt(rbt_node* root, int key);
avl_node* Search_avl(avl_node* root, int key);

bst_node* MinElem_bst(bst_node* node);
rbt_node* MinElem_rbt(rbt_node* node);
avl_node* MinElem_avl(avl_node* node);

bst_node* MaxElem_bst(bst_node* node);
rbt_node* MaxElem_rbt(rbt_node* node);
avl_node* MaxElem_avl(avl_node* node);



