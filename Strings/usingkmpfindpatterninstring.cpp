// Problem Statement
// You are given two strings 'S' and 'P' consisting of lowercase English alphabets. Your task is to find whether the 'P' is 
// present in 'S' as a substring or not.
// Note

// 1. There may be more than one occurrence of 'P' in 'S'.
// 2. Some alphabets in the strings may be repeated.

// Input Format:

// The first line of input contains a single integer 'T', representing the number of test cases

// Then the 'T' test cases follow.

// The first line of each test case contains two space-separated strings 'P' and 'S' respectively.

// Output Format:

// For each test case, print a single line containing “YES” if string 'P' is present in string 'S' as a substring, 
// otherwise print “NO”.

// The output for each test case will be printed in a separate line.

// Note

// You don’t have to print anything, it has already been taken care of. Just implement the given function. 

// Constraints:

// 1 <= T <= 100
// 1 <= |S| <= 10000
// 1 <= |P| < |S|

// Where |S| and |P| represents the length of the string 'S' and 'P' respectively.

// Time limit: 1 sec.

// Sample input 1:

// 3
// xxy yxxyxxy
// a baac
// cfg cgfgfc

// Sample output 1

// YES
// YES
// NO

// Explanation for sample output 1

// In the first test case, there are two substrings equal to P on index 1 and 4 in S.

// In the second test case, there are two substrings equal to P on indexes 1 and 2 in S.
// In the third test case, P does not exist in S.

// Sample input 2:

// 3
// bbb abba
// iqw hdhhdqoa
// car caribbean 

// Sample output 2

// NO
// NO
// YES

// Explanation for sample output 2

//  In the first test case, P does not exist in S.
//  In the second test case, P does not exist in S.
//  In the third test case, there is one substring equal to P on index 1 in S.

//Solution using KMP:
bool findPattern(string b, string a)
{
    int la=a.length(), lb=b.length();

    vector<int> lps(lb);
    lps[0]=0;

    int i=1;
    int len=0;

    while(i<lb)     //constructing lps array of b
    {
        if(b[len]==b[i])
            lps[i++]=++len;
        else
            if(len==0)
                lps[i++]=0;
        else
            len=lps[len-1];
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
            if(j==0)
                i++;
        else
            j=lps[j-1];

        if(j==lb)
            return true;

    }

    return false;
}