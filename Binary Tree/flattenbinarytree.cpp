// 114. Flatten Binary Tree to Linked List
// Medium

// Given the root of a binary tree, flatten the tree into a "linked list":

//     The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list 
//     and the left child pointer is always null.
//     The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Example 1:

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [0]
// Output: [0]

// Constraints:

//     The number of nodes in the tree is in the range [0, 2000].
//     -100 <= Node.val <= 100

// Follow up: Can you flatten the tree in-place (with O(1) extra space)?

//Recursive Solution: 
// Time Complexity: O(N)
// Reason: We are doing a simple preorder traversal.

// Space Complexity: O(N)
// Reason: Worst case time complexity will be O(N) (in case of skewed tree).

class Solution {
public:
    TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        flatten(root->right);
        flatten(root->left);

        root->right=prev;        
        root->left=NULL;
        prev=root;
    }
};

//Iterative Solution: Using Stack
// Time Complexity: O(N)
// Reason: The loop will execute for every node once.

// Space Complexity: O(N)

class Solution {
public:
    void flatten(TreeNode* root)
    {
        stack<TreeNode*> st;
        if(!root)
            return;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr=st.top();
            st.pop();
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
            if(!st.empty())
                curr->right=st.top();
            curr->left=NULL;
        }
    }
};

//Iterative Solution: Using concept of morris traversal.
// Time Complexity: O(N)
// Reason: Time complexity will be the same as that of a morris traversal

// Space Complexity: O(1)
// Reason: We are not using any extra space.

class Solution {
public:
    void flatten(TreeNode* root)
    {
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* prev=curr->left;
                while(prev->right)
                    prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
            
        }
    }
};