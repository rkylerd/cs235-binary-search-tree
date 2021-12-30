#include "BST.h"

#include <string.h>
#include <iostream>

using namespace std;

void BST::print(Node* n)
{
	
	if (n == NULL) {
		return;
}
	if (n->left != NULL) { print(n->left); }
	if (n->right != NULL) { print(n->right); }
	if (n->right == NULL && n->left == NULL) { 
		cout << n->data << "  ";
	}

}

bool BST::addRec(Node* &n, int data)
{
	
	if (n == NULL) { //to the point where we can add it now
		n = new Node();
		n->data = data;
		return true; 
	}

	if (n->data == data) {
		//it's already in the tree
		return false;
	}

	if (n->data < data) { //if the parent is less than the new addition
		addRec(n->right, data);
	}

	if (n->data > data) { //if the parent is more than the new addition
		addRec(n->left, data);
	}
	
}

bool BST::remRec(Node*&x, int data) 
{
	
	if (x == NULL) return false; //nothing in the tree

	if (x->data == data) { //MATCH!!!

		//if no kids
		if (x->left == NULL && x->right == NULL) {
			delete x;
			x = NULL;
			return true;
		}
		
		// if one kid
		if ((x->left != NULL && x->right == NULL) || (x->left == NULL && x->right != NULL)) {
			if (x->left == NULL) {//right child
				Node* temp = x;
				x = x->right;
				delete temp;
				temp = NULL;
				/*x->data = x->right->data; ///this was your problem!!!
				delete x->right; //you deleted everything to the right on this line... no bueno
				x->right = NULL;*/	
				return true;
			}

			if (x->right == NULL) {//left child
				Node* temp = x;
				x = x->left;
				delete temp;
				temp = NULL;
				/*x->data = x->left->data;  /// this was your problem!!!
				delete x->left;
				x->left = NULL;*/
				return true;
			}
		}
		

		//Kun may 2 ka anak***
		if (x->left != NULL && x->right != NULL) {
			Node *temp = x->left;

			while (temp->right != NULL) {
				temp = temp->right;
			}
			x->data = temp->data;
			
			return remRec(x->left, temp->data);//call me on myself to get rid of the original copy (the leaf node)
		}
		

	}

	//Still looking for a match
	if (x->data > data) {

		return remRec(x->left, data);
	}
	if (x->data < data) {
		return remRec(x->right, data);
	}
}

void BST::recClear(Node* &p)
{
	//No nodes
	if (p == NULL) {
		return;
	}

	//if no kids or leaf
	/*if (p->right == NULL && p->left == NULL) {
		//print(*&p);
		delete p;
		p = NULL;
		
	}*/
	
	//if naa'y kids, recurs
	if (p->right != NULL) {
		
		recClear(p->right);
		
	}
	if (p->left != NULL) {

		recClear(p->left);
	}
	delete p;
	p = NULL;
	
}

NodeInterface* BST::getRootNode()
{
	return root;
}

bool BST::add(int data)
{
	
	return addRec(root, data);
}

bool BST::remove(int data) 
{
	return remRec(root, data);
}


void BST::clear()
{
	//print(root);
	//cout << "This is what they hope to clear: " << root;
	
	recClear(root);
	return;
	
	
}