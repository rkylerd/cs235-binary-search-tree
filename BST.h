#pragma once
#include "BSTInterface.h"
#include "NodeInterface.h"

using namespace std;

class BST: public BSTInterface {
private:
	
	struct Node : public NodeInterface {
		Node() {
			
			right = NULL;
			left = NULL;
			data = 0;
		}

		~Node() {}

		Node *left, *right;
		int data;
		
		int getData()
		{
			return data;
		}

		Node * getLeftChild()
		{
			if (left == NULL) return NULL;
			else return left;
		}

		Node * getRightChild()
		{
			if (right == NULL) return NULL;
			else return right;
		}
	};
	Node* root;
public:
	BST() { 
		root = NULL; 
		
	}
	~BST() { clear(); } //Is this the right place to call clear?

	void print(Node* n);

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface* getRootNode(); 

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool add(int data);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool remove(int data);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void clear();

	//HELPERS!!!
	bool addRec(Node* &n, int data);
	bool remRec(Node*&x, int data);
	void recClear(Node* &p);
};