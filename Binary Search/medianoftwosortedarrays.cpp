// 4. Median of Two Sorted Arrays
// Hard

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.

// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 

// Constraints:

//     nums1.length == m
//     nums2.length == n
//     0 <= m <= 1000
//     0 <= n <= 1000
//     1 <= m + n <= 2000
//     -106 <= nums1[i], nums2[i] <= 106

// Solution 1: Naive Approach

// Intuition :

// The point to observe is that the given arrays are sorted. Our task is to merge them into a sorted array. 
// The word “merge” gives us hints to apply the merge step of merge sort.

// Approach :

// Take two pointers, each pointing to each array. Take an array of size (m+n) to store the final sorted array. 
// If the first pointed element is smaller than the second one, store that value in an array and move the first 
// pointer ahead by one. Else do the same for the second pointer when the case is vice-versa. Then use the formula 
// to get the median position and return the element present at that position.

// Time Complexity : O(m+n)
// Reason : We traverse through both the arrays linearly.

// Space Complexity : O(m+n)
// Reason : We store the final array whose size is m+n.

// Solution 2: Optimised Naive Approach
// We can optimize in space complexity.

// Approach :

// Similar to the naive approach, instead of storing the final merged sorted array, we can keep a counter to keep track 
// of the required position where the median will exist. First, using the median formula, get a position where the median 
// will exist. Then, follow the above approach and instead of storing elements in another array, we will increase the 
// counter value. When the counter value is equal to the median positions, return element.

// Time Complexity : O(m+n)
// Reason : We are still traversing both the arrays linearly.

// Space Complexity: O(1)
// Reason : We do not use any extra array.


// Solution 3: Efficient solution

// Intuition :
// We came up with a naive solution because of the hint that two arrays are sorted and we want elements from merged sorted arrays. 
// If we look into the word “sorted arrays”, we can think of a binary solution. Hence, we move to an efficient solution using 
// binary search. But how to apply binary search? Let’s look into the thought process.
// We know that we will get answers only from the final merged sorted arrays. We figured it out with the naive approach discussed 
// above. We will partition both the arrays in such a way that the left half of the partition will contain elements, which will 
// be there when we merge them, till the median element and rest in the other right half. This partitioning of both arrays will 
// be done by binary search.

// Approach :

// We will do a binary search in one of the arrays which have a minimum size among the two. 
// Firstly, calculate the median position with (n+1)/2. Point two-pointer, say low and high, equal to 0 and size of the 
// array on which we are applying binary search respectively. Find the partition of the array.

// Check if the left half has a total number of elements equal to the median position. 
// If not, get the remaining elements from the second array. 

// Now, check if partitioning is valid. This is only when l1<=r2 and l2<=r1. 
// If valid, return max(l1,l2)(when odd number of elements present) else return (max(l1,l2)+min(r1,r2))/2.

// If partitioning is not valid, move ranges. When l1>r2, move left and perform the above operations again. 
// When l2>r2, move right and perform the above operations.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums1.size(), m=nums2.size();
        if(m<n)
            return findMedianSortedArrays(nums2,nums1);
        
        int low=0, high=n;
        while(low<=high)
        {
            int cut1= (low+high)>>1;
            int cut2= (n+m+1)/2 -cut1;
            
            int l1= (cut1==0 ? INT_MIN : nums1[cut1-1]);
            int l2= (cut2==0 ? INT_MIN : nums2[cut2-1]);
            
            int r1= (cut1==n ? INT_MAX : nums1[cut1]);
            int r2= (cut2==m ? INT_MAX : nums2[cut2]);
            
            if(l1 <= r2 and l2 <= r1)
            {
                if((n+m)%2==0)
                    return (max(l1,l2)+min(r1,r2)) / 2.0;                    
                else
                    return max(l1,l2);
            }
            else if( l1 > r2 )
                high= cut1 -1;
            else
                low= cut1 +1;
        }
        return 0;
    }
};