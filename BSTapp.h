//Author : Sanjog jadhav
//BSTapp.h : declares all the functions to process the commands.

#ifndef BSTAPP_H
#define BSTAPP_H

#include "BST.h"
using namespace std;

class BSTapp 
{
   public:
	// Gives the call to process command. 
   	void mainLoop();              
   private:
	// Declaration of object of class Btree.
   	BST STree;              
       
	// Breaks the input string into key and data and 
	// calls appropriate process command.
  	void processCommand();
   	
	// Processes the insert command and inserts the node in the tree.
  	void processInsert(string& key, string& data);
   	
	// Processes the find command and displays the node with the key passed.
  	void processFind(string& key);
   	
	// Processes the delete command and deletes all the nodes with the 
	// specified key and data value.
  	void processDelete(string& key, string& data);
   	
	// Processes the print command and prints the tree in order.	 
  	void processPrint();
	
	// Processes the quit command and quits the program.
  	void processQuit();
};

#endif
