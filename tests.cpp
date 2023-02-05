#include <gtest/gtest.h>
#include "priorityqueue.h"

TEST(emptyqueue, sizeTest) {//tests if the default constructor compiles and initializes size correctly
	priorityqueue<string> pq;
	ASSERT_EQ(pq.Size(), 0);
	pq.clear();
}

TEST(pqueue, enqueue){//tests if the enqueue function compiles correctly and size updates correctly
	priorityqueue<string> pq;
	pq.enqueue("Howard", 1);
	ASSERT_EQ(pq.Size(), 1);
}

TEST(pqueue, enqueue2){//tests if the enqueue function correctly enqueues two items
        priorityqueue<string> pq;
        pq.enqueue("Howard", 1);
	pq.enqueue("Penny", 2);
        ASSERT_EQ(pq.Size(), 2);
}

TEST(pqueue, enqueueDuplicate){//tests if the enqueue function works with two items with the same priority
        priorityqueue<string> pq;
        pq.enqueue("Howard", 1);
        pq.enqueue("Penny", 1);
        ASSERT_EQ(pq.Size(), 2);
}

TEST(sizeTest, completeDuplicates){//tests if two nodes with the same name and priority can be added to the same BST properly
	priorityqueue<string> pq;
	pq.enqueue("Howard", 1);
	pq.enqueue("Howard", 1);
	ASSERT_EQ(pq.Size(), 2);
}

TEST(pqueue, toStringEmpty){//tests if the toString function works properly with nothing in the queue
        priorityqueue<string> pq;
        string pqueue = pq.toString();
        string answer = "There are no values in the queue.\n";
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringOne){//tests if the toString function works properly with one item in the queue
	priorityqueue<string> pq;
        pq.enqueue("Howard", 1);
	string pqueue = pq.toString();
	string answer = "1 value: Howard\n";
        ASSERT_EQ(pq.Size(), 1);
	ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringTwo){//tests if the toString function works properly with two items in the queue
        priorityqueue<string> pq;
        pq.enqueue("Howard", 1);
        pq.enqueue("Penny", 2);
        string pqueue = pq.toString();
        string answer = "1 value: Howard\n2 value: Penny\n";
        ASSERT_EQ(pq.Size(), 2);
	ASSERT_EQ(pqueue, answer);
	pq.enqueue("Flynn", 3);
	answer = "1 value: Howard\n2 value: Penny\n3 value: Flynn\n";
	pqueue = pq.toString();
	ASSERT_EQ(pq.Size(), 3);
	ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringTwoReversed){//tests if the toString function works properly with two items in the queue when they are entered in descending order
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 1);
        string pqueue = pq.toString();
        string answer = "1 value: Penny\n2 value: Howard\n";
        ASSERT_EQ(pq.Size(), 2);
	ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringDupl){//tests if the toString function works properly with two items with the same priorities
        priorityqueue<string> pq;
        pq.enqueue("Howard", 1);
        pq.enqueue("Penny", 1);
        string pqueue = pq.toString();
        string answer = "1 value: Howard\n1 value: Penny\n";
        ASSERT_EQ(pq.Size(), 2);
	ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringMixed){//tests if the toString function works properly with two items with the same priorities
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 1);
	pq.enqueue("Maximus", 2);
        string pqueue = pq.toString();
        string answer = "1 value: Penny\n2 value: Howard\n2 value: Maximus\n";
        ASSERT_EQ(pq.Size(), 3);
	ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringMixed2){//tests if the toString function works properly with two items with the same priorities
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 1);
	pq.enqueue("Flynn", 3);
	pq.enqueue("Rider", 3);
        pq.enqueue("Maximus", 2);
        string pqueue = pq.toString();
        string answer = "1 value: Penny\n2 value: Howard\n2 value: Maximus\n3 value: Flynn\n3 value: Rider\n";
        ASSERT_EQ(pq.Size(), 5);
	ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringTwoDuplicates){//tests if the toString function works properly with two items with the same priorities and values
        priorityqueue<string> pq;
	pq.enqueue("Howard", 1);
	pq.enqueue("Howard", 1);
        ASSERT_EQ(pq.Size(), 2);
	string pqueue = pq.toString();
        string answer = "1 value: Howard\n1 value: Howard\n";
        ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringMultipleDupl){//tests if the toString function works properly with two items with the same priorities and values
        priorityqueue<string> pq;
        pq.enqueue("Howard", 1);
        pq.enqueue("Howard", 1);
	pq.enqueue("Penny", 2);
        ASSERT_EQ(pq.Size(), 3);
        string pqueue = pq.toString();
        string answer = "1 value: Howard\n1 value: Howard\n2 value: Penny\n";
        ASSERT_EQ(pqueue, answer);
}

TEST(pqueue, toStringMixedMultipleDupl){//tests if the toString function works properly with multiple items with the same priorities
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 1);
        pq.enqueue("Howard", 3);
        pq.enqueue("Rider", 3);
        pq.enqueue("Howard", 2);
        string pqueue = pq.toString();
        string answer = "1 value: Penny\n2 value: Howard\n2 value: Howard\n3 value: Howard\n3 value: Rider\n";
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pqueue, answer);
}

