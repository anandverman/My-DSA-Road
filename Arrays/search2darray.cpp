/*
74. Search a 2D Matrix
Medium

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104

*/

//My approach: find row then binary search in row
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        
        int row=-1,col=matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++)
        {
            if(target<=matrix[i][col])
            {
                if(target==matrix[i][col])
                {
                    return true;
                }
                row=i;
                break;
            }
            
        }
        
        if(row==-1)
            return false;
                
        int left =0, right =col, mid;
        while(right>=left)
        {
            mid =(left + right)/2;
            if(matrix[row][mid]==target)
            {
                return true;                
            }
            if(matrix[row][mid]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }
};

//Striver Approach: do binary search on complete 2d arr as 1d array
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size(), m=matrix[0].size();
        int left =0, right =m*n-1, mid;
        while(right>=left)
        {
            mid =(left + right)/2;
            if(matrix[mid/m][mid%m]==target)
            {
                return true;                
            }
            if(matrix[mid/m][mid%m]>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }
};