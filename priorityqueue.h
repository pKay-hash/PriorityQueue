// priorityqueue.h
//
// Syed Shaban
// Program Description: A program that uses a modified Binary Search Tree that allows for duplicates to create a priority queue data structure.
//

#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)
    
public:
    //
    // default constructor:
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue() {
       this->size = 0;
       this->root = new NODE;//initializes the root of the node to an empty node
       this->root->right = nullptr;
       this->root->left = nullptr;
       this->root->dup = false;
       this->root->link = nullptr;
       this->root->parent = nullptr;
       this->curr = nullptr;
        
    }
    
    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other) {
        this->clear();//calls clear function
	delete this->root;
        helpCopy(this->root, other.root);//helper function which recursively calls a helpCopy function
        this->size = other.size;
	this->curr = other.curr;
	return *this;
        
        
    }
    
    void helpCopy(NODE* &newNode, NODE* other){//pre order recursive function to help copy a BST onto another
    	if(other == nullptr){//base case 
		newNode = nullptr;
	}
	else{
		newNode = new NODE;
		newNode->priority = other->priority;//adds each node and its element to new BST
		newNode->value = other->value;
		newNode->right = other->right;
		newNode->left = other->left;
		newNode->dup = other->dup;
		newNode->parent = other->parent;
		if(other->dup == true){//checks if the current node is a duplicate
			NODE* temp = other;
			helpCopy(newNode->link, other->link);
		}
		helpCopy(newNode->left, other->left);
		helpCopy(newNode->right, other->right);		
	}
    }
    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear(){
	if(this->size != 0){
		recursiveClear(this->root);//calls recursive function passing the root node of the BST in as a parameter
		this->root = new NODE;//declares new root;
		this->size = 0;
		this->root->right = nullptr;
		this->root->left = nullptr;
		this->root->dup = false;
		this->root->link = nullptr;
		this->root->parent = nullptr;
		this->curr = nullptr;
	}
    }

    void recursiveClear(NODE* node) {//postorder function to delete each node in a BST
        if(node == nullptr){//base case to return when null
		return;
	}
	if(node->link != nullptr){//checks if there is any links on the current node
                recursiveClear(node->link);
        }
	recursiveClear(node->left);//recursively calls on left and right nodes
	recursiveClear(node->right);
	delete node;
    }
    
    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue() {
        this->clear();//calls clear function to clear all nodes in the BST
	delete this->root;//deletes the root that is automatically initialized in the constructor and reinitialized after performing the clear function
        // TO DO: write this function.
        
        
    }
    
    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //

    void enqueue(T value, int priority) {
        if(this->size == 0){//checks if there is anything in the queue currently, if not, make the new node the root
		this->root->priority = priority;
		this->root->value = value;
		this->root->right = nullptr;
       		this->root->left = nullptr;
       		this->root->link = nullptr;
       		this->root->parent = nullptr;
		this->root->dup = false;//defaults duplicates to false;
		this->root->parent = nullptr;//root does not have a parent
		this->size = this->size + 1;
		return;
	}
	NODE* newNode = nullptr;
	NODE* tempNode = this->root;
	NODE* dupNodes = nullptr;
	while(tempNode != NULL){//find the current leafNode at which the newly inserted node should be
		if(priority < tempNode->priority){//use priority to determine where in the tree that the node should be placed
			if(tempNode->left == NULL){//if we find the correct spot, insert a new node
				newNode = new NODE;
				newNode->priority = priority;
				newNode->value = value;
				newNode->right = nullptr;//initializes children and linked list for duplicates to null.
				newNode->left = nullptr;
				newNode->link = nullptr;
				newNode->dup = false;//since there is no item in the queue/tree that currently has the same priority as this new item, we do not consider the duplicated linked list.
				newNode->parent = tempNode;//sets current node as the parent of the new node before adding it as a child
				tempNode->left = newNode;
				tempNode = NULL;
				this->size = this->size + 1;
			}
			else{
				tempNode = tempNode->left;//keeps following the tree down the structure.
			}
		}
		//same as case above, except with right children when the priority is greater than the current node's.
		else if(priority > tempNode->priority){
			if(tempNode->right == NULL){
				newNode = new NODE;
                                newNode->priority = priority;
                                newNode->value = value;
				newNode->right = nullptr;//initializes children and linked list for duplicates to null.
                                newNode->left = nullptr;
                                newNode->link = nullptr;
                                newNode->dup = false;
                                newNode->parent = tempNode;
				tempNode->right = newNode;
				tempNode = NULL;
				this->size = this->size + 1;
			}
			else{
				tempNode = tempNode->right;
			}
		}
		else if(priority == tempNode->priority){//there already exists an item in the queue with the same priority.
			newNode = new NODE;
			newNode->priority = priority;
			newNode->value = value;
			newNode->dup = true;
			newNode->left = nullptr;//initializes children and parents to nullptr
			newNode->right = nullptr;
			tempNode->dup = true;
			newNode->parent = nullptr;
			newNode->link = nullptr;
			dupNodes = tempNode;
			while(dupNodes->link != nullptr){//adds the new node to the end of the linked list attached to the current node's position in the BST
				dupNodes = dupNodes->link;
			}
			dupNodes->link = newNode;
			tempNode = NULL;
			this->size = this->size + 1;

		}

	}
        
        
        
    }
    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T dequeue() {
        T valueOut;
	if(this->size == 0){//checks if there is currently anything in the queue
        	return valueOut;//should return nothing
	}
	NODE* returnNode = findMin(this->root);//finds the leftmost item in the BST
	if(returnNode->link != nullptr){//if the node doesn't have any duplicates
		if(returnNode->parent != nullptr){
			returnNode->link->parent = returnNode->parent;//sets the next item in the linked list's parent equal to the current node's parent, and does the same with its children
			if(returnNode == returnNode->parent->left){//if the return node is the left child of its parent, set the parent of the return node's left child to the current node's link
				returnNode->parent->left = returnNode->link;
			}
			else if (returnNode == returnNode->parent->right){//does the same thing for the right child
				returnNode->parent->right = returnNode->right;
			}
		}
                returnNode->link->right = returnNode->right;//sets the next item's right child to the right child of the current item.
		if(returnNode->right != nullptr){
                	returnNode->right->parent = returnNode->link;
		}
		returnNode->link->left = returnNode->left;//sets the next item's left child to the left child of the current item
		if(returnNode->left != nullptr){
			returnNode->left->parent = returnNode->link;
		}
		valueOut = returnNode->value;
		if(returnNode->link->link == nullptr){//if the next item is the last item in the linked list, set duplicate value to false
			returnNode->link->dup = false;
		}
		delete returnNode;
		if(returnNode == this->root)
			this->root = returnNode->link;
		this->size = this->size-1;
		return valueOut;
		
	}
	if(returnNode == this->root){//if the leftmost item is the root, check whether the root is the only item in the BST
		if(returnNode->right == nullptr){//if the root is the leftmost item of the BST and the only item in the BST
			valueOut = returnNode->value;
			delete returnNode;
			this->size = this->size-1;
			this->root = new NODE;//initializes the root of the node to an empty node
			this->root->right = nullptr;
			this->root->left = nullptr;
			this->root->dup = false;
			this->root->link = nullptr;
			this->root->parent = nullptr;
			this->size = 0;
			this->curr = nullptr;
			return valueOut;
		}
		else{
			valueOut = returnNode->value;
			this->root = returnNode->right;//sets the new root as the right child of the old root
			this->root->parent = nullptr;//sets the parent of the current root to nullptr
			delete returnNode;
			this->size = this->size-1;
			return valueOut;
		}
	}
	if(returnNode->left == nullptr && returnNode->right == nullptr){//if the node is a leaf
		valueOut = returnNode->value;
		if(returnNode->parent->left == returnNode)//if the node is the left child of its parent, set the parents left child to null before deleting
			returnNode->parent->left = nullptr;
		if(returnNode->parent->right == returnNode)//if the node is the right child of its parent, set the parent's right child to null before deleting.
			returnNode->parent->right = nullptr;
		delete returnNode;
		this->size = this->size-1;
		return valueOut;
	}
	else if(returnNode->left == nullptr){//if there is only a right child
		valueOut = returnNode->value;
		if(returnNode == returnNode->parent->left){//if the current node is the right child of its parent
			returnNode->parent->left = returnNode->right;//sets the parent's left child to the right child of the current node.
			returnNode->right->parent = returnNode->parent;//sets the parent of the right child of the current node to the current node's parent, taking the current node out of the connection.
			delete returnNode;
			this->size = this->size-1;
			return valueOut;
		}

	}
        return valueOut; // TO DO: update this return
        
        
    }
    
    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
	int Size() {
		return this->size;
	}
	
    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin() {
	if(this->size == 0){//checks if there is anything in the BST for the curr node to point to.
		this->curr = nullptr;
	}
	else {//checks if there is any items in the queue before running helperBegin
        	this->curr = findMin(this->root);
	}
    }
    
    NODE* findMin(NODE* node){//recursive function to get the leftmost item in the BST
    	if(node->left == nullptr){//base case to make sure that the function can call the left child
		return node;//returns the leftmost node in the BST
	}
	return findMin(node->left);//recursively calls the function.
    }
    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority) {
	if(curr == nullptr){//if curr is not currently pointing to anything, one cannot perform the next function
		return false;
	}
	bool linkedList = false;//checks if the current value is the last element of a linked list
	if(curr->link != nullptr){//if the current node has a duplicate priority and it is not the last element in the linked list
		value = this->curr->value;
		priority = this->curr->priority;
		curr = curr->link;//sets the curr value to the next element in the linked list
		return true;
	}
	else if (curr->dup == true && curr->link == nullptr){//if it is the last element in the linked list
		value = this->curr->value;
		priority = this->curr->priority;
		curr = this->find(curr->priority);
		linkedList = true;//this item is the last element in a linked list, letting the rest of the code know not to override the value and priority
	}
	if(linkedList == false){
		value = this->curr->value;//set the parameters passed through the function to the curr's value and priority BEFORE advancing the node
		priority = this->curr->priority;
	}
	if(curr->right != nullptr){//if there is a right subtree, find the min of the right subtree, that is the next inorder node
		this->curr = findMin(curr->right);
		return true;
	}
	else{// if the right subtree of the current inorder node is empty, follow the parents up the tree
		NODE* tempNode = curr;
		if(tempNode->parent == nullptr){//if there is no parent of the current subtree and the right subtree is empty, it is the end of the list
			return false;
		}
		while(tempNode->parent != nullptr && tempNode->parent->right == tempNode){//while the parent of the current node is not empty, and it is the right child of its parent, keep following the tree upwards.
			tempNode = tempNode->parent;
			if(tempNode->parent == nullptr)//if we reach the root the most recent curr value was the last inorder node.
				return false;
		}
		tempNode = tempNode->parent;
		curr = tempNode;
		return true;

	}
        
        // TO DO: write this function.
        //TO DO: update this return
        
        
    }

    //helper function for next that finds the first item in the BST that matches priorities
    NODE* find(int pri){
    	NODE* current = this->root;
	while(current->priority != pri){
		if(current != nullptr){
			if(current->priority > pri){
				current = current->left;
			}
			else{
				current = current->right;
			}
			if(current == nullptr) return nullptr;
		}
	}
	return current;
    }
    
    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString() {
	if(this->size > 0){
		stringstream ss;
		printInOrder(this->root, ss);//calls recursive function
        	return ss.str();
	}
        return "There are no values in the queue.\n";
        
        
    }

    void printInOrder(NODE* node, ostream& output){
    	if(node == NULL)
		return;

	this->printInOrder(node->left, output);
	output << node->priority << " value: " << node->value << endl;
	if(node->dup == true){
		NODE* temp = node->link;
		while(temp != NULL){
			output << temp->priority << " value: " << temp->value << endl;
			temp = temp->link;
		}

	}
	this->printInOrder(node->right, output);
    }
    
    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T peek() {
        T valueOut;
        if(this->size != 0){//if there is anything left in the BST, peek should return the value of the node with the minimum priority.
		NODE* minimumValue = findMin(this->root);
		valueOut = minimumValue->value;
	}
	else{
		valueOut = "";	
	}
        return valueOut; // TO DO: update this return
        
        
    }
    




    //used for my tests to return the node stored in the "root" variable as a part of the priority queue
    NODE* acquireRoot(){
        return this->root;
    }


    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue& other){
	    if(this->size == 0 && other.size == 0)//removes possibility of there being any garbage values for specific parameters
		    return true;
	    if(this->size != other.size)
		    return false;
	    return equals(this->root, other.root);

    }
    
    bool equals(NODE* &our, NODE* other){//recursive function that checks if the left and right node are equal and how to progress further
    	if(our == nullptr && other == nullptr){ //if both are empty
		return true;
	}
	else if (our == nullptr){ // if "this" BST has an empty node where there is an existing node on the "other" BST
		return false;
	}
	else if (other == nullptr){ // if "other" BST has an empty node where there is an existing node on the "this" BST
		return false;
	}
	else{
		if(equals(our->left, other->left) &&
		   our->value == other->value &&
		   our->priority == other->priority &&
		   equals(our->link, other->link) &&
		   equals(our->right, other->right)){
			return true;
		}
		else{
			return false;
		}

	}
	return false;
    }

    //used for my tests to return the node stored in the "curr" variable as a part of the priority queue
    NODE* getCurr(){
        return this->curr;
    }

    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};
