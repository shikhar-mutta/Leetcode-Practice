// Link: https://leetcode.com/problems/distinct-subsequences-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1) (26 letters)
// Approach: track total = number of distinct non-empty subsequences
// using characters so far, and last[c] = the total count right before
// character c was most recently appended. Appending a new character x
// doubles total (append x to every existing subsequence, plus x alone)
// minus the subsequences already counted from the last time x was
// appended (to avoid duplicates), all mod 1e9+7.
class Solution
{
public:
    int distinctSubseqII(string s)
    {
        const long long MOD = 1e9 + 7;
        vector<long long> last(26, 0);
        long long total = 0;
        for (char c : s)
        {
            int idx = c - 'a';
            long long newTotal = (2 * total + 1 - last[idx] + MOD) % MOD;
            last[idx] = total + 1;
            total = newTotal;
        }
        return (int)total;
    }
};
