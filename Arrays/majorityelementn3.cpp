// 229. Majority Element II
// Medium

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]

// Example 2:

// Input: nums = [1]
// Output: [1]

// Example 3:

// Input: nums = [1,2]
// Output: [1,2]

 

// Constraints:

//     1 <= nums.length <= 5 * 104
//     -109 <= nums[i] <= 109

 /*
 Solution 3: Optimal Solution (Extended Boyer Moore’s Voting Algorithm)

Approach + Intuition: In our code, we start with declaring a few variables:

    num1 and num2 will store our currently most frequent and second most frequent element.
    c1 and c2 will store their frequency relatively to other numbers.
    We are sure that there will be a max of 2 elements which occurs > N/3 times because there cannot be if you do a simple math addition. 

Let, ele be the element present in the array at any index. 

    if ele == num1, so we increment c1.
    if ele == num2, so we increment c2.
    if c1 is 0, so we assign num1 = ele.
    if c2 is 0, so we assign num2 = ele.
    In all the other cases we decrease both c1 and c2.

In the last step, we will run a loop to check if num1 or nums2 are the majority elements or not by running a for loop check.

Intuition: Since it’s guaranteed that a number can be a majority element, hence it will always be present at the last block, hence, in turn, will be on nums1 and nums2.
*/

class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int count1=0,count2=0,n=nums.size();
        int element1,element2;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element1)
                    count1++;
            else if(nums[i]==element2)
                count2++;
            else if(count1==0)
            {
                element1=nums[i];
                count1=1;                
            }
            else if(count2==0)
            {
                element2=nums[i];  
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }            
        }
        
        count1=count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element1)
                    count1++;
            else if(nums[i]==element2)
                count2++;
        }
        vector<int> res;
        if(count1>n/3)
            res.push_back(element1);
        if(count2>n/3)
            res.push_back(element2);
        return res;
    }
};