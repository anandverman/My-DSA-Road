// 200. Number of Islands
// Medium

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all 
// four edges of the grid are all surrounded by water.

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 300
//     grid[i][j] is '0' or '1'.

// Solution:DFS
class Solution {
public:
    void mark_island_DFS(vector<vector<char>> &grid, int x, int y, int &rows, int &cols)
    {
        if(x<0 or y<0 or x==rows or y==cols or grid[x][y]!='1')
            return;
        grid[x][y]='2';
        mark_island_DFS(grid, x+1, y, rows, cols);
        mark_island_DFS(grid, x-1, y, rows, cols);
        mark_island_DFS(grid, x, y-1, rows, cols);
        mark_island_DFS(grid, x, y+1, rows, cols);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0)
            return 0;
        int cols=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_island_DFS(grid, i, j, rows, cols);
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
};


// Solution:BFS
class Solution {
public:

    void mark_island_DFS(vector<vector<char>> &grid, int x, int y, int &rows, int &cols)
    {        
        queue<pair<int, int>> q;
        q.push({x,y});
        while(!q.empty())
        {
            x=q.front().first;
            y=q.front().second;
            q.pop();              
            if(x<0 or y<0 or x==rows or y==cols or grid[x][y]!='1')
                continue;
            else
            {
                grid[x][y]='2';
                q.push({x-1, y});
                q.push({x+1, y});
                q.push({x, y-1});
                q.push({x, y+1});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        if(rows==0)
            return 0;
        int cols=grid[0].size();
        int no_of_islands=0;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(grid[i][j]=='1')
                {
                    mark_island_DFS(grid, i, j, rows, cols);
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
};