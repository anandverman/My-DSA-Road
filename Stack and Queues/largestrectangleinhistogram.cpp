// 84. Largest Rectangle in Histogram
// Hard

// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
// return the area of the largest rectangle in the histogram.

 

// Example 1:

// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram where width of each bar is 1.
// The largest rectangle is shown in the red area, which has an area = 10 units.

// Example 2:

// Input: heights = [2,4]
// Output: 4

 

// Constraints:

//     1 <= heights.length <= 105
//     0 <= heights[i] <= 104

//Naive Solution
// Time Complexity: O(N*N ) 
// Space Complexity: O(1)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int maxarea=0;
        for(int i=0; i<n ;i++)
        {
            int minheight=10000;
            for(int j=i; j<n; j++)
            {
                minheight=min(minheight,h[j]);
                maxarea=max(maxarea, minheight*(j+1-i));
            }
        }
        return maxarea;
    }
};

// More Optimal Solution:
// Intuition: The intuition behind the approach is the same as finding the smaller element on both sides but in an 
//            optimized way using the concept of the next greater element and the next smaller element.
// Time Complexity: O( N )
// Space Complexity: O(3N) where 3 is for the stack, left small array and a right small array

class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        int maxarea=0,n=h.size();
        stack<int> st;
        int leftsmall[n], rightsmall[n];
         //loop to find left boundary: leftboundary= index of left smaller element +1
        for(int i=0; i<n; i++)
        {
            //while stack is not empty and height at index st.top() is greater or equal to height at index i.
            while(!st.empty() and h[st.top()]>= h[i]) 
            {   
                st.pop();                  //pop the greater height indexes from stack
            }
            
            if(st.empty())                 //if stack is empty, there is no smaller element on left
                leftsmall[i]=0;            //so left boundary is zero
            else                //otherwise, left boundary is index (st.top()+1)
                leftsmall[i]=st.top()+1;
            
            st.push(i);                    //push current index on stack
        }   
        
        while(!st.empty())      //empty stack for reuse
            st.pop();
        
         //loop to find right boundary: rightboundary= index of right smaller element -1
        for( int i=n-1; i>=0; i++)
        {
            //while stack is not empty and height at index st.top() is greater or equal to height at index i.
            while(!st.empty() and h[st.top()>= h[i]])
            {       
                st.pop();               //pop the greater height index from stack
            }
            
            if(st.empty())              //if stack is empty, there is no smaller element on right
                rightsmall[i]=n-1;      //so right boundary is n-1
            else
                rightsmall[i]=st.top()-1;
            st.push(i);                 //push current element on stack
        }
        
        for(int i=0; i<n; i++)
        {
            maxarea=max(maxarea,h[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        return maxarea;
    }
};

//Most Optimal Solution (in single pass)
// Time Complexity: O( N ) + O (N)
// Space Complexity: O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int maxarea;
        stack<int> st;
        for(int i=0; i<=n; i++)
        {
            while(!st.empty() and (i==n or h[st.top()] >= h[i]))
            {
                int height=h[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width=i;
                else 
                    width = i-st.top()-1;
                maxarea= max(maxarea, width* height);
            }
            st.push(i);
        }
        return maxarea;
    }
    
};