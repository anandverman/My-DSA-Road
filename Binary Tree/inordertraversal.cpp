// 94. Binary Tree Inorder Traversal
// Easy

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:

// Input: root = []
// Output: []

// Example 3:

// Input: root = [1]
// Output: [1]

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 100].
//     -100 <= Node.val <= 100

 
// Follow up: Recursive solution is trivial, could you do it iteratively?

//Recursive Solution:

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
    void inorder(TreeNode* node, vector<int> &ans)
    {
        if(node==NULL)
            return;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

//Iterative Solution:Striver solution

vector < int > inOrderTrav(node * curr) {
  vector < int > inOrder;
  stack < node * > s;
  while (true) {
    if (curr != NULL) {
      s.push(curr);
      curr = curr -> left;
    } else {
      if (s.empty()) break;
      curr = s.top();
      inOrder.push_back(curr -> data);
      s.pop();
      curr = curr -> right;
    }
  }
  return inOrder;
}

//Iterative Solution: MORRIS INORDER TRAVERSAL

class Solution {
public:
    void inorder(TreeNode* node, vector<int> &ans)
    {
        if(node==NULL)
            return;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                ans.push_back(cur->val);
                cur=cur->right;
            }    
            else
            {
                TreeNode* prev=cur->left;
                while(prev->right!=NULL and prev->right!=cur)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};