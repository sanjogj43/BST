// Author : Sanjog Jadhav
// Defines all the functions declared in the class BST

#include "BST.h"

// destructs the complete tree.
BST::~BST()
{
	while(this->root!=NULL)
	{
		this->treeDelete(this->root);
	}
		
}

// prints each node in the tree traversing it in 'in order'
// node : current node.
void BST::inOrderTreeWalk(Node *node)
{
	static int depth = -1; 
	if(node!= NULL)
	{
		depth++;
		inOrderTreeWalk(node->left);
        	cout<<depth<<' '<<*node->key<<' '<<*node->data<<endl;
	
		inOrderTreeWalk(node->right);
		depth--;
	}
}


// Searches the node with key 'key' in the child specified by the node child.
// node : child or root under which the node with specified key is to be found.
// key : key based on which the node is to be searched.		
Node* BST::treeSearch(Node *node, string key)
{
	if(node == NULL || *node->key == key)
	{
		return node;
	}
			
	if(key < *node->key)
	{
		return treeSearch(node->left, key);
	}
	return treeSearch(node->right, key);
}

// Returns the node with minimum key value in the left sub tree of the node.
// node: node under which the minimum node is to be found.
Node* BST::treeMinimum(Node *node)
{
	while(node->left !=NULL)
	{
		node = node->left;
	}
	return node;
}

// creates node with key and data specified. And inserts that node in the tree.
// key : key of which node is to be formed.
// data : data of which node is to be formed.
void BST::treeInsert(string &key, string &data)
{
	Node *nodeToInsert = new Node(key,data,NULL,NULL,NULL);
	Node *temp1 = NULL;
	Node *traverse_node = this->root;
	while(traverse_node!=NULL)
	{
		temp1 = traverse_node;
		if(*nodeToInsert->key<*traverse_node->key)
		{
			traverse_node = traverse_node->left;
		}
		else
		{
			traverse_node = traverse_node->right;
		}
	}
	nodeToInsert->parent = temp1;
	if(temp1 == NULL)
	{
		this->root = nodeToInsert;
	}
	else if(*nodeToInsert->key<*temp1->key)
	{
		temp1->left = nodeToInsert;
	}
	else
	{
		temp1->right = nodeToInsert;
	}
}

// Deletes the specified node from the tree.
// nodeToDelete : Node that is to be deleted from the tree.
void BST::treeDelete(Node *nodeToDelete)
{
	// if left is null, replace the right child with the node to delete
	if(nodeToDelete->left==NULL)
	{
		transplant(nodeToDelete,nodeToDelete->right);
	}

	// if right is null, replace the left child wih node to delete.
	else if(nodeToDelete->right==NULL)
	{
		transplant(nodeToDelete,nodeToDelete->left);
	}

	// if niether right, nor left is null, find the minimum in the right subtree
	else
	{
			Node *nodeMinimum= this->treeMinimum(nodeToDelete->right);
			if(nodeMinimum->parent != nodeToDelete)	
			{
				// if node to delete is not the immediate parent of the minimum node
				// replace the node minimum with right child of node minimum
				this->transplant(nodeMinimum,nodeMinimum->right);
				nodeMinimum->right = nodeToDelete->right;
				nodeMinimum->right->parent = nodeMinimum; 
			}
			// replace the node to delete with node minimum
			this->transplant(nodeToDelete,nodeMinimum);
			nodeMinimum->left = nodeToDelete->left;
			nodeMinimum->left->parent = nodeMinimum;
	}
	delete nodeToDelete;
}

// transplant the node to delete  with node to be transplanted.
// nodeToDelete : the node that is to be deleted.
// nodeToBeTransplanted : node that is to be transplanted.		
void BST::transplant(Node *nodeToDelete, Node *nodeToBeTransplanted)
{
	if(nodeToDelete->parent == NULL)
	{
		this->root = nodeToBeTransplanted;
	}
	else if(nodeToDelete == nodeToDelete->parent->left)
	{
		nodeToDelete->parent->left = nodeToBeTransplanted;
	}
	else
	{
		nodeToDelete->parent->right = nodeToBeTransplanted;
	}
	if(nodeToBeTransplanted!= NULL)
	{
		nodeToBeTransplanted->parent = nodeToDelete->parent;
	}
}