TEST(clear, sizeOne){//tests if the clear function works for size function
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        ASSERT_EQ(pq.Size(), 1);
	pq.clear();
        ASSERT_EQ(pq.Size(), 0);
}

TEST(clear, toStringOne){//tests if the clear function works when toString is displayed
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        ASSERT_EQ(pq.Size(), 1);
	string pqueue = pq.toString();
        string answer = "2 value: Howard\n";
	ASSERT_EQ(answer, pqueue);
	pq.clear();
	pqueue = pq.toString();
        ASSERT_EQ(pq.Size(), 0);
	ASSERT_EQ("There are no values in the queue.\n", pqueue);
}

TEST(clear, sizeMult){//tests if the clear function works for size function with multiple nodes
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
	pq.enqueue("Penny", 1);
        ASSERT_EQ(pq.Size(), 2);
        pq.clear();
        ASSERT_EQ(pq.Size(), 0);
}

TEST(clear, toStringMult){//tests if the clear function works when toString is displayed with multiple nodes
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
	pq.enqueue("Penny", 1);
        ASSERT_EQ(pq.Size(), 2);
        string pqueue = pq.toString();
        string answer = "1 value: Penny\n2 value: Howard\n";
        ASSERT_EQ(answer, pqueue);
        pq.clear();
        pqueue = pq.toString();
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ("There are no values in the queue.\n", pqueue);
}

TEST(clear, sizeMultDupRoot){//tests if the clear function works for size function with multiple nodes that have duplicate priorities
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 2);
        ASSERT_EQ(pq.Size(), 2);
        pq.clear();
        ASSERT_EQ(pq.Size(), 0);
}

TEST(clear, toStringMultDupRoot){//tests if the clear function works when toString is displayed with multiple nodes that have duplicate priorities
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 2);
        ASSERT_EQ(pq.Size(), 2);
        string pqueue = pq.toString();
        string answer = "2 value: Howard\n2 value: Penny\n";
        ASSERT_EQ(answer, pqueue);
        pq.clear();
        pqueue = pq.toString();
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ("There are no values in the queue.\n", pqueue);
}

TEST(clear, sizeMultDup){//tests if the clear function works for size function with multiple nodes that have duplicate priorities both of which are not the root
        priorityqueue<string> pq;
	pq.enqueue("Maximus", 1);
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 2);
        ASSERT_EQ(pq.Size(), 3);
        pq.clear();
        ASSERT_EQ(pq.Size(), 0);
}

TEST(clear, toStringMultDup){//tests if the clear function works when toString is displayed with multiple nodes that have duplicate priorities both of which are not the root
        priorityqueue<string> pq;
	pq.enqueue("Maximus", 1);
        pq.enqueue("Howard", 2);
        pq.enqueue("Penny", 2);
        ASSERT_EQ(pq.Size(), 3);
        string pqueue = pq.toString();
        string answer = "1 value: Maximus\n2 value: Howard\n2 value: Penny\n";
        ASSERT_EQ(answer, pqueue);
        pq.clear();
        pqueue = pq.toString();
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ("There are no values in the queue.\n", pqueue);
}

TEST(clear, queueAfterClear){//tests if the queue still works properly after being cleared
	priorityqueue<string> pq;
        pq.enqueue("Flynn", 1);
//	ASSERT_EQ("1 value: Flynn\n", pq.toString());
        pq.enqueue("Rapunzel", 3);
//	ASSERT_EQ("1 value: Flynn\n3 value: Rapunzel\n", pq.toString());
        pq.enqueue("Maximus", 1);
//	ASSERT_EQ("1 value: Flynn\n1 value: Maximus\n3 value: Rapunzel\n", pq.toString());
        pq.enqueue("Simeon", 2);
//	ASSERT_EQ("1 value: Flynn\n1 value: Maximus\n2 value: Simeon\n3 value: Rapunzel\n", pq.toString());
        pq.enqueue("Howard", 2);
//	ASSERT_EQ("1 value: Flynn\n1 value: Maximus\n2 value: Simeon\n2 value: Howard\n3 value: Rapunzel\n", pq.toString());
        pq.enqueue("Penny", 2);
//	ASSERT_EQ("1 value: Flynn\n1 value: Maximus\n2 value: Simeon\n2 value: Howard\n2 value: Penny\n3 value: Rapunzel\n", pq.toString());
        pq.enqueue("Rider", 5);
//	ASSERT_EQ("1 value: Flynn\n1 value: Maximus\n2 value: Simeon\n2 value: Howard\n2 value: Penny\n3 value: Rapunzel\n5 value: Rider\n", pq.toString());
        ASSERT_EQ(pq.Size(), 7);
        string pqueue = pq.toString();
        string answer = "1 value: Flynn\n1 value: Maximus\n2 value: Simeon\n2 value: Howard\n2 value: Penny\n3 value: Rapunzel\n5 value: Rider\n";
        ASSERT_EQ(answer, pqueue);
        pq.clear();
        pqueue = pq.toString();
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ("There are no values in the queue.\n", pqueue);
        pq.enqueue("Maximus", 1);
        pq.enqueue("Rider", 3);
        pq.enqueue("Flynn", 1);
        pq.enqueue("Simeon", 2);
        pq.enqueue("Penny", 2);
        pq.enqueue("Howard", 2);
        pq.enqueue("Rapunzel", 5);
        ASSERT_EQ(pq.Size(), 7);
        pqueue = pq.toString();
        answer = "1 value: Maximus\n1 value: Flynn\n2 value: Simeon\n2 value: Penny\n2 value: Howard\n3 value: Rider\n5 value: Rapunzel\n";
        ASSERT_EQ(answer, pqueue);
	
}

