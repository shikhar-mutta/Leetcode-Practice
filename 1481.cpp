// Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) + O(n) + O(nlogn) + O(n) = O(nlogn)
// SC: O(n)
// Approach:
//  1. Sort the array
//  2. Count the frequency of each unique integer and store it in a vector
//  3. Sort the frequency vector
//  4. Iterate through the frequency vector and remove the least frequent integers until k is exhausted

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &a, int k)
    {
        sort(a.begin(), a.end());
        vector<int> b;
        int c = 1, d = a.size();
        for (int i = 0; i < d - 1; i++)
        {
            if (a[i] == a[i + 1])
            {
                c++;
            }
            else
            {
                b.push_back(c);
                c = 1;
            }
        }
        b.push_back(c);
        sort(b.begin(), b.end());
        d = b.size();
        for (int i : b)
        {
            if (k >= i)
            {
                k -= i;
                d--;
            }
            else
                break;
        }
        return d;
    }
};