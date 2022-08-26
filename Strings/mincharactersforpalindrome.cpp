// Problem Statement
// Given a string STR of length N. The task is to return the count of minimum characters to be added at front to make the string 
// a palindrome.
// For example, for the given string “deed”, the string is already a palindrome, thus, minimum characters needed are 0.
// Similarly, for the given string “aabaaca”, the minimum characters needed are 2 i.e. ‘a’ and ‘c’ which makes the string 
// “acaabaaca” palindrome.
// Input format :

// The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then, the T test cases 
// follow.

// The first and only line of each test case or query contains the string STR. 

// Output format :

// For each test case, print the count of minimum characters needed in a separate line.

// Note :

// You do not need to print anything, it has already been taken care of. Just implement the given function.

// Constraints :

// 1 <= T <= 10 
// 1 <= N <= 10 ^ 5 
// STR contains only lowercase English letters.

// Time limit: 1 sec

// Sample input 1 :

// 2
// abcd
// dad 

// Sample output 1 :

// 3
// 0

// Explanation of sample input 1 :

// For test case 1 : 
// Minimum characters to be added at front to make it a palindrome are 3 i.e. “dcb” which makes the string “dcbabcd”.  

// For test case 2 :
// The string is already a palindrome, we do not need to add any character.     

// Sample input 2 :

// 2
// xxaxxa    
// abb

// Sample output 2 :

// 1
// 2

//Naive Approach: Pop last character of string till string becomes palindrome, return no of characters popped.
// Code: Time Complexity O(n*n); Space Complexity O(1)
bool ispalindrome(string s)
{
    for(int i=0, j=s.length()-1; i<j; i++,j--)
    {
        if(s[i]!=s[j])
            return false;
    }
    return true;
}

int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.length();
    int i=0, j=n-1;
    string s=str;
    int count=0;
    while(!ispalindrome(s))
    {
        s.pop_back();
        count++;
    }
    return count;
}

//Optimized Approach: Using KMP string matching algo, find LPS array of string: str+"any non alphabet character"+ reverse(str)
//                    Required ans is length of original string- last element of LPS array of above string. 
// Code: Time Complexity O(n); Space Complexity O(2n+1)
#include<vector>
#include<algorithm>
vector<int> computelps(string s, int n)
{
    vector<int> lps(n);
    lps[0]=0;
    int i=1, len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            lps[i++]=++len;           
        }
        else
        {
            if(len==0)
            {
                lps[i++]==0;
            }
            else
                len=lps[len-1];
        }
    }
    return lps;
}

int minCharsforPalindrome(string str) {
	// Write your code here.
	int n=str.length();
    string s=str+'*';
    reverse(str.begin(), str.end());
    s+=str;
    int l=s.length();
    vector<int> lps(l);
    lps=computelps(s,l);
    return n-lps.back();
}

