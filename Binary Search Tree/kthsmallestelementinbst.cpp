// 230. Kth Smallest Element in a BST
// Medium

// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of 
// the nodes in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Example 2:

// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3

// Constraints:

//     The number of nodes in the tree is n.
//     1 <= k <= n <= 104
//     0 <= Node.val <= 104

// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth 
// smallest frequently, how would you optimize?

//Recursive Solution:
class Solution {
public:
    void inorder(TreeNode* root, int &k, int &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left, k, ans);
        k--;
        if(k==0)
        {
            ans=root->val;    
            return;
        }
        inorder(root->right, k, ans);                   
    }
        
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        inorder(root, k, ans);
        return ans;
    }
};

//Iterative Solution: Morris Traversal O(1) Space Complexity
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=-1;
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->left==NULL)
            {
                k--;
                if(k==0)
                {
                    ans=cur->val;
                }
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
                    k--;
                    if(k==0)
                    {
                        ans=cur->val;
                    }
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};