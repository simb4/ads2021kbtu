#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

struct node {
	node *left;
	node *right;
	int key;
	// string data;

	node(int _key = 0) {
		left = right = NULL;
		key = _key;
	}

	node(int key, node *left, node *right) 
		: key(key), left(left), right(right) {
	}
};

struct BST {
	node *root = NULL;
	
	void insert(node *cur, int x) {
		node *next = NULL; 
		if (x <= cur->key) {
			if (cur->left == NULL) {
				cur->left = new node(x);
				return;
			}
			next = cur->left;
		}
		else {
			if (cur->right == NULL) {
				cur->right = new node(x);
				return;
			}
			next = cur->right;
		}
		insert(next, x);
	}

	void insert(int x) {
		if (root == NULL)
			root = new node(x);
		else
			insert(root, x);
	}

	node* find(node *cur, int x) {
		if (x == cur->key)
			return cur;
		if (x < cur->key)
			return cur->left == NULL 
				? NULL 
				: find(cur->left, x);
		// x > key
		return cur->right == NULL
			? NULL
			: find(cur->right, x);
	}

	node* find(int x) {
		return find(root, x);
	}

	void print(node *cur, int tab = 1) {
		if (cur != NULL)
			printf("[%d]\n", cur->key);
		else {
			puts("");
			return;
		}
		for (int i = 0; i < tab; i++) putchar('\t');
		printf("L ");
		print(cur->left, tab + 1);
		for (int i = 0; i < tab; i++) putchar('\t');
		printf("R ");
		print(cur->right, tab + 1);

	}

	void print() {
		print(root);
	}

	node* del(node *cur, int x) {
		if (cur == NULL)
			return NULL;

		if (x < cur->key) {
			
			cur->left = del(cur->left, x);

		} else if (cur->key < x) {

			cur->right = del(cur->right, x);

		} else { // cur->key == x

			/* case cur is leaf */
			if (cur->left == NULL && cur->right == NULL) {
				delete cur;
				return NULL;
			}

			/* case cur has 1 child */
			if (cur->left == NULL || cur->right == NULL) {
				node *next = cur->left != NULL 
					? cur->left
					: cur->right;
				delete cur;
				return next;
			}
			
			/* case cur have 2 children */
			node *next = cur->right;
			while (next->left != NULL)
				next = next->left;

			/* copy the content */
			cur->key = next->key;
			// cur->data = next->data; // in case data is used
			cur->right = del(cur->right, next->key);

		}
		return cur;
	}

	void del(int x) {
		root = del(root, x);
	}

} bst;



int main() {

	BST bst;
	bst.insert(6);
	bst.insert(4);
	bst.insert(1);
	bst.insert(5);
	bst.insert(7);
	bst.insert(9);
	bst.print();

	bst.del(4);
	bst.print();

	return 0;
}




