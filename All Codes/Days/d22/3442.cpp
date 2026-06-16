// Link: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxDifference(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;

        // largest odd frequency minus smallest (positive) even frequency
        int maxOdd = 0, minEven = INT_MAX;
        for (int f : freq)
        {
            if (f == 0)
                continue;
            if (f % 2)
                maxOdd = max(maxOdd, f);
            else
                minEven = min(minEven, f);
        }
        return maxOdd - minEven;
    }
};
