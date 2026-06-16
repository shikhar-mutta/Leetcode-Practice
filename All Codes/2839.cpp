// Link: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    bool canBeEqual(string s1, string s2)
    {
        // swaps only between indices 2 apart -> even and odd positions stay separate.
        // equal-able iff the even-index chars match as a set and the odd-index chars match.
        string e1, e2, o1, o2;
        for (int i = 0; i < (int)s1.size(); ++i)
            if (i % 2 == 0)
            {
                e1 += s1[i];
                e2 += s2[i];
            }
            else
            {
                o1 += s1[i];
                o2 += s2[i];
            }
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        sort(o1.begin(), o1.end());
        sort(o2.begin(), o2.end());
        return e1 == e2 && o1 == o2;
    }
};
