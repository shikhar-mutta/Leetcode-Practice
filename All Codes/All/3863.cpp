// Link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: already sorted -> 0. n==2 and unsorted -> impossible (the
// only non-whole-string substrings are single chars). Otherwise, if the
// first char is already the global min or the last char is already the
// global max, one sort of the rest suffices. If a min/max char sits
// strictly in the interior, move it to an end (1 op) then sort the rest
// (1 op) = 2. Otherwise, sort the substring spanning both the min and
// max positions, then sort the rest = 3.
class Solution
{
public:
    int minOperations(string s)
    {
        if (is_sorted(s.begin(), s.end()))
            return 0;
        if (s.size() == 2)
            return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[s.size() - 1] == mx)
            return 1;
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i] == mx || s[i] == mn)
                return 2;
        }
        return 3;
    }
};