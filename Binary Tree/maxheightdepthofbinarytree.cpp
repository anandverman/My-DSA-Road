// 104. Maximum Depth of Binary Tree
// Easy

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:

// Input: root = [1,null,2]
// Output: 2

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 104].
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
//Recursive Solution: PostOrder Traversal
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lsHeight=maxDepth(root->left); //height of left subtree 
        int rsHeight=maxDepth(root->right); //height of right subtree 
        
        return 1+ max(lsHeight,rsHeight); //height at current node = 1 + max of heights of left and right subtree.
    }
};

//Compressed Solution:
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
    }
};

//Iterative Solution: Level Order Traversal
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> q;
        int depth=0;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};