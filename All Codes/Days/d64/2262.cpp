// Link: https://leetcode.com/problems/total-appeal-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: for substrings ending at index i, char c's contribution to
// appeal is 1 for every substring where c is present, which equals
// (i - lastSeen[c]) distinct starting positions (since starts beyond
// lastSeen[c] give a substring containing c for the first time at i).
// Sum this over all i and all chars implicitly via running total.
class Solution
{
public:
    long long appealSum(string s)
    {
        vector<int> last(26, -1);
        long long total = 0, cur = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            int c = s[i] - 'a';
            cur += (i - last[c]);
            last[c] = i;
            total += cur;
        }
        return total;
    }
};
