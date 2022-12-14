// Problem Statement
// You are given a Binary Tree of integers. You are supposed to return the top view of the given binary tree. The Top view of
//  the binary tree is the set of nodes that are visible when we see the tree from the top.
// Example:

// For the given binary tree:

// The top view of the tree will be {10, 4, 2, 1, 3, 6}.

// Input Format:

// The first line contains an integer 'T' which denotes the number of test cases. 

// The first line of each test case contains elements of the tree in the level order form. The line consists of values of nodes
//  separated by a single space. In case a node is null, we take -1 in its place.

// Example:

// The input for the tree depicted in the below image would be:

// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

// Explanation :

// Level 1 :
// The root node of the tree is 1

// Level 2 :
// Left child of 1 = 2
// Right child of 1 = 3

// Level 3 :
// Left child of 2 = 4
// Right child of 2 = null (-1)
// Left child of 3 = 5
// Right child of 3 = 6

// Level 4 :
// Left child of 4 = null (-1)
// Right child of 4 = 7
// Left child of 5 = null (-1)
// Right child of 5 = null (-1)
// Left child of 6 = null (-1)
// Right child of 6 = null (-1)

// Level 5 :
// Left child of 7 = null (-1)
// Right child of 7 = null (-1)

// 1
// 2 3
// 4 -1 5 6
// -1 7 -1 -1 -1 -1
// -1 -1

// Note :

// 1. The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. 
// The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level 
// and so on.

// 2. The input ends when all nodes at the last level are null(-1).

// Output Format:

// For each test case, return the vector/list of all the elements of the top view of the given tree.

// Note :

// You don't need to print the output, it has already been taken care of. Just implement the given function.

// Constraints:

// 1 <= T <= 100
// 0 <= N <= 1000
// 0 <= data <= 10^6 and data != -1

// Where ???N??? is the total number of nodes in the binary tree, and 'data' is the value of the binary tree node.

// Time limit: 1 sec

// Sample Input 1:

// 2
// 1 2 3 4 5 6 7 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 3 -1 -1 -1 -1

// Sample Output 1:

// 8 4 2 1 3 7
// 2 1 3

// Explanation of Sample Output 1:

//  In test case 1, 

// From left to right, the top view of the tree will be {8,4,2,1,3,7}. Where 9,5 and 6 will be hidden when we see from the top 
// of the tree.

// In test case 2, from left to right, the top view of the tree will be {2,1,3} as there are only three nodes. There is nothing 
// to hide.

// Sample Input 2:

// 2
// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1
// 5 -1 -1

// Sample Output 2:

// 4 2 1 3 6
// 5

// Explanation of Sample Output 2:

//  In test case 1,  

// From left to right, the top view of the tree will be {4,2,1,3,6}. Where 7 and 5 will be hidden when we see from the top of 
// the tree.

// In test case 2, There is only one node and thus the top view of the tree will be {5}.

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<map>
#include<queue>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int> res;
    if(root==NULL)
        return res;
    map<int,int> mp;
    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        auto itr=q.front();
        TreeNode<int>* node=itr.first;
        int pos=itr.second;
        if(mp.find(pos)==mp.end()) //only difference between bottom view and top view.
            mp[pos]=node->val;
        
        q.pop();
        if(node->left!=NULL)
            q.push({node->left,pos-1});
        if(node->right!=NULL)
            q.push({node->right,pos+1}); 
    }
    
    for(auto it:mp)
        res.push_back(it.second);
    return res;
}