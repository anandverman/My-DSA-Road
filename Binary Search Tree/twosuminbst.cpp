// 653. Two Sum IV - Input is a BST
// Easy

// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such 
// that their sum is equal to the given target.

// Example 1:

// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Example 2:

// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

// Constraints:

//     The number of nodes in the tree is in the range [1, 104].
//     -104 <= Node.val <= 104
//     root is guaranteed to be a valid binary search tree.
//     -105 <= k <= 105

//Naive Solution: Save inorder values in array and find sum using two pointers (as used in two sum in Arrays)
// Time Complexity:    O(N)
// Space Complexity:   O(N)
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &arr)
    {
        if(root==NULL)
        {
            return;

        }
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);

    }
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> arr;
        inorder(root,arr);
        int i=0, j=arr.size()-1;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum==k)
            {
                return true;
            }
            else if(sum>k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return false;
        
    }
};

//Optimal Solution:  Using two BST Iterators (forward and backward)- Iterators give inorder values from left and right.
// Time Complexity:    O(1) Amortized/Average
// Space Complexity:   2* O(H)==O(H) for iterator stacks

class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse;
    
    BSTIterator(TreeNode* root, bool isrev)
    {
        reverse=isrev;
        push(root);
    }
    
    void push(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            if(reverse)
                root=root->right;            
            else                   
                root=root->left;
        }
    }
    
    int next() 
    {
        TreeNode* node=st.top();
        st.pop();
        if(reverse)
            push(node->left);
        else
            push(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i=l.next();
        int j=r.next();
        while(i<j)
        {
            if(i+j==k)
                return true;
            else if(i+j<k)
            {
                i=l.next();
            }
            else
            {
                j=r.next();
            }
        }
        return false;
    }    
};

// My Solution: For each node i in bst search another node
// Time Complexity:    O(H*N) atworst when there is no node with 
// Space Complexity:   O(1)
class Solution {
public:
    bool result=false;
    TreeNode*root2, *other;
    bool search(TreeNode* root, int k)
    {
        while(root!=NULL)
        {
            if(root->val==k and root!=other)
                return true;
            if(root->val>k)
                root=root->left;
            else
                root=root->right;
        }
        return result;
    }    
    void preorder(TreeNode* root, int k)
    {
        if(root==NULL)
            return;
        other=root;
        result=search(root2, k-root->val);
        if(result==true)
            return;
        preorder(root->left, k);
        preorder(root->right, k);

    }
    bool findTarget(TreeNode* root, int k) {
        root2=root;
        preorder(root, k);
        return result;
    }
};