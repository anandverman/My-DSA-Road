// 51. N-Queens
// Hard

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:

// Input: n = 1
// Output: [["Q"]]

//Solution 1: Recursion and Backtracking
// Time Complexity: Exponential in nature, since we are trying out all ways. To be precise it goes as O(N! * N) nearly.
// Space Complexity: O(N^2)
class Solution {
public:
    
    bool isvalid(vector<string> board, int row, int col, int n)
    {
        int r=row,c=col;
        while(r>=0 and c>=0)
        {
            if(board[r--][c--]=='Q')
                return false;
        }
        r=row;
        c=col;
        while(c>=0)
            if(board[r][c--]=='Q')
                return false;
        c=col;
        while(r<n and c>=0)
            if(board[r++][c--]=='Q')
                return false;
        return true;
    }

        
    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isvalid(board,row,col,n))
            {
                board[row][col]='Q';
                solve(board, ans, n,col+1);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string str(n,'.');
        vector<string> board (n,str);
        solve(board,ans,n,0);
        return ans;
    }
};

//Approach 2: Optimized Recursion and Backtracking using Hashing 
// Time Complexity: Exponential in nature since we are trying out all ways, to be precise it is O(N! * N).
// Space Complexity: O(N) Saves space by removing calls to isvalid function
class Solution {
public:
    
    // bool isvalid(vector<string> board, int row, int col, int n)
    // {
    //     int r=row,c=col;
    //     while(r>=0 and c>=0)
    //     {
    //         if(board[r--][c--]=='Q')
    //             return false;
    //     }
    //     r=row;
    //     c=col;
    //     while(c>=0)
    //         if(board[r][c--]=='Q')
    //             return false;
    //     c=col;
    //     while(r<n and c>=0)
    //         if(board[r++][c--]=='Q')
    //             return false;
    //     return true;
    // }

        
    void solve(vector<string> &board, vector<vector<string>> &ans, int n, int col, vector<int> ud, vector<int> ld, vector<int> lr)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(lr[row]==0 and ld[row+col]==0 and ud[n-1 +col-row]==0)
            {
                lr[row]=1;
                ld[row+col]=1;
                ud[n-1 +col-row]=1;
                board[row][col]='Q';
                solve(board, ans, n,col+1, ud, ld, lr);
                board[row][col]='.';
                lr[row]=0;
                ld[row+col]=0;
                ud[n-1 +col-row]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        string str(n,'.');
        vector<string> board (n,str);
        vector<int> upperdiag(2*n-1,0);
        vector<int> lowerdiag(2*n-1,0);
        vector<int> leftrow(n,0);
        solve(board,ans,n,0,upperdiag,lowerdiag,leftrow);
        return ans;
    }
};