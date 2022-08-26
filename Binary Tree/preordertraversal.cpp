// 144. Binary Tree Preorder Traversal
// Easy

// Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

// Example 1:

// Input: root = [1,null,2,3]
// Output: [1,2,3]

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

//Recursive Solution

class Solution {
public:
    void preorder(TreeNode* node, vector<int> &ans)
    {
        if(node==NULL)
            return;        
        ans.push_back(node->val);
        preorder(node->left,ans);
        preorder(node->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

//Iterative Solution:Striver Solution

vector < int > preOrderTrav(node * curr) {
  vector < int > preOrder;
  if (curr == NULL)
    return preOrder;

  stack < node * > s;
  s.push(curr);

  while (!s.empty()) {
    node * topNode = s.top();
    preOrder.push_back(topNode -> data);
    s.pop();
    if (topNode -> right != NULL)
      s.push(topNode -> right);
    if (topNode -> left != NULL)
      s.push(topNode -> left);
  }
  return preOrder;

}

//Iterative Solution  MORRIS PREORDER TRAVERSAL

class Solution {
public: 
    vector<int> preorderTraversal(TreeNode* root) {
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
                    ans.push_back(cur->val);
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};