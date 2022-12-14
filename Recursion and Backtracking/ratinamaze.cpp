// Problem Statement
// You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths that rat can follow 
// to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move in any direc­tion ( left, right, up and down).
// Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means the rat can­not enter 
// into those cells and those with value 1 are open.

// Input Format:

// The first line of input contains an integer 'N' representing the dimension of the maze.
// The next 'N' lines of input contain 'N' space-separated integers representing the type of the cell.

// Output Format :

// For each test case, return the path from the start position to the destination position and only cells 
// that are part of the solution path should be 1, rest all cells should be 0.
// Output for every test case will be printed in a separate line.

// Note:

// You do not need to print anything, it has already been taken care of. Just implement the given function.

// Constraints:

// 1 <= N <= 10
// 0 <= MAZE[i][j] <=1

// Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

// Time Limit: 1 sec

// Sample Input 1 :

// 3
// 1 0 1
// 1 0 1
// 1 1 1

// Sample Output 1 :
// 1 0 0 1 0 0 1 1 1 

// Explanation for Sample Output 1:
// Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3) >
// So our path matrix will look like this:

// 1 0 0
// 1 0 0
// 1 1 1

// Which is returned from left to right and then top to bottom in one line.

// Sample Input 2 :
// 2
// 1 0
// 0 1

// Sample Output 2 :
//  [Blank]

// Explanation for Sample Output 2:
// As no path is possible to the last cell, a blank vector will be returned and nothing is printed.

// Solution mera, dimag ghis gaya debug karne me
bool canmove(int x,int y, vector<vector<int>> &maze, int n)
{
    if(x<0 or y<0 or x==n or y==n)
        return false;
    return maze[x][y];
}

void findpath(int n, vector<vector<int>> &maze, vector<vector<int>> &res, int i, int j, vector<int> subres)
{
    if(i==n-1 and j==n-1)
    {
        res.push_back(subres);
        return;
    }
    if(canmove(i, j+1, maze, n)) //move down 
    {
        subres[n*i+j+1]=1;
        maze[i][j]=0;
        (findpath(n,maze,res,i,j+1,subres));
        maze[i][j]=1;
        subres[n*i+j+1]=0;
    }
    if(canmove(i+1, j, maze, n)) //move right
    {
        subres[n*(i+1)+j]=1;
        maze[i][j]=0;
        (findpath(n,maze,res,i+1,j,subres));
        maze[i][j]=1;
        subres[n*(i+1)+j]=0;
    }
    if(canmove(i-1, j, maze, n)) //move left
    {
        subres[n*(i-1)+j]=1;
        maze[i][j]=0;
        (findpath(n,maze,res,i-1,j,subres));
        maze[i][j]=1;
        subres[n*(i-1)+j]=0;
    }
    if(canmove(i, j-1, maze, n)) //move up
    {
        subres[n*i+j-1]=1;
        maze[i][j]=0;
        (findpath(n,maze,res,i,j-1,subres));
        maze[i][j]=1;
        subres[n*i+j-1]=0;
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int>> &maze, int n){
    vector<vector<int>> result;
    vector<int> subres(n*n,0);
    subres[0]=maze[0][0];
    findpath(n,maze,result,0,0,subres);
    return result;
}