// Problem Statement
// You have been given a matrix of ‘N’ rows and ‘M’ columns filled up with integers where every row is sorted 
// in non-decreasing order. Your task is to find the overall median of the matrix i.e if all elements of the 
// matrix are written in a single line, then you need to return the median of that linear array.

// The median of a finite list of numbers is the "middle" number when those numbers are listed in order from 
// smallest to greatest. If there is an odd number of observations, the middle one is picked. For example, 
// consider the list of numbers [1, 3, 3, 6, 7, 8, 9]. This list contains seven numbers. The median is the 
// fourth of them, which is 6.

// Input Format:

// The first line contains a single integer ‘T’ representing the number of test cases. 

// The first line of each test case will contain two integers ‘N’ and ‘M’ denoting the number of rows and columns, respectively.

// Next ‘N’ lines contain ‘M’ space-separated integers each denoting the elements in the matrix.

// Output Format:

// For each test case, print an integer which is the overall median of the given matrix.

// Output for every test case will be printed in a separate line.

// Note:

// You don’t need to print anything; It has already been taken care of. Just implement the given function.

// Constraints:

// 1 <= 'T' <= 50
// 1 <= 'N' , 'M' <= 100
// 1 <= 'MATRIX'['I']['J'] <= 10 ^ 5
// 'N' * 'M' is always an odd number.

// Where 'MATRIX'['I']['J']  denotes the value at ('I', 'J')th cell in the matrix.

// Time limit: 1 sec

// Sample Input 1:

// 2
// 1 3
// 1 2 3
// 3 3
// 2 6 9
// 1 5 11
// 3 7 8

// Sample Output 1:

// 2
// 6

// Explanation of sample input 1:

// In the first test case, the overall median of the matrix is 2.

// In the second test case, the overall median of the matrix is 6.

// Sample Input 2:

// 2
// 3 3
// 2 6 8
// 1 4 7
// 6 8 9
// 3 5
// 1 2 6 6 10
// 2 4 4 5 7
// 2 5 5 6 6

// Sample Output 2:

// 2
// 5

// Explanation for sample input 2:

// In the first test case, the overall median of the matrix is 2.

// In the second test case, the overall median of the matrix is 5.


//Approach 1: Naive Approach: Put matrix in linear data structure, sort the data structure and return middle element.
//Approach: Binary Search: https://youtu.be/63fPPOdIr2c

int countlessthanorequaltomid(vector<int> &row, int mid)
{
    int lo=0,hi=row.size()-1;
    while(lo<=hi)
    {
        int md=((hi-lo)>>1)+lo;
        if(row[md]<=mid)
            lo=md+1;
        else
            hi=md-1;
    }
    return lo;
}

int getMedian(vector<vector<int>> &matrix)
{
    int low=1, high=1e5;
    int n=matrix.size();
    int m=matrix[0].size();
    while(low<=high)
    {
        int mid=((high-low)>>1)+low;
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+= countlessthanorequaltomid(matrix[i],mid);
        }
        if(count<= (n*m)/2)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}