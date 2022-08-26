// 42. Trapping Rain Water
// Hard

// Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it can trap after raining.

 

// Example 1:

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
// In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

 

// Constraints:

//     n == height.length
//     1 <= n <= 2 * 104
//     0 <= height[i] <= 105

//Approach 1: Naive Approach (Brute Force): Find max level from i to its left, and i to its right (i inclusive both times)
// find minimum of both maxes and subtract ith level from the minimum, this gives water at ith level, add it to result for all i.
//Gives TLE for large arrays of inputs.

// Time Complexity: O(N*N) as for each index we are calculating leftMax and rightMax so it is a nested loop.
// Space Complexity: O(1).

class Solution {
public:
    int trap(vector<int>& level) 
    {
        int w=0,n=level.size();
        for(int i=0;i<n;i++)
        {
            int l=0,r=0,cur=i;
            while(cur>=0)
            {
                l=max(l,level[cur]);
                cur--;
            }
            cur=i;
            while(cur<n)
            {
                r=max(r,level[cur]);
                cur++;
            }
            w+=min(l,r)-level[i];
        }
        return w;
    }
};

// Approach 2: Optimized above solution by calculating and saving max levels to left and right in two arrays.

// Time Complexity:O(3*N) as we are traversing through the array only once. And O(2*N) for computing prefix and suffix array.
// Space Complexity:O(N)+O(N) for prefix and suffix arrays.

class Solution {
public:
    int trap(vector<int>& lvl) 
    {
        int w=0,n=lvl.size();
        int lmax[n],rmax[n];

        lmax[0]=lvl[0];
        for(int i=1;i<n;i++)
            lmax[i]=max(lmax[i-1],lvl[i]);

        rmax[n-1]=lvl[n-1];
        for(int i=n-2;i>=0;i--)
            rmax[i]=max(rmax[i+1],lvl[i]);

        for(int i=0;i<n;i++)
            w+=min(lmax[i],rmax[i])-lvl[i];
            
        return w;
    }
};

