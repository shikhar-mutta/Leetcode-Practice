// Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(string s)
    {
        int n = s.size(), mismatch = 0;
        // count positions differing from the pattern starting with '0' (0101...)
        for (int i = 0; i < n; i++)
            if (s[i] - '0' != i % 2) mismatch++;
        // the other pattern (1010...) needs the complementary number of changes
        return min(mismatch, n - mismatch);
    }
};
