// 62. Unique Paths
// Medium

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:

// Input: m = 3, n = 7
// Output: 28

// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

 

// Constraints:

//     1 <= m, n <= 100

//Approach 1: Recursion and Backtracking (cause TLE for Large grids) Time and Space Complexity are Exponential
class Solution {
public:
    int backtrack(int i, int j, int m, int n)
    {
        if(i==m or j==n)
            return 0;
        if(i==m-1 and j==n-1)
            return 1;
        int ans=0;
        ans+=backtrack(i+1,j,m,n);
        ans+=backtrack(i,j+1,m,n);
        return ans;
    }
    int uniquePaths(int m, int n) 
    {
        return backtrack(0,0,m,n);
    }
};

//Approach 2: Dynamic Programming with Recursion and Backtracking
class Solution {
public:
    int backtrack(int i, int j, int m, int n,vector<vector<int>> &dp)
    {
        if(i==m or j==n)
            return 0;
        if(i==m-1 and j==n-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=backtrack(i+1,j,m,n,dp)+backtrack(i,j+1,m,n,dp);        
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return backtrack(0,0,m,n,dp);
    }
};

//Approach 3: Using Combinatorial Logic
// Solution 3: Combinatorics Solution

// Intuition: If we observe examples there is a similarity in paths from start to end. Each time we are taking an exactly m+n-2 number of steps to reach the end.

// From start to reach the end we need a certain number of rightward directions and a certain number of downward directions. So we can figure out we need n-1 no. of rightward direction and m-1 no. of downward direction to reach the endpoint.

// Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

// Approach: The approach of this solution is very simple just use a for loop to calculate the m+n-2Cn-1  or m+n-2Cm-1 

// Dry Run: We’ll take the input m = 2 and n = 3 

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n - 2;
        int r=( m<n ? m-1 : n-1);
        double res=1;
        for(int i=1 ; i<=r ; i++)
            res =res* (N-r+i) / i;
        return (int)res;
    }
};