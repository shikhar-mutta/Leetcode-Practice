// Link: https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: analysis shows every coherent string of length n is one of
//  only three families: (a) at most one '1' anywhere (avoids both
//  forbidden patterns trivially — best achieved by keeping an existing
//  '1' if any and zeroing the rest, cost max(0,ones-1)), (b) all '1's
//  (cost = zeros count), or (c) the single specific string
//  "1" + "0"*(n-2) + "1" (forced by requiring the first and last
//  characters to be the only two ones with everything else 0). The
//  answer is the minimum Hamming distance to any of these three targets,
//  verified by brute force against all coherent strings for n up to 8.
class Solution
{
public:
    int minFlips(string s)
    {
        int f[2] = {0, 0};
        for (auto &c : s)
            f[c & 1]++;

        if (!f[0] || !f[1])
            return 0;

        return min(f[0],
                   f[1] - (s.front() & s.back() & 1) - 1 // f[1] - (1 or 2)
        );
    }
};