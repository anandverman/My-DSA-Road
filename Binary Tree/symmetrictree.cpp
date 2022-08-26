// 101. Symmetric Tree
// Easy

// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false

// Constraints:

//     The number of nodes in the tree is in the range [1, 1000].
//     -100 <= Node.val <= 100

 
// Follow up: Could you solve it both recursively and iteratively?

//Recursive Solution:
class Solution {
public:
    bool Symmetry(TreeNode*root1, TreeNode*root2)
    {
        if(root1==NULL or root2==NULL)
            return root1==root2;
        if(root1->val!=root2->val)
            return false;
        
        return Symmetry(root1->left,root2->right) and Symmetry(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return Symmetry(root->left,root->right);
    }
};

//Iterative Solution:
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) 
        {
            TreeNode* node1 = q.front();
            q.pop();
            TreeNode* node2 = q.front();
            q.pop();
            if((!node1 and node2) or (node1 and !node2) )
                return false;
            if(node1 and node2){
                if(node1->val!=node2->val)
                    return false;
                q.push(node1->left);
                q.push(node2->right);
                q.push(node1->right);
                q.push(node2->left);
            }
        }
        return true;
    }
};