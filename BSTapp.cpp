// Author : Sanjog Jadhav
// Defines all the functions defined in the class BSTapp

#include<stdlib.h>
#include"BSTapp.h"

// calls the function process command.
void BSTapp::mainLoop() {
   while (!cin.eof()) 
	   processCommand();         
}

// Breaks the input string into key and data and calls the different commands used in the program.
void BSTapp::processCommand()
{
		string s;
		getline(cin, s);                             
		
		// break the string into command, key and data.   
		string command = s.substr(0, s.find(' '));   
		s.erase(0, s.find(' ')+1);
		string key = s.substr(0, s.find(' '));
		s.erase(0, s.find(' ')+1);
		string data = s.substr(0, s.find('\n'));

		if (command == "insert") 
			processInsert(key,data);
		else if (command == "find") 
			processFind(key);
		else if (command == "delete") 
			processDelete(key,data);
		else if (command == "print") 
			processPrint();
		else if (command == "quit") 
			processQuit();

}
   
// Accepts the key and data from process command and sends them 
// to insert function in the BST class.
void BSTapp::processInsert(string& key, string& data)
{
	if(!key.empty() && !data.empty())
	{
		this->STree.treeInsert(key,data);
	}
}
   
// Accepts the key from process command and sends them 
// to search function in the BST class.
void BSTapp::processFind(string& key)
{
	if(!key.empty())
	{
		Node *root = this->STree.getRoot();
		Node *foundNode = this->STree.treeSearch(root,key);
			
		while(foundNode != NULL)
		{
			cout<<foundNode->getKey()<<' '<<foundNode->getData()<<'\n';
			foundNode = this->STree.treeSearch(foundNode->getRight(), key); 
		}			
	}
}
   
// Accepts the key and data from process command and sends them 
// to delete function in the BST class.
void BSTapp::processDelete(string& key, string& data) 
{
	if(!key.empty() && !data.empty())
	{
		Node *root = this->STree.getRoot();
		
		// search the node with the key under root.
		Node *foundNode = this->STree.treeSearch(root,key);

		// to check if the the node is deleted or not.
		bool deleteFlag;
		while(foundNode!=NULL)
		{
			deleteFlag = false;
			if(foundNode->getData() == data)
			{
				// if the data and key both match that of found node
				// delete it and set the delete flag to true
				this->STree.treeDelete(foundNode);	
				deleteFlag = true;
			}
			if(deleteFlag)
			{
				// if node is deleted set the found node to root
				foundNode = this->STree.getRoot();
			}
			else
			{
				// if not set found node to right child.
				foundNode = foundNode->getRight(); 
			}
			foundNode = this->STree.treeSearch(foundNode,key);

		}	
	}
}

// Print the nodes in the tree in 'in order format' 
void BSTapp::processPrint()
{
	Node* root  = this->STree.getRoot();
	this->STree.inOrderTreeWalk(root);
}

// exit the program.
void BSTapp::processQuit()
{
	this->STree.~BST();
	exit(0);
}

//start the program.
int main()
{
	BSTapp myBSTapp;
	myBSTapp.mainLoop();
	return 0;
}
