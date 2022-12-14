// Problem Statement
// You have been given a Binary Tree of 'N' nodes, where the nodes have integer values. Your task is to find the ln-Order, 
// Pre-Order, and Post-Order traversals of the given binary tree.
// For example :

// For the given binary tree:

// The Inorder traversal will be [5, 3, 2, 1, 7, 4, 6].
// The Preorder traversal will be [1, 3, 5, 2, 4, 7, 6].
// The Postorder traversal will be [5, 2, 3, 7, 6, 4, 1].

// Input Format :

// The first line contains an integer 'T' which denotes the number of test cases. 

// The first line of each test case contains elements of the tree in the level order form. The line consists of values of 
// nodes separated by a single space. In case a node is null, we take -1 in its place.

// Example :

// The input for the tree is depicted in the below image: 

// 1 3 8 5 2 7 -1 -1 -1 -1 -1 -1 -1

// Explanation :

// Level 1 :
// The root node of the tree is 1

// Level 2 :
// Left child of 1 = 3
// Right child of 1 = 8

// Level 3 :
// Left child of 3 = 5
// Right child of 3 = 2
// Left child of 8 =7
// Right child of 8 =  null (-1)


// Level 4 :
// Left child of 5 = null (-1)
// Right child of 5 = null (-1)
// Left child of 2 = null (-1)
// Right child of 2 = null (-1)
// Left child of 7 = null (-1)
// Right child of 7 = null (-1)

// 1
// 3 8
// 5 2 7 -1
// -1 -1 -1 -1 -1 -1

// Note :

// 1. The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. 
// The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level 
// and so on.

// 2. The input ends when all nodes at the last level are null(-1).

// 3. The above format was just to provide clarity on how the input is formed for a given tree. The sequence will be put 
// together in a single line separated by a single space. Hence, for the above-depicted tree, the input will be given as:

// 1 3 8 5 2 7 -1 -1 -1 -1 -1 -1 -1

// Output Format :

// For each test case, return a vector/list of vector/list containing all three traversals (In-Order, Pre-Order, and Post-Order) 
// in each vector/list in the same order.

// The first line of output of each test case prints 'N' single space-separated integers denoting the node's values in In-Order 
// traversal.

// The second line of output of each test case prints 'N' single space-separated integers denoting the node's values in Pre-Order 
// traversal.

// The third and the last line of output of each test case prints 'N' single space-separated integers denoting the node's values 
// in Post-Order traversal.

// Note :

// You don't need to print anything, it has already been taken care of. Just implement the given function.

// Constraints :

// 1 <= T <= 100
// 0 <= N <= 3000
// 0 <= data <= 10^9   

// Where 'data' denotes the node value of the binary tree nodes.

// Time limit: 1 sec

// Sample Input 1 :

// 2
// 1 2 3 -1 -1 -1  6 -1 -1
// 1 2 3 -1 -1 -1 -1

// Sample Output 1 :

// 2 1 3 6 
// 1 2 3 6 
// 2 6 3 1
// 2 1 3 
// 1 2 3 
// 2 3 1

// Explanation of Sample Output 1 :

//  In test case 1, the given binary tree is shown below:

// Inorder traversal of given tree = [2, 1, 3, 6]
// Preorder traversal of given tree = [1, 2, 3, 6]
// Postorder traversal of given tree = [2, 6, 3, 1]

//  In test case 2, the given binary tree is shown below:

// Inorder traversal of given tree = [2, 1, 3]
// Preorder traversal of given tree = [1, 2, 3]
// Postorder traversal of given tree = [2, 3, 1]

// Sample Input 2 :

// 2
// 1 -1 -1
// 1 2 4 5 3 -1 -1 -1 -1 -1 -1

// Sample Output 2 :

// 1
// 1
// 1
// 5 2 3 1 4 
// 1 2 5 3 4 
// 5 3 2 4 1

// Explanation of Sample Output 2 :

// In test case 1, there is only one node and so all the three traversals will be the same having only one node.

// In test case 2, the given binary tree is shown below:

// Inorder traversal of given tree = [5, 2, 3, 1, 4]
// Preorder traversal of given tree = [1, 2, 5, 3, 4]
// Postorder traversal of given tree = [5, 3, 2, 4, 1]

//SOLUTION:
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void inorder(vector<int> &ans, BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return;
    inorder(ans,root->left);
    ans.push_back(root->data);
    inorder(ans,root->right);
}
void preorder(vector<int> &ans, BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return;
    ans.push_back(root->data);
    preorder(ans,root->left);    
    preorder(ans,root->right);
}
void postorder(vector<int> &ans, BinaryTreeNode<int> *root)
{
    if(root==NULL)
        return;
    postorder(ans,root->left);    
    postorder(ans,root->right);
    ans.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> res;
    vector<int> ans;
    inorder(ans,root);
    res.push_back(ans);
    ans.clear();
    preorder(ans,root);
    res.push_back(ans);
    ans.clear();
    postorder(ans,root);
    res.push_back(ans);
    return res;
}