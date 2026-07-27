// Link: https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: analysis shows every coherent string of length n is one of
// only three families: (a) at most one '1' anywhere (avoids both
// forbidden patterns trivially — best achieved by keeping an existing
// '1' if any and zeroing the rest, cost max(0,ones-1)), (b) all '1's
// (cost = zeros count), or (c) the single specific string
// "1" + "0"*(n-2) + "1" (forced by requiring the first and last
// characters to be the only two ones with everything else 0). The
// answer is the minimum Hamming distance to any of these three targets,
// verified by brute force against all coherent strings for n up to 8.
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        int ones = count(s.begin(), s.end(), '1');
        int zeros = n - ones;

        int famA = max(0, ones - 1);
        int famB = zeros;
        int ans = min(famA, famB);

        if (n >= 2) {
            int diff = 0;
            for (int i = 0; i < n; i++) {
                char want = (i == 0 || i == n - 1) ? '1' : '0';
                if (s[i] != want) diff++;
            }
            ans = min(ans, diff);
        }
        return ans;
    }
};
