Problem Statement
You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). 
You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

Input Format :

The first line of input contains an integer T, the number of test cases.

The first line of each test case contains an integer that denotes the value of K.

The next 2*K lines of each test case follow: 
The first line contains an integer ‘N’ denoting the size of the array. 

The second line contains N space-separated integers. 

Output Format :

The first and only line of output contains space-separated elements of the merged and sorted array, as described in the task.

Note :

You don’t have to print anything; it has already been taken care of. Just implement the function. 

Constraints :

1 <= T <= 5
1 <= K <= 5
1 <= N <= 20
-10^5 <= DATA <= 10^5

Time Limit: 1 sec 

Sample Input 1:

1
2
3 
3 5 9 
4 
1 2 3 8   

Sample Output 1:

1 2 3 3 5 8 9 

Explanation of Sample Input 1:

After merging the two given arrays/lists [3, 5, 9] and [ 1, 2, 3, 8], the output sorted array will be [1, 2, 3, 3, 5, 8, 9].

Sample Input 2:

1
4
3
1 5 9
2
45 90
5
2 6 78 100 234
1
0

Sample Output 2:

0 1 2 5 6 9 45 78 90 100 234

Explanation of Sample Input 2 :

After merging the given arrays/lists [1, 5, 9], [45, 90], [2, 6, 78, 100, 234] and [0], the output sorted array will 
be [0, 1, 2, 5, 6, 9, 45, 78, 90, 100, 234].

#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> que(arr[0].begin(),arr[0].end());
    for(int i=1;i<k;i++)
    {
        for(int j=0;j<arr[i].size();j++)
            que.push(arr[i][j]);
    }
    while(!que.empty())
    {
        ans.push_back(que.top());
        que.pop();
    }
    return ans;
}
