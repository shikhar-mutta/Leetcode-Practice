// Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: Hashing + Math
//  1. We can solve this problem by using a hash map to store the frequency of the difference between the number and its reverse.
//  2. We can use the formula n*(n-1)/2 to calculate the number of pairs for each unique difference.
//  3. We can use a static lambda to disable synchronization with C I/O and untie cin from cout to improve performance
class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        const long long MOD = 1000000007;
        unordered_map<int, long long> freq;
        long long res = 0;
        for (int x : nums)
        {
            int key = x - rev(x);
            res = (res + freq[key]) % MOD;
            ++freq[key];
        }
        return res;
    }

private:
    int rev(int x)
    {
        int r = 0;
        while (x)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return r;
    }
};