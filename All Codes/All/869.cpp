// Link: https://leetcode.com/problems/reordered-power-of-2/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n)) + O(30*log(n)) = O(log(n))
// SC: O(1)
// Approach: Create a signature of the number n by counting the frequency of each digit. Then, iterate through all powers of 2 up to 10^9 and check if any of them has the same signature as n. If a match is found, return true; otherwise, return false.

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        auto signature = [](int x)
        {
            array<int, 10> cnt{};
            while (x)
            {
                cnt[x % 10]++;
                x /= 10;
            }
            return cnt;
        };

        auto target = signature(n);
        for (int p = 1; p <= 1e9; p <<= 1)
            if (signature(p) == target)
                return true;
        return false;
    }
};
