// 28. Implement strStr()
// Easy

// Implement strStr().

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not 
// part of haystack.

// Clarification:

// What should we return when needle is an empty string? This is a great question to ask during an interview.

// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() 
// and Java's indexOf().

 

// Example 1:

// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:

// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

 

// Constraints:

//     1 <= haystack.length, needle.length <= 104
//     haystack and needle consist of only lowercase English characters.

// One Line solution:
class Solution {
public:
    int strStr(string hay, string needle) {
        return hay.find(needle);
    }
};

//Solution: Naive string matcher
class Solution {
public:
    int strStr(string hay, string needle) {
        if(needle=="")
            return 0;
        
        int hlen=hay.length(), nlen=needle.length();
        
        for(int i=0; i<hlen-nlen+1; i++)
        {
            int j;
            for(j=0; j<nlen; j++)
                if(hay[i+j]!=needle[j])
                    break;
            if(j==nlen)
                return i;
        }
        return -1;
    }
};

//Solution: KMP Algorithm
class Solution {
public:
    int strStr(string a, string b) {

        int la=a.length(), lb=b.length();
        
        vector<int> lps(lb);
        lps[0]=0;
        
        int i=1;
        int len=0;
        
        while(i<lb)     //constructing lps array of b
        {
            if(b[i]==b[len])                
                lps[i++]=++len;                        
            else
            {
                if(len==0)
                    lps[i++]=0;                
                else
                    len=lps[len-1];
            }
        }
                
        //comparing lps of b in a
        i=0;
        int j=0;
        
        while(i<la)
        {
            if(a[i]==b[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j==0)                                                                              
                    i++;               
                
                else
                    j=lps[j-1];
            }
            
            if(j==lb)
                return i-lb;
                
        }
        
        return -1;
    }
};