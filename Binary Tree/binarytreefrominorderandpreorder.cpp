// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Medium

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder 
// is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:

// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]

 

// Constraints:

//     1 <= preorder.length <= 3000
//     inorder.length == preorder.length
//     -3000 <= preorder[i], inorder[i] <= 3000
//     preorder and inorder consist of unique values.
//     Each value of inorder also appears in preorder.
//     preorder is guaranteed to be the preorder traversal of the tree.
//     inorder is guaranteed to be the inorder traversal of the tree.

class Solution {
public:
    TreeNode* construct(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &inmap)
    {
        if(preStart>preEnd or inStart>inEnd)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inroot= inmap[root->val];  //root of index in inorder array.
        int inleft=inroot-inStart;  //no of elements in left of root in inorder array.
        
        root->left=construct(preorder, preStart+1, preStart+inleft, inorder, inStart, inroot-1, inmap);
        root->right=construct(preorder, preStart+1+inleft, preEnd, inorder, inroot+1, inEnd, inmap);
        return root;
    }
        
        
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map <int,int> inmap;
        for(int i=0; i<inorder.size(); i++)
            inmap[inorder[i]]=i;        //map inorder elements by index.
        TreeNode* root=construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inmap);
        return root;
    }
};