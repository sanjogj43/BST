#ifndef BST_H
#define BST_H

#include"Node.h"

class BST
{
	private:
		Node *root;
              
		//Returns the minimum node in the sub child 'node' 
		Node* treeMinimum(Node *node);

		//Replace the 'nodeTobeDeleted' with 'nodeToBeTransplanted'
		void transplant(Node *nodeToDelete, Node *nodeToBeTransplanted);
	public:
		
		//Default Constructor
		BST(){this->root = NULL;}
		
		//Paramentrized Constructor
		BST(Node *node){this->root = node;}
		
		//Getter : Returns the root of the tree 
		Node *getRoot(){return this->root;}
		
		//Destructor for the tree
		~BST();
		
		//Prints the nodes of the tree in order
		void inOrderTreeWalk(Node *node);
		
		//To search the node 
		Node* treeSearch(Node *node, string key);
		
		//Create a node with key and data and insert it into the tree.
		void treeInsert(string &key, string &data);

		//To delete the Node from the tree
		void treeDelete(Node *nodeToDelete);

};

#endif