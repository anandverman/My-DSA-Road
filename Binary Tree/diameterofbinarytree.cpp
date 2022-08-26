// 543. Diameter of Binary Tree
// Easy

// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.
 

// Example 1:

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

// Example 2:

// Input: root = [1,2]
// Output: 1

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -100 <= Node.val <= 100

//Naive Solution:
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+ max(height(root->left),height(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int d1=height(root->left)+height(root->right);
        int d2=diameterOfBinaryTree(root->left);
        int d3=diameterOfBinaryTree(root->right);
        return max(d1,max(d2,d3));
    }
};

//Optimized Solution:
class Solution {
public:
    int height(TreeNode* root, int &diameter)
    {
        if(root==NULL)
            return 0;
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;        
    }
};