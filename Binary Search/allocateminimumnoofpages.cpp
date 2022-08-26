// Allocate Minimum Number of Pages

// Problem Statement: Given an array of integers A of size N and an integer B.
// The College library has N bags, the ith book has A[i] number of pages.
// You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

// Conditions given :
// A book will be allocated to exactly one student.
// Each student has to be allocated at least one book.
// Allotment should be in contiguous order, for example, A student cannot be allocated book 1 and book 3, skipping book 2.
// Calculate and return the minimum possible number. Return -1 if a valid assignment is not possible.

// Examples:

// Example 1:

// Input: A = [12, 34, 67, 90]
//        B = 2

// Output: 113

// Explaination: Let’s see all possible cases of how books can be allocated for each student. 

// So, the maximum number of pages allocated in each case is [191,157,113]. So, the minimum number among them is 113. 
// Hence, our result is 113.

// Example 2:

// Input: A = [5, 17, 100, 11]
//        B = 4

// Output: 100

bool canallocate(long long limit, long long students, long long noofbooks, vector<int> book)
{
    long long pages=0;
    long long currstudent=1;
//     if(limit<book[0])
//         return false;
    for(long long i=0;i<noofbooks;i++)
    {
        if(pages+book[i]>limit)
        {
            currstudent++;
            pages=book[i];
            if(pages>limit)
                return false;
        }
        else
        {
            pages+=book[i];
        }
    }
    if(currstudent <= students)
        return true;
    return false;
}

long long ayushGivesNinjatest(long long students, long long noofbooks, vector<int> book) 
{    
    if(students>noofbooks)
        return -1;
    long long low=book[0], high=0,mid;
    for(long long i=0;i<noofbooks;i++)   
    {
        high+=book[i];
        low=min(low,(long long)book[i]);
    }

    while(low<=high)
    {
        mid=((high-low) >> 1) +low;  //  =(low+high)/2
        if(canallocate(mid, students, noofbooks, book))
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}