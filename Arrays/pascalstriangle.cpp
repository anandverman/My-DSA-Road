// 18. Pascal's Triangle
// Easy

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]

 

// Constraints:

//     1 <= numRows <= 30



class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> triangle(numRows);
        if (numRows>0)
            triangle[0]={1};
        if (numRows>1)
            triangle[1]={1,1};
        if (numRows>2)
        {
            for(int i=2;i<numRows;i++)
            {
                triangle[i].push_back(1);
                for(int j=1;j<i;j++)
                    triangle[i].push_back(triangle[i-1][j]+triangle[i-1][j-1]);
                triangle[i].push_back(1);
            }    
        }
        return triangle;
    }
};