// 145. Binary Tree Postorder Traversal
// Easy

// Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [3,2,1]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]

 

// Constraints:

//     The number of the nodes in the tree is in the range [0, 100].
//     -100 <= Node.val <= 100

// Follow up: Recursive solution is trivial, could you do it iteratively?

//Recursive Solution

class Solution {
public:
    void postorder(TreeNode* node, vector<int> &ans)
    {
        if(node==NULL)
            return;
        postorder(node->left,ans);
        postorder(node->right,ans);
        ans.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

// Iterative Solution (Modifies tree):

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
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        
        vector<int> ans;
        
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty())
        {
            TreeNode *cur = s.top();
            
            if (cur->left==NULL and cur->right==NULL) //!cur-> left && !cur-> right
            {
                s.pop();
                ans.push_back(cur->val);
            }
            
            if (cur->right!=NULL)
            {
                s.push(cur->right);
                cur->right = NULL;
            }
            
            if (cur->left!=NULL)
            {
                s.push(cur->left);
                cur->left = NULL;
            }
        }
        return ans;
    }
};

//MORRIS MODIFIED POSTORDER
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->right==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->left;
            }    
            else
            {
                TreeNode* prev=cur->right;
                while(prev->left!=NULL and prev->left!=cur)
                {
                    prev=prev->left;
                }
                if(prev->left==NULL)
                {
                    ans.push_back(cur->val);
                    prev->left=cur;                    
                    cur=cur->right;
                }
                else
                {
                    prev->left=NULL;
                    cur=cur->left;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};