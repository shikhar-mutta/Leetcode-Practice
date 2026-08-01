// Link: https://leetcode.com/problems/number-of-stable-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach:
//  1. We can use dynamic programming to count the number of stable subsequences.
//  2. We can maintain four variables: e1, e2, o1, and o2, where e1 is the count of stable subsequences ending with an even number, e2 is the count of stable subsequences ending with an even number and having at least one even number, o1 is the count of stable subsequences ending with an odd number, and o2 is the count of stable subsequences ending with an odd number and having at least one odd number.
//  3. For each number in the array, we can update these variables based on whether the number is even or odd. If the number is even, we can update e1 and e2 based on the previous values of e1, e2, o1, and o2. If the number is odd, we can update o1 and o2 based on the previous values of e1, e2, o1, and o2.
//  4. Finally, we can return the sum of e1, e2, o1, and o2 modulo 10^9 + 7, which is the total count of stable subsequences.
#define ll long long
class Solution
{
public:
    int countStableSubsequences(vector<int> &nums)
    {
        ll e1 = 0, e2 = 0, o1 = 0, o2 = 0;
        int mod = 1e9 + 7;
        for (int x : nums)
        {
            if ((x & 1) == 0)
            {
                ll ne1 = (e1 + (o1 + o2 + 1)) % mod;
                ll ne2 = (e2 + e1) % mod;
                e1 = ne1;
                e2 = ne2;
            }
            else
            {
                ll no1 = (o1 + (e1 + e2 + 1)) % mod;
                ll no2 = (o1 + o2) % mod;
                o1 = no1;
                o2 = no2;
            }
        }
        return (int)((e1 + e2 + o1 + o2) % mod);
    }
};