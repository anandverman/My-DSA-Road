// 169. Majority Element
// Easy

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3

// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

 

// Constraints:

//     n == nums.length
//     1 <= n <= 5 * 104
//     -109 <= nums[i] <= 109


//Approach 1: brute force :Time Complexity: O(N2), Space Complexity: O(1)


//Approach 2: Hash Map :Time Complexity: O(N)-> Frequency array or O(N log N) -> HashMap, Space Complexity: O(N)

/*Solution 3 (Optimal):

Moore’s Voting Algorithm

Intuition: The question clearly states that the nums array has a majority element. Since it has a majority element we can say definitely the count is more than N/2.

Majority element count = N/2 + x;

Minority/Other elements = N/2 – x;

Where x is the number of times it occurs after reaching the minimum value N/2.

Now, we can say that count of minority elements and majority element are equal upto certain point of time in the array. So when we traverse through the array we try to keep track of the count of elements and which element we are tracking. Since the majority element appears more than N/2 times, we can say that at some point in array traversal we find the majority element. 

Approach: 

    Initialize 2 variables: 
        Count –  for tracking the count of element
        Element – for which element we are counting
    Traverse through nums array.
        If Count is 0 then initialize the current traversing integer of array as Element 
        If the traversing integer of array and Element are same increase Count by 1
        If they are different decrease Count by 1
    The integer present in Element is the result we are expecting 
    */

   class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
                element=nums[i];
            if(nums[i]==element)
                count++;
            else
                count--;
        }
        return element;
    }
};