TEST(copy, simple){//tests if two empty priority queues can be set to one another
	priorityqueue<string> pq;
	priorityqueue<string> pq2;
	pq2 = pq;
	ASSERT_EQ(pq.Size(), pq2.Size());
}

TEST(copy, simple2){//tests if one empty priority queue can be set to another (similar to clear function)
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
	pq2.enqueue("Maximus", 1);
	ASSERT_EQ(pq2.Size(), 1);
        pq2 = pq;
        ASSERT_EQ(pq.Size(), pq2.Size());
}

TEST(copy, simple3){//tests if one pqueue can be set to an empty priority queue
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
        ASSERT_EQ(pq2.Size(), 1);
        pq = pq2;
        ASSERT_EQ(pq.Size(), pq2.Size());
}

TEST(copy, simple2ToString){//tests if one empty priority queue can be set to another (similar to clear function)
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
        ASSERT_EQ(pq2.Size(), 1);
        pq = pq2;
        ASSERT_EQ(pq.toString(), "1 value: Maximus\n");
}

TEST(copy, dupNodes){//tests if the copy function works properly with duplicate nodes in the BST
	priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
	pq2.enqueue("Flynn", 1);
        ASSERT_EQ(pq2.Size(), 2);
        pq = pq2;
        ASSERT_EQ(pq.toString(), "1 value: Maximus\n1 value: Flynn\n");
}

TEST(copy, dupNodes2){//tests if the copy function works properly with duplicate nodes in the BST
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
        pq2.enqueue("Maximus", 1);
        ASSERT_EQ(pq2.Size(), 2);
        pq = pq2;
        ASSERT_EQ(pq.toString(), "1 value: Maximus\n1 value: Maximus\n");
}

TEST(copy, dupNodes3){//tests if the copy function works properly with duplicate nodes in the BST
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
        pq2.enqueue("Flynn", 1);
	pq2.enqueue("Maximus", 2);
        ASSERT_EQ(pq2.Size(), 3);
        pq = pq2;
        ASSERT_EQ(pq.toString(), "1 value: Maximus\n1 value: Flynn\n2 value: Maximus\n");
}

TEST(copy, dupNodesNotRoot){//tests if the copy function works properly with duplicate nodes in the BST that are not the root node
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
        pq2.enqueue("Flynn", 2);
        pq2.enqueue("Maximus", 2);
        ASSERT_EQ(pq2.Size(), 3);
        pq = pq2;
        ASSERT_EQ(pq.toString(), "1 value: Maximus\n2 value: Flynn\n2 value: Maximus\n");
}

TEST(copy, duplicateThreeNodes){//tests if the copy function works properly with more than 3 duplicates
	priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq2.enqueue("Maximus", 1);
        pq2.enqueue("Flynn", 2);
        pq2.enqueue("Maximus", 2);
        pq2.enqueue("Walter", 2);
        pq2.enqueue("Ted", 3);
        ASSERT_EQ(pq2.Size(), 5);
        pq = pq2;
        ASSERT_EQ(pq.toString(), "1 value: Maximus\n2 value: Flynn\n2 value: Maximus\n2 value: Walter\n3 value: Ted\n");
}

TEST(begin, emptyNode){//tests if begin makes curr point to nothing when the BST is empty
	priorityqueue<string> pq;
	pq.begin();
	ASSERT_EQ(pq.getCurr(), nullptr);
}

TEST(begin, valueTest){//tests if the begin function sets curr to the correct node;
	priorityqueue<string> pq;
	pq.enqueue("Maximus", 3);
	pq.begin();
	ASSERT_EQ(pq.Size(), 1);
	ASSERT_EQ(pq.getCurr()->value, "Maximus");
}

TEST(begin, priorityTest){//tests if the begin function sets curr to the correct node;
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.begin();
	ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.getCurr()->priority, 2);
}

TEST(begin, multNodes){//tests if the begin function sets curr to the correct node;
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
	pq.enqueue("Saul", 3);
        pq.begin();
	ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.getCurr()->priority, 2);
}

TEST(begin, multNodesReversed){//tests if the begin function sets curr to the correct node;
        priorityqueue<string> pq;
        pq.enqueue("Howard", 3);
        pq.enqueue("Saul", 2);
        pq.begin();
	ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.getCurr()->priority, 2);
}

TEST(begin, multNodes2){//tests if the begin function sets curr to the correct node;
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Saul", 3);
	pq.enqueue("Goodman", 1);
        pq.begin();
	ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.getCurr()->priority, 1);
}

TEST(begin, multNodesDup){//tests if the begin function sets curr to the correct node; The root node has duplicate priorities in the BST
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
        pq.begin();
	ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.getCurr()->priority, 1);
}

TEST(begin, multNodesDup2){//tests if the begin function sets curr to the correct node; There is a node with duplicate priorities in the BST
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Saul", 1);
        pq.enqueue("Goodman", 1);
        pq.begin();
	ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.getCurr()->priority, 1);
}

