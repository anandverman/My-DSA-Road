// 173. Binary Search Tree Iterator
// Medium

// Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

//     BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of 
//     the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
//     boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise 
//     returns false.
//     int next() Moves the pointer to the right, then returns the number at the pointer.

// Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the 
// smallest element in the BST.

// You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order 
// traversal when next() is called.

 

// Example 1:

// Input
// ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
// Output
// [null, 3, 7, true, 9, true, 15, true, 20, false]

// Explanation
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();    // return 3
// bSTIterator.next();    // return 7
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 9
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 15
// bSTIterator.hasNext(); // return True
// bSTIterator.next();    // return 20
// bSTIterator.hasNext(); // return False

// Constraints:

//     The number of nodes in the tree is in the range [1, 105].
//     0 <= Node.val <= 106
//     At most 105 calls will be made to hasNext, and next.

// Follow up:

//     Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of 
//     the tree?



// Optimal Approach:
// Time Complexity:    O(1) Amortized/Average
// Space Complexity:   O(H)

class BSTIterator {
public:
    stack<TreeNode*> st;
    void push(TreeNode* root)
    {
        while(root)
        {
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        if(st.empty())
            return -1;
        TreeNode* node=st.top();
        st.pop();
        push(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

//Alternate Version of above approach:
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* iter;
    
    BSTIterator(TreeNode* root) {
        iter=root;
    }
    
    int next() 
    {
        while(iter)    
        {
            st.push(iter);
            iter=iter->left;
        }
        iter=st.top();
        st.pop();
        int res=iter->val;
        iter=iter->right;
        return res;
    }
    
    bool hasNext() {
        return iter or !st.empty();
    }
};

//Optimized Naive Approach: Saving Inorder in stack
// Time Complexity:    O(1) for operations, O(N) for constructor
// Space Complexity:   O(N) for stack size and recursion
class BSTIterator {
public:
    stack<int> st;
    void reverseinorder(TreeNode* root, stack<int> &st)
    {
        if(root==NULL)
            return;
        reverseinorder(root->right, st);
        st.push(root->val);
        reverseinorder(root->left, st);
    }
    BSTIterator(TreeNode* root) {
        reverseinorder(root, st);
    }
    
    int next() {
        int res=-1;
        if(!st.empty())
        {
            res=st.top();
            st.pop();
        }
        return res;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

//Naive Approach: Using Successor
// Time Complexity:    O(log2(N))<=O(H)<=O(N) for inorder successor search.
// Space Complexity:   O(1)

class BSTIterator {
public:
    TreeNode* bstroot;
    int curr;
    BSTIterator(TreeNode* root) {
        bstroot=root;
        curr=-1;
    }
    
    int next() {
        TreeNode* root=bstroot;
        int succ=-1;        
        while(root!=NULL)
        {
            if(root->val<=curr)      //Successor Code has <= instead of <
                root=root->right;
            else
            {
                succ=root->val;
                root=root->left;
            }
        }
        curr=succ;
        return succ;
    }
    
    bool hasNext() {
        TreeNode* root=bstroot;
        int succ=-1 ;       
        while(root!=NULL)
        {
            if(root->val<=curr)      //Successor Code has <= instead of <
                root=root->right;
            else
            {
                succ=root->val;
                root=root->left;
            }
        }
        if(succ<0)
            return false;
        return true;
    }
};
