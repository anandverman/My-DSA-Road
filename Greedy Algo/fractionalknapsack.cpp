// Problem Statement
// You have been given weights and values of ‘N’ items. You are also given a knapsack of size ‘W’.
// Your task is to put the items in the knapsack such that the total value of items in the knapsack is maximum.
// Note:

// You are allowed to break the items.

// Example:

// If 'N = 4' and 'W = 10'. The weights and values of items are weights = [6, 1, 5, 3] and values = [3, 6, 1, 4]. 
// Then the best way to fill the knapsack is to choose items with weight 6, 1 and  3. 
// The total value of knapsack = 3 + 6 + 4 = 13.00   

// Input Format:

// The first line contains an integer ‘T’ denoting the number of test cases. Then each test case follows.
// The first line of each test case contains two single space-separated integers ‘N’ and ‘W’, respectively.
// The second line of each test case contains ‘N’ single space-separated integers representing the weight of the i-th item.
// The third line of each test case contains ‘N’ single space-separated integers representing the value of the i-th item.

// Output Format:

// For each test case, the only line of output will print the maximum total value of items in the knapsack.  
// The output must be rounded correctly up to two decimal places.
// Print the output of each test case in a separate line.

// Note: You are not required to print the expected output; it has already been taken care of. Just implement the function.

// Constraints:

// 1 <= T <= 100
// 1 <= N <= 5000
// 1 <= W <= 10^5
// 1 <= weights[i] <= 10^5
// 1 <= values[i] <= 10^5

// Time limit: 1 sec

// Sample Input 1:

// 1
// 6 200
// 50 40 90 120 10 200 
// 40 50 25 100 30 45

// Sample output 1:

// 204.00

// Explanation of Sample output 1:

// The most optimal way to fill the knapsack is to choose full items with weight 10 and value 30, 
// weight 40 and value 50, weight 120 and value 100. Then take weight 30 from the item with weight 50 and value 40.

// The total value =  30 + 50 + 100 + (30/50)*(40) = 204.00

// Sample Input 2:

// 1
// 5 100
// 20 24 36 40 42
// 12 35 41 25 32

// Sample output 2:

// 106.48

// My Solution for Fractional Knapsack
#include<algorithm>
struct item
{
    int wt,val;
    double valperwt;
};
bool sortcompare(item i1,item i2)
{
    if(i1.valperwt>i2.valperwt)
        return true;
    return false;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    item itm[n];
    double profit=0;
    for(int i=0;i<n;i++)
    {
        itm[i].wt=items[i].first;
        itm[i].val=items[i].second;
        itm[i].valperwt=(double)itm[i].val/itm[i].wt;
    }
    sort(itm,itm+n,sortcompare);
    for(int i=0;i<n;i++)
    {
        if(w==0)
            break;
        if(itm[i].wt<=w)
        {
            profit+=itm[i].val;
            w-=itm[i].wt;
        }
        else if(itm[i].wt>w and w!=0)
        {
            profit+=itm[i].valperwt*w;
            w=0;
        }
    }
    return profit;
}