TEST(begin, multNodesDup3){//tests if the begin function sets curr to the correct node; The root node has duplicate priorities in the BST
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 3);
        pq.begin();
	ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.getCurr()->priority, 2);
}

TEST(next, oneNode){//tests if the next function returns false when there is only one node in the BST
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.begin();
	int pri = 0;
	string name = "";
	ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.next(name, pri), false);
}

TEST(next, twoNodes){//tests if the next function returns the correct node's data members and sets curr to the correct node.
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Nancy", 3);
        pq.begin();
        int pri = 0;
        string name = "";
	ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.next(name, pri), true);
}

TEST(next, twoNodes2){//tests if the next function returns the correct node's data members and sets curr to the correct node.
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Nancy", 1);
        pq.begin();
        int pri = 0;
        string name = "";
        ASSERT_EQ(pq.Size(), 2);
	ASSERT_EQ(pq.next(name, pri), true);
}

TEST(next, threeNodes){//tests if the next function returns the correct node's data members and sets curr to the correct node.
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.enqueue("Nancy", 1);
	pq.enqueue("Saul", 3);
        pq.begin();
        int pri = 0;
        string name = "";
	pq.next(name, pri);
	ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.next(name, pri), true);
}

TEST(next, oneNodeMembers){//tests if the next function changes the parameters given
        priorityqueue<string> pq;
        pq.enqueue("Howard", 2);
        pq.begin();
        int pri = 0;
        string name = "";
	pq.next(name, pri);
	ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(name, "Howard");
	ASSERT_EQ(pri, 2);
}

TEST(next, twoNodesMembers){//tests if the next function returns the correct node's data members and sets curr to the correct node.
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
        pq.begin();
        int pri = 1;
        string name = "f";
	ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.next(name, pri), true);
	ASSERT_EQ(pri, 1);
	ASSERT_EQ(name, "Goodman");
}

TEST(next, twoNodesMembers2){//tests if the next function returns the correct node's data members and sets curr to the correct node.
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
	ASSERT_EQ(pq.Size(), 2);
}

TEST(next, ThreeNodes){//tests if the next function returns the correct node's data members and sets curr to the correct nodes.
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
	pq.enqueue("Walter", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
	ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Goodman");
	ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
	ASSERT_EQ(pq.Size(), 3);
}

TEST(next, ThreeNodes2){//tests if the next function returns the correct node's data members and sets curr to the correct nodes.
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
        pq.enqueue("Walter", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
	ASSERT_EQ(pq.Size(), 3);
}

TEST(next, ThreeNodesRightHeavy){//tests if the next function returns the correct node's data members and sets curr to the correct nodes when the BST is right heavy
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 4);
        pq.enqueue("Walter", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Goodman");
	ASSERT_EQ(pq.Size(), 3);
}

TEST(next, ThreeNodesLeftHeavy){//tests if the next function returns the correct node's data members and sets curr to the correct nodes when the BST is left heavy
        priorityqueue<string> pq;
        pq.enqueue("Saul", 4);
        pq.enqueue("Goodman", 2);
        pq.enqueue("Walter", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Saul");
	ASSERT_EQ(pq.Size(), 3);
}

TEST(next, callAfterEndOfBST){//tests if the next function still returns false and doesn't change the values passed in as parameters after running next when it has already reached the last inorder node.
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 4);
        pq.enqueue("Walter", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Goodman");
	ASSERT_EQ(pq.Size(), 3);
}

TEST(next, manyNodes){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 4);
        pq.enqueue("Walter", 3);
	pq.enqueue("White", 1);
	pq.enqueue("Mike", 6);
	pq.enqueue("Ehrmantraut", 5);
        pq.begin();
        int pri = 1;
        string name = "f";
	ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "White");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 5);
        ASSERT_EQ(name, "Ehrmantraut");
	ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 6);
        ASSERT_EQ(name, "Mike");
	ASSERT_EQ(pq.Size(), 6);
}

TEST(next, dupNodeRoot){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 2);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Goodman");
	ASSERT_EQ(pq.Size(), 2);
}

TEST(next, ThreedupNodeRoot){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 2);
	pq.enqueue("Walter", 2);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Goodman");
	ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Walter");
	ASSERT_EQ(pq.Size(), 3);
}

TEST(next, dupNodeNotRoot){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
	priorityqueue<string> pq;
        pq.enqueue("Saul", 1);
        pq.enqueue("Goodman", 2);
	pq.enqueue("Walter", 2);
	pq.enqueue("White", 2);
	pq.enqueue("Jesse", 3);
	pq.enqueue("Pinkman", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Goodman");
	ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Walter");
	ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "White");
	ASSERT_EQ(pq.next(name, pri), true);
	ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Jesse");
	ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Pinkman");
	ASSERT_EQ(pq.Size(), 6);
}

TEST(next, dupNodeRoot2){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
        pq.enqueue("Walter", 1);
        pq.enqueue("White", 2);
        pq.enqueue("Jesse", 4);
        pq.enqueue("Pinkman", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "White");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Pinkman");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Jesse");
	ASSERT_EQ(pq.Size(), 6);
}

