// 300. Longest Increasing Subsequence
// Medium

// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of 
// the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

// Constraints:

//     1 <= nums.length <= 2500
//     -104 <= nums[i] <= 104

//Most Optimized Solution:
// TC:O(n), SC:O(n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seq;
        seq.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>seq.back())
                seq.push_back(nums[i]);
            else
            {
                int index=lower_bound(seq.begin(), seq.end(), nums[i]) -seq.begin();
                seq[index]=nums[i];
            }
        }
        return seq.size();
    }
};

//2nd Most Optimized Solution:
// TC:O(n*n), SC:O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int> len(n,1);
        for(int i=0; i<n; i++)
        {
            for(int j=i; j>=0; j--)
            {
                if(nums[i]>nums[j])
                    len[i]=max(len[i],len[j]+1);
                ans=max(ans,len[i]);
            }
        }
        return ans;
    }
};

//Lesser Optimized Solutions:
#include<vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n+1, 0), cur(n+1, 0);
    for(int index= n-1; index>=0; index--)
    {
        for(int previndex=index-1; previndex>=-1; previndex--)
        {
            int len=0+ next[previndex+1];
    
            if(previndex ==-1 or arr[index]>arr[previndex])
            {
                len=max(len , 1+ next[index+1]);
            }
            cur[previndex+1] =len;
        }
        next=cur;
    }
    return next[-1+1];
}

// OR

#include<vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for(int index= n-1; index>=0; index--)
    {
        for(int previndex=index-1; previndex>=-1; previndex--)
        {
            int len=0+ dp[index+1][previndex+1];
    
            if(previndex ==-1 or arr[index]>arr[previndex])
            {
                len=max(len , 1+ dp[index+1][index+1]);
            }

            dp[index][previndex+1]= len;    
        }
    }
    return dp[0][-1+1];
}

// OR
#include<vector>
int f(int index, int previndex, int arr[], int n, vector<vector<int>> &dp)
{
    if(index==n)
        return 0;
    
    if(dp[index][previndex+1]!= -1 )
        return dp[index][previndex+1];
    
    int len=0+ f(index+1, previndex, arr, n, dp);
    
    if(previndex ==-1 or arr[index]>arr[previndex])
    {
        len=max(len,1+ f(index+1, index, arr, n, dp));
    }
    
    return dp[index][previndex+1]= len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, -1, arr, n, dp);
}


