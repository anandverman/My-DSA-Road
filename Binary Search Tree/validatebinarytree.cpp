// 98. Validate Binary Search Tree
// Medium

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

//     The left subtree of a node contains only nodes with keys less than the node's key.
//     The right subtree of a node contains only nodes with keys greater than the node's key.
//     Both the left and right subtrees must also be binary search trees.

 

// Example 1:

// Input: root = [2,1,3]
// Output: true

// Example 2:

// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

 

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -231 <= Node.val <= 231 - 1

//Recursive Solution
class Solution {
public:
    bool isBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(root==NULL)
            return true;
        if((minNode and root->val<=minNode->val) or (maxNode and root->val>=maxNode->val))
            return false;
        return isBST(root->left, minNode, root) and isBST(root->right, root, maxNode);
    }
    bool isValidBST(TreeNode* root) {
        return isBST(root, NULL, NULL);
    }
};

// Alternate Solution
class Solution {
public:
    long long leftvalue = (long long)INT_MIN-1;
    int result = true;
    void inorder(TreeNode* node) {
        if(!node) {
            return;
        }
        inorder(node->left);
        if(leftvalue >= node->val) {
            result=false;
            return;
        }
        leftvalue=node->val;
        inorder(node->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return result;
    }
};