TEST(next, dupNode2){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
        pq.enqueue("Walter", 1);
        pq.enqueue("White", 2);
        pq.enqueue("Jesse", 4);
        pq.enqueue("Pinkman", 3);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "White");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Pinkman");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Jesse");
	ASSERT_EQ(pq.Size(), 6);
}

TEST(next, dupNodeLeftHeavy){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes 
        priorityqueue<string> pq;
        pq.enqueue("Saul", 4);
        pq.enqueue("Goodman", 2);
        pq.enqueue("Walter", 3);
        pq.enqueue("White", 3);
        pq.enqueue("Jesse", 2);
        pq.enqueue("Pinkman", 2);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Jesse");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Pinkman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "White");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 4);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.Size(), 6);
}

TEST(next, dupNodeRightHeavy){//tests if the next function assigns the parameters passed in as the correct values and assigns curr to the correct nodes
        priorityqueue<string> pq;
        pq.enqueue("Saul", 1);
        pq.enqueue("Goodman", 2);
        pq.enqueue("Walter", 3);
        pq.enqueue("White", 3);
        pq.enqueue("Jesse", 2);
        pq.enqueue("Pinkman", 2);
        pq.begin();
        int pri = 1;
        string name = "f";
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 1);
        ASSERT_EQ(name, "Saul");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Goodman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Jesse");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 2);
        ASSERT_EQ(name, "Pinkman");
        ASSERT_EQ(pq.next(name, pri), true);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "Walter");
        ASSERT_EQ(pq.next(name, pri), false);
        ASSERT_EQ(pri, 3);
        ASSERT_EQ(name, "White");
        ASSERT_EQ(pq.Size(), 6);
}

TEST(dequeue, empty){//tests if the dequeue function correctly doesn't do anything when the priority queue is empty.
        priorityqueue<string> pq;
        ASSERT_EQ(pq.dequeue(), "");//should return empty string
}

TEST(dequeue, oneNode){//tests if the dequeue function correctly deletes a node when it is the only node in the BST
	priorityqueue<string> pq;
	pq.enqueue("Saul", 1);
	ASSERT_EQ(pq.dequeue(), "Saul");
}

TEST(dequeue, twoNodesRoot){//tests if the dequeue function correctly deletes the front node when there are only two nodes in the BST, and the node being deleted is the root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 1);
	pq.enqueue("Goodman", 2);
        ASSERT_EQ(pq.dequeue(), "Saul");
}

TEST(dequeue, twoNodesNotRoot){//tests if the dequeue function correctly deletes the front node when there are only two nodes in the BST, and the node being deleted is not the root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
        ASSERT_EQ(pq.dequeue(), "Goodman");
}

TEST(dequeue, threeNodesBalanced){//tests if the dequeue function correctly deletes each of the items in the queue, and returns an empty string when there is nothing left to dequeue.
        priorityqueue<string> pq;
        pq.enqueue("Saul", 2);
        pq.enqueue("Goodman", 1);
	pq.enqueue("Mike", 3);
        ASSERT_EQ(pq.dequeue(), "Goodman");
	ASSERT_EQ(pq.dequeue(), "Saul");
	ASSERT_EQ(pq.dequeue(), "Mike");
	ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, threeNodesLeftHeavy){//same test as before on a left-heavy BST that goes left then right
	priorityqueue<string> pq;
        pq.enqueue("Saul", 3);
        pq.enqueue("Goodman", 1);
        pq.enqueue("Mike", 2);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.dequeue(), "Mike");
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.dequeue(), "");

}

TEST(dequeue, threeNodesLeftHeavy2){//same test as before on a left-heavy BST that goes straight down left
        priorityqueue<string> pq;
        pq.enqueue("Saul", 3);
        pq.enqueue("Goodman", 2);
        pq.enqueue("Mike", 1);
        ASSERT_EQ(pq.dequeue(), "Mike");
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.dequeue(), "");

}

TEST(dequeue, threeNodesRightHeavy){//same test as before on a right-heavy BST that goes straight down right
        priorityqueue<string> pq;
        pq.enqueue("Saul", 1);
        pq.enqueue("Goodman", 2);
        pq.enqueue("Mike", 3);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.dequeue(), "Mike");
        ASSERT_EQ(pq.dequeue(), "");

}

TEST(dequeue, threeNodesRightHeavy2){//same test as before on a right-heavy BST that goes right then left
        priorityqueue<string> pq;
        pq.enqueue("Saul", 1);
        pq.enqueue("Goodman", 3);
        pq.enqueue("Mike", 2);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.dequeue(), "Mike");
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.dequeue(), "");

}

