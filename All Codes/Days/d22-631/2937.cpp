// Link: https://leetcode.com/problems/make-three-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(min(|s1|, |s2|, |s3|)), SC: O(1)
    int findMinimumOperations(string s1, string s2, string s3)
    {
        // only trailing deletions allowed -> all three must reduce to their common prefix
        int L = 0, lim = min({s1.size(), s2.size(), s3.size()});
        while (L < lim && s1[L] == s2[L] && s2[L] == s3[L])
            L++;
        if (L == 0)
            return -1; // no common first char -> impossible
        // delete every char beyond the common prefix in each string
        return (s1.size() - L) + (s2.size() - L) + (s3.size() - L);
    }
};
