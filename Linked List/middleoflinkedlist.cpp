// 876. Middle of the Linked List
// Easy

// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.

// Example 2:

// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

 

// Constraints:

//     The number of nodes in the list is in the range [1, 100].
//     1 <= Node.val <= 100

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* head2=head;
        int count=-1;
        while(head2!=NULL)
        {
            count++;
            head2=head2->next;
        }
        if(count&1)
            count++;
        count/=2;
        head2=head;
        while(count--)
        {
            head2=head2->next;
        }
        return head2;
    }
};

//Approach 2 Faster Approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slo=head,*fas=head;
        while(fas and fas->next)
        {
            slo=slo->next;
            fas=fas->next->next;
        }
        return slo;
    }
};