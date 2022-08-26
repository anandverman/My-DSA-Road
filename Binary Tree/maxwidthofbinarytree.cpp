// Leetcode
// 662. Maximum Width of Binary Tree
// Medium

// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
// where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level 
// are also counted into the length calculation.

// It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

// Example 1:

// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

// Example 2:

// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
// Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

// Example 3:

// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width exists in the second level with length 2 (3,2).

// Constraints:

//     The number of nodes in the tree is in the range [1, 3000].
//     -100 <= Node.val <= 100


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//Solution:Time Complexity: O(N)

// Reason: We are doing a simple level order traversal. The inner loop simply traverses the nodes level-wise and doesn’t 
// add to the complexity.

// Space Complexity: O(N)

class Solution {
public:
    long long widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        long long ans=0;
        queue <pair<TreeNode*, long long>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            long long minindex=q.front().second; //min index at current level
            long long first, last;  //to store indexes of first and last element at current level
            for(int i=0; i<size; i++)
            {
                long long currindex=q.front().second-minindex;
                TreeNode* node=q.front().first;
                q.pop();
                
                if(i==0)
                    first=currindex;
                if(i==size-1)
                    last=currindex;
                
                if(node->left!=NULL)
                    q.push({node->left,2*currindex+1});
                if(node->right!=NULL)
                    q.push({node->right,2*currindex+2});
            }
            ans=(ans > last+1-first ? ans : last+1-first);
        }
        return ans;
    }
};