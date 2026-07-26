// Link: https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the diff-index list + dp array
// Approach: collect indices where s1/s2 differ; odd count is impossible.
// dp2[i] (doubled to stay integer) = min cost to resolve diff[i..end]: either
// treat diff[i] as "solo" using the general any-two-indices op at cost x/2
// (valid because that op fixes any 2 positions anywhere for cost x, so used
// on lone positions the cost amortizes to x/2 each, and the total count of
// such solo picks is always even) plus dp2[i+1], or pair diff[i] directly
// with diff[i+1] via a chain of adjacent-flip ops costing their distance,
// plus dp2[i+2]. This captures pairings a simple consecutive-only pairing
// misses (e.g. nesting far-apart cheap-x pairs around close cheap-distance
// pairs) — a naive dp pairing only adjacent list elements underestimates
// what's achievable and can produce a higher (wrong) cost.
class Solution
{
public:
    int minOperations(string s1, string s2, int x)
    {
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i]) diff.push_back(i);

        int m = diff.size();
        if (m == 0) return 0;
        if (m % 2 != 0) return -1;

        // dp2[i] = 2 * (min cost to fix diff[i..m-1]); kept doubled so the
        // x/2 "fix this one alone via the general op" option stays integer.
        vector<long long> dp2(m + 1, 0);
        dp2[m - 1] = x;
        for (int i = m - 2; i >= 0; i--)
            dp2[i] = min(dp2[i + 1] + x, dp2[i + 2] + 2LL * (diff[i + 1] - diff[i]));

        return (int)(dp2[0] / 2);
    }
};
