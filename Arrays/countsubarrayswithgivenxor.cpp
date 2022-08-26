// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to B.

// Examples:

// Input Format:  A = [4, 2, 2, 6, 4] , B = 6
// Result: 4
// Explanation: The subarrays having XOR of their elements as 6 are  [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]

// Input Format: A = [5, 6, 7, 8, 9], B = 5
// Result: 2
// Explanation:The subarrays having XOR of their elements as 2 are [5] and [5, 6, 7, 8, 9]

//Approach 1: Brute Force xor of all subarrays and match
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size(),xord,count=0;
    for(int i=0;i<n;i++)
    {
        xord=0;
        for(int j=i;j<n;j++)
        {
            xord =xord xor arr[j];
            if(xord==x)
                count++;
        }
    }
    return count;
}

//Approach 2: Prefix XOR and map 
#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n=arr.size(),xors=0,count=0;
    unordered_map<int,int> pre;
    for(int i=0;i<n;i++)
    {
        xors ^=arr[i];
        if(xors==x)
            count++;
        int h =xors xor x;
        if(pre.find(h)!=pre.end())
        {
            count+=pre[h];
        }
        pre[xors]++;
    }
    return count;
}