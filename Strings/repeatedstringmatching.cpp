// 686. Repeated String Match
// Medium

// Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it.
// If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

// Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".

 

// Example 1:

// Input: a = "abcd", b = "cdabcdab"
// Output: 3
// Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

// Example 2:

// Input: a = "a", b = "aa"
// Output: 2

 

// Constraints:

//     1 <= a.length, b.length <= 104
//     a and b consist of lowercase English letters.

//Solution 1: Naive Approach.

class Solution {
public:
    
    bool isSubstring(string a, string b)
    {
        int sa=a.length(), sb=b.length();
        
        for(int i=0; i<=sa-sb; i++)
        {
            int j;
            for(j=0; j<sb; j++)
            {
                if(a[i+j]!=b[j])
                    break;
            }
            if(j==sb)
                return true;           
        }
        return false;
    }
        
        
    int repeatedStringMatch(string a, string b) {
        int count =1;
        string s=a;
        while(s.length()<b.length())
        {
            s+=a;
            count++;
        }
        if(isSubstring(s,b))
            return count;
        
        if(isSubstring(s+a,b))
            return count+1;
        
        return -1;
    }
};

//Optimized Approach: Knuth Morris Pratt String Matcher
class Solution {
public:
    
    bool findsubstring(string &a, string &b, vector<int> &lps)
    {
        int la=a.length(), lb=b.length();
        
        int i=0, j=0;
        
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
                return true;
        }
            
        return false;
    }
        
        
    int repeatedStringMatch(string a, string b) {
        int la=a.length();
        int lb=b.length();
        
        vector<int> lps(lb);  //longest prefix that is suffix in string b index array
        lps[0] =0;
        int i=1;
        int len=0;
        while(i<lb)
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
        string s=a;
        while(s.length()<lb)
            s+=a;
        int count=s.length()/la;
        
        if(findsubstring(s,b,lps))
            return count;
        
        s+=a;
        count++;
        if(findsubstring(s,b,lps))
            return count;
        
        return -1;
    }
};
