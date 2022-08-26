// 142. Linked List Cycle II
// Medium

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Example 2:

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Example 3:

// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.

// Constraints:

//     The number of the nodes in the list is in the range [0, 104].
//     -105 <= Node.val <= 105
//     pos is -1 or a valid index in the linked-list.

//Approach 1: Brute Force
// Approach: We can store nodes in a hash table so that, if a loop exists, the head will encounter the same node again. 
// This node will be present in the table and hence, we can detect the loop

// Approach 2: Slow and Fast Pointer Method

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *slo=head,*fas=head;
        int flag=0;
        if(head==NULL or head->next==NULL)
            return NULL;
        while(fas->next!=NULL and fas->next->next!=NULL)
        {
            slo=slo->next;
            fas=fas->next->next;
            if(slo==fas)
            {
                slo=head;
                while(slo!=fas)
                {
                    slo=slo->next;
                    fas=fas->next;
                }
                return slo;
            }
        }
        return NULL;
    }
};