TEST(dequeue, mixedNodes){//tests if the dequeue function works on multiple nodes that are inserted in random order with no duplicates
	priorityqueue<string> pq;
        pq.enqueue("Saul", 50);
        pq.enqueue("Goodman", 80);
        pq.enqueue("Mike", 70);
	pq.enqueue("Ehrmantraut", 20);
	pq.enqueue("Walter", 30);
	pq.enqueue("White", 40);
	pq.enqueue("Jimmy", 10);
	pq.enqueue("McGill", 9);
	pq.enqueue("Jesse", 7);
	pq.enqueue("Pinkman", 8);
	pq.enqueue("Skyler", 6);
	pq.enqueue("Marie", 5);
	ASSERT_EQ(pq.Size(), 12);
	ASSERT_EQ(pq.dequeue(), "Marie");
        ASSERT_EQ(pq.dequeue(), "Skyler");
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.dequeue(), "McGill");
        ASSERT_EQ(pq.dequeue(), "Jimmy");
        ASSERT_EQ(pq.dequeue(), "Ehrmantraut");
        ASSERT_EQ(pq.dequeue(), "Walter");
	ASSERT_EQ(pq.dequeue(), "White");
	ASSERT_EQ(pq.dequeue(), "Saul");
	ASSERT_EQ(pq.dequeue(), "Mike");
	ASSERT_EQ(pq.dequeue(), "Goodman");
	ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, mixedNodesLeftHeavy){//tests if the dequeue function works on multiple nodes that are inserted in random order with no duplicates on a LeftHeavy BST
        priorityqueue<string> pq;
        pq.enqueue("Saul", 50);
        pq.enqueue("Goodman", 45);
        pq.enqueue("Mike", 42);
        pq.enqueue("Ehrmantraut", 20);
        pq.enqueue("Walter", 30);
        pq.enqueue("White", 40);
        pq.enqueue("Jimmy", 41);
        pq.enqueue("McGill", 39);
        pq.enqueue("Jesse", 35);
        pq.enqueue("Pinkman", 37);
        pq.enqueue("Skyler", 38);
        pq.enqueue("Marie", 9);
        ASSERT_EQ(pq.Size(), 12);
        ASSERT_EQ(pq.dequeue(), "Marie");
        ASSERT_EQ(pq.dequeue(), "Ehrmantraut");
        ASSERT_EQ(pq.dequeue(), "Walter");
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.dequeue(), "Skyler");
        ASSERT_EQ(pq.dequeue(), "McGill");
        ASSERT_EQ(pq.dequeue(), "White");
        ASSERT_EQ(pq.dequeue(), "Jimmy");
        ASSERT_EQ(pq.dequeue(), "Mike");
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, mixedNodesRighttHeavy){//tests if the dequeue function works on multiple nodes that are inserted in random order with no duplicates on a right-heavy BST
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 38);
        pq.enqueue("Mike", 37);
        pq.enqueue("Ehrmantraut", 35);
        pq.enqueue("Walter", 39);
        pq.enqueue("White", 41);
        pq.enqueue("Jimmy", 40);
        pq.enqueue("McGill", 30);
        pq.enqueue("Jesse", 20);
        pq.enqueue("Pinkman", 42);
        pq.enqueue("Skyler", 45);
        pq.enqueue("Marie", 50);
        ASSERT_EQ(pq.Size(), 12);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.dequeue(), "McGill");
        ASSERT_EQ(pq.dequeue(), "Ehrmantraut");
        ASSERT_EQ(pq.dequeue(), "Mike");
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.dequeue(), "Walter");
        ASSERT_EQ(pq.dequeue(), "Jimmy");
        ASSERT_EQ(pq.dequeue(), "White");
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.dequeue(), "Skyler");
        ASSERT_EQ(pq.dequeue(), "Marie");
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, dupNodesRoot){//tests if the dequeue function works properly with duplicate nodes that are part of the root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 9);
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, dupNodesRoot2){//tests if the dequeue function works properly with duplicate nodes that have the same value that are a part of hte root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Saul", 9);
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, dupNodesNotRoot){//tests if the dequeue function works properly with duplicate nodes that are not the root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Jesse", 10);
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, dupNodesNotRoot2){//tests if the dequeue function works properly with duplicate nodes that have the same value that are not the root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Goodman", 10);
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, dupNodesNotRoot3){//tests if the dequeue function works properly with duplicate nodes that have the same value that are not the root
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Saul", 10);
        pq.enqueue("Goodman", 10);
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, multDuplicatesRoot){//tests if the dequeue function works properly with more than two duplicate nodes linked to the root node
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Saul", 9);
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 10);
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, multDuplicatesNotRoot){//tests if the dequeue function works properly with more than two duplicate nodes not linked to the root node
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Goodman", 10);
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, multDuplicateSetsRoot){//tests if the dequeue function works properly with more than two duplicate nodes including the root node
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Jesse", 11);
        pq.enqueue("Jesse", 11);
        pq.enqueue("Pinkman", 8);
        pq.enqueue("Pinkman", 8);
        ASSERT_EQ(pq.Size(), 8);
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.Size(), 7);
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(dequeue, multDuplicateNoRoot){//tests if the dequeue function works properly with more than two duplicate nodes not including the root node
        priorityqueue<string> pq;
        pq.enqueue("Saul", 9);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Goodman", 10);
        pq.enqueue("Jesse", 11);
        pq.enqueue("Jesse", 11);
	pq.enqueue("Jimmy", 12);
        pq.enqueue("Pinkman", 8);
        pq.enqueue("Pinkman", 8);
        ASSERT_EQ(pq.Size(), 8);
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.Size(), 7);
        ASSERT_EQ(pq.dequeue(), "Pinkman");
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.dequeue(), "Saul");
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), "Goodman");
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), "Jesse");
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), "Jimmy");
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), "");
}

TEST(peek, empty){//tests if the peek function correctly returns nothing when run on an empty priority queue
        priorityqueue<string> pq;
        ASSERT_EQ(pq.Size(), 0);
	ASSERT_EQ(pq.peek(), "");
	ASSERT_EQ(pq.dequeue(), "");
}

