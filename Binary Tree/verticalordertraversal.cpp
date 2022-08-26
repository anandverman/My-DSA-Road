// Problem Statement
// Given a binary tree, return the vertical order traversal of the values of the nodes of the given tree.
// For each node at position (X, Y), (X-1, Y-1) will be its left child position while (X+1, Y-1) will be the right child position.
// Running a vertical line from X = -infinity to X = +infinity, now whenever this vertical line touches some nodes, we need to add
// those values of the nodes in order starting from top to bottom with the decreasing ‘Y’ coordinates.
// Note:

// If two nodes have the same position, then the value of the node that is added first will be the value that is on the left side.

// For example:

// For the binary tree in the image below.

// The vertical order traversal will be {2, 7, 5, 2, 6, 5, 11, 4, 9}.

// Input Format:

// The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases are 
// as follows.

// The only line of each test case contains elements in the level order form. The line consists of values of nodes separated by 
// a single space. In case a node is null, we take -1 in its place. So -1 would not be a part of the tree nodes.

// For example, the input for the tree depicted in the below image will be:

// For example taking a tree:

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

// The first not-null node(of the previous level) is treated as the parent of the first two nodes of the current level. The 
// second not-null node (of the previous level) is treated as the parent node for the next two nodes of the current level and 
// so on.

// The input ends when all nodes at the last level are null(-1).

// Note :

// The above format was just to provide clarity on how the input is formed for a given tree. 
// The sequence will be put together in a single line separated by a single space. Hence, for the above-depicted tree, the 
// input will be given as:

// 1 2 3 4 -1 5 6 -1 7 -1 -1 -1 -1 -1 -1

// Output Format:

// For each test case, print the vertical order traversal of the given binary tree separated by single spaces.

// Print the output of each test case in a separate line.

// Note:

// You do not need to print anything, it has already been taken care of. Just implement the given function.

// Constraints:

// 1 <= 'T' <= 100
// 0 <= 'N' <= 3000
// 0 <= 'VAL' <= 10^5

// Where 'VAL' is the value of any binary tree node.

// Time Limit: 1 sec

// Sample Input 1:

// 2
// 1 2 3 4 -1 -1 -1 -1 -1
// 1 -1 2 -1 -1

// Sample Output 1:

// 4 2 1 3 
// 1 2 

// Explanation of Sample Input 1:

// For the first test case, the vertical order traversal of the given binary tree will be {{4}, {2}, {1}, {3}}.

// For the second test case, the vertical order traversal of the given binary tree will be {{1}, {2}}.

// Sample Input 2:

// 2
// 2 1 -1 -1 -1
// 0 1 2 4 5 3 6 -1 -1 7 -1 -1 -1 -1 -1 -1 -1

// Sample Output 2:

// 1 2
// 4 1 7 0 5 3 2 6 

// Explanation of Sample Input 2:

// For the first test case, the vertical order traversal of the given binary tree will be {{1}, {2}}.

// For the second test case, the vertical order traversal of the given binary tree will be {{4}, {1, 7}, {0, 5, 3}, {2}, {6}}.

//Solution with Level Order Traversal and Data Structure for storing position and data.
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<map>
#include<queue>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    map <int, map<int,queue<int>>> mp; //map for storing values mapped at coordinates (x,y) <x,y,queue of values at (x,y)>
                                       // used queue so that order of insertion of values is maintained.

    queue<pair<TreeNode<int>*, pair<int,int>>> q;// queue for storing nodes and their coordinates for level order traversal.
    q.push({root,{0,0}});
    while(!q.empty())
    {
        auto element=q.front();
        TreeNode<int>* node=element.first;
        int x=element.second.first, y=element.second.second;
        mp[x][y].push(node->data);
        q.pop();
        if(node->left!=NULL)
            q.push({node->left,{x-1,y+1}});
        
        if(node->right!=NULL)
            q.push({node->right,{x+1,y+1}});
    }
    vector<int> ans;
    for(auto i:mp)
    {
        for(auto j:i.second)
        {
            while(!j.second.empty())
            {
                ans.push_back(j.second.front());
                j.second.pop();
            }
        }
    }
    return ans;
}

