// Problem Statement
// You are given a linked list containing N nodes, where every node in the linked list contains two pointers, 
// first one is ‘NEXT’ which points to the next node in the list and the second one is ‘CHILD’ pointer to a linked list 
// where the head is this node. And each of these child linked lists is in sorted order.
// Your task is to flatten this linked such that all nodes appear in a single layer or level while the nodes should 
// maintain the sorted order.

// Note:
// The flattened list will be printed using the bottom pointer instead of the next pointer.
// The value of any node in the linked list will not be equal to -1.

// Input format :
// The first line of input contains an integer ‘T’ denoting the number of test cases.
// The first line of the test case contains ‘N’ which represents the number of next-nodes in the linked list.

// The description of the next N lines is as follows-
// Each line contains space-separated integers which are the child nodes of the head linked list 
// and each line ends with -1 to indicate that the sublist is over. Thus, -1 will never be a linked list element.

// Output format :
// For each test case, return the head node of the final linked list. 
// The output of each test case will be printed in a separate line.

// Note:
// You don’t have to print anything; it has already been taken care of. Just implement the given function. 

// Constraints:

// 1 <= T <= 5
// 1 <= N <= 100
// 1 <= C <= 20
// 1 <= data <= 1000

// Time Limit: 1sec

// Sample Input 1 :

// 2
// 5
// 3 4 6  -1
// 5 11 14 -1
// 22 25 -1
// 26 28 -1
// 39  -1
// 4
// 1 2 3 -1
// 8 10 15 -1
// 18 22 -1
// 29 -1

// Sample Output 1 :

// 3 4 5 6 11 14 22 25 26 28 39
// 1 2 3 4 6 8 10 15 18 22 29

// Explanation For Sample Input 1:

// For the first test case:
// The given linked list is :

// Therefore after flattening the list will become-
// 3 -> 4 ->  5 ->  6 -> 11 -> 14 -> 22 -> 25 -> 26 -> 28 -> 39->null
// Note that: the list after flattening should be sorted!

// For the second test case:

// The given linked list is 

// Therefore after flattening the list will become-
// 1 -> 2 ->  3 ->  4 -> 6 -> 8 -> 10 -> 15 -> 18 -> 22 -> 29 ->null

// Sample Input 2 :

// 3
// 5
// 4 6 -1
// 5 71 -1
// 7 8 9 -1
// 11 12 19 -1
// 14 15 17 -1
// 2
// 3 4 -1
// 5 6 7 8 -1
// 1
// 3 -1 

// Sample Output 2 :

// 4 5 6 7 8 9 11 12 14 15 17 19 71
// 3 4 5 6 7 8
// 3

//Solution using Recursive Merge approach from end of list

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* mergelist(Node* h1,Node* h2)
{
    Node* top=new Node(0),*ptr=top;
    while(h1!=NULL and h2!=NULL)
    {
        if(h1->data < h2->data)
        {
            ptr->child=h1;
            ptr=ptr->child;
            h1=h1->child;
        }
        else
        {
            ptr->child=h2;
            ptr=ptr->child;
            h2=h2->child;
        }
    }
    if(h2)
        ptr->child=h2;
    else
        ptr->child=h1;
    return top->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head==NULL or head->next==NULL)
        return head;
    head->next =flattenLinkedList(head->next);
    head =mergelist(head,head->next);
    return head;    
}