TEST(peek, oneNode){//tests if the peek function returns the correct node's value when run on a priority queue with only one node
        priorityqueue<string> pq;
	pq.enqueue("Mirror", 1);
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.peek(), "Mirror");
}

TEST(peek, multiplePeeks){//tests if the peek function correctly returns the correct node's value multiple times on a priority queue with only one node
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 1);
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.peek(), "Mirror");
        ASSERT_EQ(pq.peek(), "Mirror");
        ASSERT_EQ(pq.peek(), "Mirror");
        ASSERT_EQ(pq.peek(), "Mirror");
        ASSERT_EQ(pq.peek(), "Mirror");
	
}

TEST(peek, testWithDequeue){//tests if the peek function correctly returns the correct node by checking with the dequeue function
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 1);
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.peek(), "Mirror");
	ASSERT_EQ(pq.dequeue(), pq.peek());//the assert_eq function from gtest runs the parameter on the right side first, meaning pq.peek() must be on the right side, otherwise the dequeue function runs before the peek function, meaning there would be nothing left in the queue for the peek function to return
}

TEST(peek, testWithDequeueRightHeavy){//tests if the peek function works properly with a right-heavy BST
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 1);
        pq.enqueue("Exactly", 1);
        pq.enqueue("Don't", 2);
        pq.enqueue("Pro", 2);
        pq.enqueue("Rep", 3);
        pq.enqueue("Error", 3);
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.peek(), "Mirror");
        ASSERT_EQ(pq.dequeue(), pq.peek());//the assert_eq function from gtest runs the parameter on the right side first, meaning pq.peek() must be on the right side, otherwise the dequeue function runs before the peek function, meaning there would be nothing left in the queue for the peek function to return
        ASSERT_EQ(pq.Size(), 5);
	ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 4);
	ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 3);
	ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 2);
	ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), pq.peek());
}

TEST(peek, testWithDequeueLeftHeavy){//tests if the peek function works properly with a left-heavy BST
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 3);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 2);
        pq.enqueue("Pro", 2);
        pq.enqueue("Rep", 1);
        pq.enqueue("Error", 1);
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.peek(), "Rep");
        ASSERT_EQ(pq.dequeue(), pq.peek());//the assert_eq function from gtest runs the parameter on the right side first, meaning pq.peek() must be on the right side, otherwise the dequeue function runs before the peek function, meaning there would be nothing left in the queue for the peek function to return
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), pq.peek());
}

TEST(peek, testWithDequeueLeftHeavy2){//tests if the peek function works properly with a left-heavy BST
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 5);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 1);
        pq.enqueue("Pro", 2);
        pq.enqueue("Rep", 2);
        pq.enqueue("Pocket", 2);
        pq.enqueue("Error", 4);
        ASSERT_EQ(pq.Size(), 7);
        ASSERT_EQ(pq.peek(), "Don't");
        ASSERT_EQ(pq.dequeue(), pq.peek());//the assert_eq function from gtest runs the parameter on the right side first, meaning pq.peek() must be on the right side, otherwise the dequeue function runs before the peek function, meaning there would be nothing left in the queue for the peek function to return
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), pq.peek());
}

TEST(peek, testWithDequeueRightHeavy2){//tests if the peek function works properly with a right-heavy BST
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 1);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 5);
        pq.enqueue("Pro", 4);
        pq.enqueue("Rep", 4);
        pq.enqueue("Pocket", 4);
        pq.enqueue("Error", 2);
        ASSERT_EQ(pq.Size(), 7);
        ASSERT_EQ(pq.peek(), "Mirror");
        ASSERT_EQ(pq.dequeue(), pq.peek());//the assert_eq function from gtest runs the parameter on the right side first, meaning pq.peek() must be on the right side, otherwise the dequeue function runs before the peek function, meaning there would be nothing left in the queue for the peek function to return
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), pq.peek());
}

TEST(peek, testWithDequeueMixed){//tests if the peek function works properly with a BST with duplicate nodes and 12 well spread items
        priorityqueue<string> pq;
        pq.enqueue("Mirror", 6);
        pq.enqueue("Exactly", 4);
        pq.enqueue("Don't", 7);
        pq.enqueue("Pro", 7);
        pq.enqueue("Rep", 2);
        pq.enqueue("Pocket", 3);
        pq.enqueue("Error", 2);
        pq.enqueue("When", 2);
        pq.enqueue("No", 1);
        pq.enqueue("Breathe", 10);
        pq.enqueue("Watch", 9);
        pq.enqueue("Through", 9);
        ASSERT_EQ(pq.Size(), 12);
        ASSERT_EQ(pq.peek(), "No");
        ASSERT_EQ(pq.dequeue(), pq.peek());//the assert_eq function from gtest runs the parameter on the right side first, meaning pq.peek() must be on the right side, otherwise the dequeue function runs before the peek function, meaning there would be nothing left in the queue for the peek function to return
        ASSERT_EQ(pq.Size(), 11);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 10);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 9);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 8);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 7);
        ASSERT_EQ(pq.dequeue(), pq.peek());
	ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 5);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 4);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 3);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 2);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 1);
        ASSERT_EQ(pq.dequeue(), pq.peek());
        ASSERT_EQ(pq.Size(), 0);
        ASSERT_EQ(pq.dequeue(), pq.peek());
}

