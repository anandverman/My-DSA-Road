// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Example 1:

// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}

// Result: 5

// Explanation: The following subarrays sum to zero:
// {-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
// Since we require the length of the longest subarray, our answer is 5!

// Example 2:

// Input Format: N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}

// Result: 8

// Subarrays with sum 0 : {-2, 2}, {-8, 1, 7}, {-2, 2, -8, 1, 7}, {6, -2, 2, -8, 1, 7, 4, -10}
// Length of longest subarray = 8

// Example 3:

// Input Format: N = 3, array[] = {1, 0, -5}

// Result: 1

// Subarray : {0}
// Length of longest subarray = 1

// Example 4:

// Input Format: N = 5, array[] = {1, 3, -5, 6, -2}

// Result: 0

// Subarray: There is no subarray that sums to zero

//Approach 1 Brute Force
#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    int n=arr.size(),count=0,sum;
    for(int i=0;i<n-1;i++)
    {
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum==0)
                count=max(count,j+1-i);
        }
    }
    return count;
}

//Approach 2 Use unordered map of prefix sums
#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) 
{
    int n=arr.size(),sum=0,ans=0;
    unordered_map<int,int> pre;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            ans=i+1;
        else
        {
            if(pre.find(sum)!=pre.end())
                ans=max(ans,i-pre[sum]);
            else
                pre[sum]=i;
        }
    }
    return ans;
}