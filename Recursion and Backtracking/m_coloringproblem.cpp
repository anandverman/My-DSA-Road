// Problem Statement
// You are given an undirected graph in the form of an adjacency matrix along with an integer M. You need to tell if you can 
// color the vertices of the graph using at most M colors such that no two adjacent vertices are of the same color.
// For example:

// If the given adjacency matrix is:
// [0 1 0]
// [1 0 1]
// [0 1 0] and M = 3.
// The given adjacency matrix tells us that 1 is connected to 2 and 2 is connected to 3. So if we color vertex 1 with 2, 
// vertex 2 with 1, and vertex 3 with 2, it is possible to color the given graph with 2 colors: M.

// Input Format:

// The first line of input contains a single integer T, representing the number of test cases or queries to be run. 
// Then the T test cases follow.
// The first line of the test case contains two space-separated integers V and M, denoting the number of vertices in 
// the undirected graph and the number of colors respectively. 
// Each of the next V lines contains V integers denoting the adjacency matrix of the undirected graph.

// Output Format:
// For each test case, you need to return “YES” if we can color the given graph with at most M colors. 
// Otherwise, return “NO”. (without the inverted commas)

// Note:

// You are not required to print the expected output, it has already been taken care of. Just implement the function.

// Constraints:

// 1 ≤ T ≤ 1000
// 1 ≤ V ≤ 20
// 1 ≤ M ≤ V

// Time Limit : 1 sec 

// Sample Input 1:

// 3
// 3 3
// 0 1 0
// 1 0 1
// 0 1 0
// 3 1
// 0 1 0
// 1 0 1
// 0 1 0
// 2 1
// 0 1
// 1 0

// Sample Output 1:

// YES
// NO
// NO

// Explanation of Input 1:

// The first test case has already been explained in the example.
// In the second test case, the given adjacency matrix tells us that 1 is connected to 2 and 2 is connected to 3. 
// We can see that minimum of 2 colors would be needed to color the graph. So it is not possible to color the graph in this case.

// The third test case, the given adjacency matrix tells us that 1 is connected to 2. We can see that minimum 2 
// colors would be needed to color the graph. So it is not possible to color the graph in this case.

// Sample Input 2:

// 3
// 3 3
// 0 0 0
// 0 0 1
// 0 1 0
// 4 2
// 0 1 0 0
// 1 0 0 0
// 0 0 0 1
// 0 0 1 0
// 4 1
// 0 1 0 0
// 1 0 0 0
// 0 0 0 1
// 0 0 1 0

// Sample Output 2

// YES
// YES
// NO

bool cancolor(vector<vector<int>> &mat,int ptr,int color, vector<int> col_arr)
{
    for( int i=0; i<ptr ;i++)
        if(mat[ptr][i]== 1 and col_arr[i]==color)
            return false;
    return true;        
}

bool colorable(vector<vector<int>> &mat, int ptr, int m, vector<int> &col_arr)
{
    if(ptr == mat.size())
        return true;
    
    for(int i=1; i<=m; i++)//i are different colors
    {
        if(cancolor(mat,ptr,i,col_arr))
        {
            col_arr[ptr]=i;
            if(colorable(mat,ptr+1,m,col_arr))
                return true;
            col_arr[ptr]=0;
        }       
    }    
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) 
{
    int n=mat.size();
    vector<int> col_arr(n,0);
    if(colorable(mat,0,m,col_arr))
        return "YES";
    else 
        return "NO";
}