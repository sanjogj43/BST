// Author : Sanjog Jadhav
// Defines the class node and declares the 
// member variables and functions in it.

#ifndef NODE_H
#define NODE_H

#include<string>
#include<iostream>
using namespace std;

class Node 
{
	private:
 		// declare key of the node
		string *key;

		// declares the data of the node
		string *data;

		// declares the node pointer for left node
		Node *left;

		// declares the node pointer for right node
		Node *right;
		
		// declares the parent node for the parent
		Node *parent;	 
	
	public:
			
		// Declares the non-parameterized constructor for node class.
		Node();
		
		// parameterized constructor for Node Class.
		Node(string& key, string& data, Node* left, Node *right, Node *parent);
		
		// Declares the destructor for the class Node.
		~Node();
		
		// Declares the getter to return the left node of the current Node.
		Node* getLeft(){return this->left;}
		
		// Declares the Getter to return the right node of the current Node.
		Node* getRight(){return this->right;}	
		
		// Declares the Getter to return the key of the current Node.
		string getKey(){return *this->key;}
			
		// Declares the Getter to return the data of the current Node.
		string getData(){return *this->data;}
		
		// Declares the class BST as a friend of class BST.
		friend class BST;
};

#endif
