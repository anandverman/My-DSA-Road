// Problem Statement

// You are given a N x 2 2-D array 'Jobs' of 'N' jobs where Jobs[i][0] denote the deadline of i-th job 
// and Jobs[i][1] denotes the profit associated with i-th job.
// You will make a certain profit if you complete the job within the deadline associated with it. 
// Each job takes 1 unit of time to be completed, and you can schedule only one job at a particular time.
// Your task is to find out the maximum profit that you can make.
// Note :

// If a particular job has a deadline 'x', it means that it needs to be completed at any time interval before 'x'.

// For Example :

// If jobs is - 

// [ 2 40 ]
// [ 2 20 ]
// [1 10 ]

// So, there are a total of 3 jobs. The first job has a deadline of 2, and the profit associated with it is 40. 
// The second job has a deadline of 2, and the profit is 20. Similarly, the third job has a deadline of 1, and the profit is 10. 
// So, it’s optimal to complete the first and second jobs to earn a profit of 60. One of the jobs can be 
// completed in the first minute, and the second job can be completed in the next minute. 
// So, the total profit = 40 + 20 = 60, and the number of completed jobs is 2. 
// Since the third job can’t be completed within the deadline, so we do not earn any profit.

// Follow Up :

// Can you solve this in (N*log(N)) time complexity?

// Input Format :

// The first line contains an integer 'T', which denotes the number of test cases or queries to be run. Then, 
// the T test cases follow. The first line of each test case contains a single integer N, denoting the number 
// of elements of the array “jobs”.
// The second line of each test case contains 'N' space-separated integers denoting the deadline assigned to each job.
// The third line of each test case contains 'N' space-separated integers denoting the profit associated with each job.

// Output Format :

// For each test case, print the maximum profit that can be earned. 

// Output for each test case will be printed in a separate line.

// Note :

// You do not need to print anything. It has already been taken care of. Just implement the given function.

// Constraints :

// 1 <= T <= 100
// 1 <= N <= 5000
// 1 <= jobs[i][0] <= 3000
// 1 <= jobs[i][1] <= 10^5

// Time limit: 1 sec

// Sample Input 1 :

// 2
// 4
// 2 2 1 1
// 30 40 10 10
// 5
// 2 4 1 3 5
// 25 40 5 50 60

// Sample Output 1 :

// 70
// 180

// Explanation For Sample Input 1 :

// For the first test case, the first and second jobs can be completed within the deadlines, 
// and we earn a profit of 70 by doing so.

// For the second test case, all the jobs have different deadlines. So we complete all the jobs.

// Sample Input 2 :

// 2
// 1
// 2
// 50
// 3
// 1 1 1
// 40 60 50

// Sample Output 2 :

// 50
// 60

// Solution: Striver's Approach but on vectors.

#include<algorithm>
bool sortcompare(vector<int> j1,vector<int> j2)
{
    if(j1[1]>j2[1])
        return true;
    return false;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int sum=0,n=jobs.size(),maxdeadline=0;
    sort(jobs.begin(),jobs.end(),sortcompare);
    for(int i=0;i<n;i++)
    {
        maxdeadline=max(maxdeadline,jobs[i][0]);
    }
    
    int slots[maxdeadline+1]={0};    
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i][0];j>0;j--)
        {
            if(slots[j]==0)
            {
                slots[j]=i+1;
                sum+=jobs[i][1];
                break;
            }
        }
    }    
    return sum;
}
