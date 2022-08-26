// 18. 4Sum
// Medium

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

//     0 <= a, b, c, d < n
//     a, b, c, and d are distinct.
//     nums[a] + nums[b] + nums[c] + nums[d] == target

// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]

 

// Constraints:

//     1 <= nums.length <= 200
//     -109 <= nums[i] <= 109
//     -109 <= target <= 109

//Optimized Approach: TC O(nlogn+ n^3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& copy, long long target) {       
        vector<vector<int>> res;
         if (copy.empty())
            return res;
        int n=copy.size();
        // vector<int> copy;
        // copy=nums;
        sort(copy.begin(),copy.end());
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int left=j+1,right=n-1;
                long long diff=target-(copy[i]+copy[j]);
                while(left<right)
                {
                    if(copy[left]+copy[right]==diff)
                    {
                        vector<int> tmp(4,0);
                        tmp[0]=copy[i];
                        tmp[1]=copy[j];
                        tmp[2]=copy[left];
                        tmp[3]=copy[right];
                        res.push_back(tmp);
                        //skip consecutive duplicates of left and right
                        while(left<right and copy[left]==tmp[2])   
                            left++;
                        while(left<right and copy[right]==tmp[3])
                            right--;
                    }
                    else if(copy[left]+copy[right]>diff)
                        right--;
                    else
                        left++;
                }
                //skip consecutive duplicates of j
                while(j<n-2 and copy[j]==copy[j+1])
                    j++;
            }
            //skip consecutive duplicates of i
            while(i<n-3 and copy[i]==copy[i+1])
                    i++;
        }
        return res;    
    }
};