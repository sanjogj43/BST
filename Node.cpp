// Author : Sanjog Jadhav
// Defines the functions declared in the class Node.

#include"Node.h"

// non parameterized constructor 
Node::Node()
{
	this->key = new string(" ");
	this->data = new string(" ");
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}

// parameterized constructor
Node::Node(string& key, string& data, Node* left, Node *right, Node *parent)
{
	this->key=new string;
	this->key->assign(key);
	this->data=new string;
	this->data->assign(data);
	this->left = left;
	this->right = right;
	this->parent = parent;
}

// destructor
Node::~Node()
{
	delete(this->key);
	delete(this->data);
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;		
}
