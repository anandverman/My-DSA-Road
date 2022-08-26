// 234. Palindrome Linked List
// Easy

// Given the head of a singly linked list, return true if it is a palindrome.

// Example 1:

// Input: head = [1,2,2,1]
// Output: true

// Example 2:

// Input: head = [1,2]
// Output: false

 

// Constraints:

//     The number of nodes in the list is in the range [1, 105].
//     0 <= Node.val <= 9

// Follow up: Could you do it in O(n) time and O(1) space?

//Approach 1:copy linked list to array and check array for palindrome;

//Approach 2:Reverse list from middle and check values of correspoinding nodes of the lists;

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
    bool isPalindrome(ListNode* head) 
    {
        if(head->next==NULL)
            return true;
        ListNode* slo=head,*fas=head;
        while(fas->next!=NULL and fas->next->next!=NULL)
        {
            fas=fas->next->next;
            slo=slo->next;
        }
        ListNode* prev=NULL,*cur=slo->next,*nex;
        while(cur!=NULL)
        {
            nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
        }
        slo->next=prev;
        while(prev!=NULL)        
        {
            if(head->val!=prev->val)
                return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};  