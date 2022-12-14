// 994. Rotting Oranges
// Medium

// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 10
//     grid[i][j] is 0, 1, or 2.

//Code uses BFS: 
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if(grid.empty())
            return 0;
        
        int m=grid.size(), n=grid[0].size();
        int minutes=0, oranges=0, rotcount=0;
        queue<pair<int,int>> rotten;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2)
                    rotten.push({i,j});
                if(grid[i][j]!=0)
                    oranges++;
            }
        
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        
        while(!rotten.empty())
        {
            int k=rotten.size();
            rotcount+=k;
            while(k--)
            {
                int x=rotten.front().first;
                int y=rotten.front().second;
                rotten.pop();
                for(int i=0; i<4; i++)
                {
                    int rx=x+dx[i], ry=y+dy[i];
                    if(rx<0 or ry<0 or rx>=m or ry>=n or grid[rx][ry]!=1)
                        continue;
                    grid[rx][ry]=2;
                    rotten.push({rx,ry});
                }
            }
            if(!rotten.empty())
                minutes++;
        }
        return rotcount==oranges? minutes: -1;
    }
};