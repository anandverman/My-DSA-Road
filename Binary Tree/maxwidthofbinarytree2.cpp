// Problem Statement
// You have been given a Binary Tree of integers. You are supposed to return the maximum width of the given Binary Tree. 
// The maximum width of the tree is the maximum width among all the levels of the given tree.
// The width of one level is defined as the length between the leftmost and the rightmost, non-null nodes in the level, 
// where the null nodes in between the leftmost and rightmost are excluded into length calculation.
// For example :

// For the given binary tree

// The maximum width will be at the third level with the length of 3, i.e. {4, 5, 6}.

// Input Format :

// The only line of input contains elements in the level order form. The line consists of values of nodes separated by a 
// single space. In case a node is null, we take -1 in its place.

// For example, the input for the tree depicted in the below image would be :

// 1
// 2 3
// 4 -1 5 6
// -1 7 -1 -1 -1 -1
// -1 -1

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

// The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. 
// The second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current 
// level and so on.
// The input ends when all nodes at the last level are null(-1).

// Note :

// The above format was just to provide clarity on how the input is formed for a given tree. 
// The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, 
// the input will be given as:

// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

// Output Format :

// For each input, print a single line that contains a single integer that denotes the maximum width for the given tree.

// Note :

// You do not need to print anything; it has already been taken care of. Just implement the given function.

// Constraints :

// 0 <= 'N' <= 5 * 10 ^ 5
// 0 <= 'DATA' <= 10 ^ 6 and data != -1
// Where ???N??? is the total number of nodes in the binary tree, and 'DATA' is the value of the binary tree node.

// Time Limit: 1sec.

// Sample Input 1 :

// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

// Sample Output 1 :

// 3

// Explanation of Sample Input 1 :

// The maximum width will be at the third level with the length of 3, i.e. {4, 5, 6}.

// Sample Input 2 :

// 2 7 5 2 6 -1 9 -1 -1 5 11 4 -1 -1 -1 -1 -1 -1 -1

// Sample Output 2 :

// 3

// Explanation of Sample Input 2 :

// The maximum width will be at the third level i.e. {2, 6, 9} and the fourth level with the length of 3, i.e. {5, 11, 4}. 
// So the maximum width will be 3.



/************************************************************

    Following is the TreeNode class structure

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

//Solution: Space Complexity = O(n), Time Complexity = O(n)

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
        return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int count=1;
    while(!q.empty())
    {
        int size=q.size();
        count=max(count,size);
        while(size--)
        {
            TreeNode<int> *node=q.front();
            q.pop();
            if(node->left!=NULL)
                q.push(node->left);
            if(node->right!=NULL)
                q.push(node->right);           
        }       
    }
    return count;
}