TEST(equality, emptyBSTs){//tests whether two empty BSTs are equal
	priorityqueue<string> pq;
	priorityqueue<string> pq2;
	ASSERT_EQ(pq == pq2, true);
}

TEST(equality, SameNode){//tests whether two BSTs with the same item are equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
	pq.enqueue("Howard", 2);
	pq2.enqueue("Howard", 2);
        ASSERT_EQ(pq == pq2, true);
}

TEST(equality, DifferentNodes){//tests whether two BSTs with different items are equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Howard", 2);
        pq2.enqueue("Chuck", 3);
        ASSERT_EQ(pq == pq2, false);
}

TEST(equality, DifferentValue){//tests whether two BSTs with one node in each with different priorities are equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Howard", 2);
        pq2.enqueue("Chuck", 2);
        ASSERT_EQ(pq == pq2, false);
}

TEST(equality, DifferentPriority){//tests whether two BSTs with one node in each with different values are equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Howard", 2);
        pq2.enqueue("Howard", 3);
        ASSERT_EQ(pq == pq2, false);
}

TEST(equality, duplicate){//tests whether two BSTs with the same duplicate roots are scanned as equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Howard", 2);
        pq.enqueue("Howard", 2);
	pq2 = pq;
	ASSERT_EQ(pq == pq2, true);
}

TEST(equality, duplicateInequal){//tests whether two BSTs with the same duplicate roots are scanned as equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Howard", 2);
        pq.enqueue("Howard", 2);
        pq2 = pq;
	pq2.enqueue("Recognize", 1);
        ASSERT_EQ(pq == pq2, false);
}


TEST(equality, duplicateNotRoot){//tests whether two BSTs with the duplicate values that are not the root.
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
	pq.enqueue("Street", 1);
        pq.enqueue("Howard", 2);
        pq.enqueue("Howard", 2);
        pq2 = pq;
        ASSERT_EQ(pq == pq2, true);
}

TEST(equality, duplicateNotRootInequal){//tests whether two BSTs with the duplicate values that are not the root.
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Street", 1);
        pq.enqueue("Howard", 2);
        pq.enqueue("Howard", 2);
        pq2 = pq;
	pq.enqueue("Howard", 2);
        ASSERT_EQ(pq == pq2, false);
}

TEST(equality, duplicateNotRoot2){//tests whether two BSTs with the duplicate values that are not the root.
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Street", 2);
        pq.enqueue("Howard", 1);
        pq.enqueue("Howard", 1);
        pq2 = pq;
        ASSERT_EQ(pq == pq2, true);
}

TEST(equality, duplicateLeftHeavy){//tests whether two left heavy BST's that are equal return equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
	pq.enqueue("Mirror", 3);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 2);
        pq.enqueue("Pro", 2);
        pq.enqueue("Rep", 1);
        pq.enqueue("Error", 1);
        ASSERT_EQ(pq.Size(), 6);
        pq2 = pq;
	ASSERT_EQ(pq2.Size(), 6);
	ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq == pq2, true);
}

TEST(equality, duplicateRightHeavy){//tests whether two right heavy BST's that are equal return equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Mirror", 1);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 5);
        pq.enqueue("Pro", 4);
        pq.enqueue("Rep", 4);
        pq.enqueue("Pocket", 4);
        pq.enqueue("Error", 2);
        ASSERT_EQ(pq.Size(), 7);
	pq2.enqueue("Mirror", 1);
        pq2.enqueue("Exactly", 3);
        pq2.enqueue("Don't", 5);
        pq2.enqueue("Pro", 4);
        pq2.enqueue("Rep", 4);
        pq2.enqueue("Pocket", 4);
        pq2.enqueue("Error", 2);
        ASSERT_EQ(pq2.Size(), 7);
        ASSERT_EQ(pq.Size(), 7);
        ASSERT_EQ(pq == pq2, true);
}

TEST(equality, duplicateRightHeavy2){//tests whether two right heavy BST's that are equal return equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
        pq.enqueue("Mirror", 1);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 5);
        pq.enqueue("Pro", 4);
        pq.enqueue("Rep", 4);
        pq.enqueue("Error", 2);
        ASSERT_EQ(pq.Size(), 6);
        pq2 = pq;
	ASSERT_EQ(pq2.Size(), 6);
        ASSERT_EQ(pq.Size(), 6);
        ASSERT_EQ(pq == pq2, true);
}

TEST(equality, duplicateLeftHeavy2){//tests whether two left heavy BST's that are equal return equal
        priorityqueue<string> pq;
        priorityqueue<string> pq2;
	pq.enqueue("Mirror", 5);
        pq.enqueue("Exactly", 3);
        pq.enqueue("Don't", 1);
        pq.enqueue("Pro", 2);
        pq.enqueue("Rep", 2);
        pq.enqueue("Pocket", 2);
        pq.enqueue("Error", 4);
	pq2 = pq;
        ASSERT_EQ(pq.Size(), 7);
	ASSERT_EQ(pq2.Size(), 7);
	ASSERT_EQ(pq == pq2, true);
}
