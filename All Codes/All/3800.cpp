// Link: https://leetcode.com/problems/minimum-cost-to-make-two-binary-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: only mismatched positions matter, split into type A (s=0,t=1)
// and type B (s=1,t=0). One swap within s (or within t) can fix one A and
// one B simultaneously (cost swapCost), or two flips can fix them
// separately (cost 2*flipCost) — take the cheaper per AB pair. Leftover
// same-type mismatches (after pairing min(a,b)) can be fixed two at a
// time via a cross-swap turning one into the opposite type followed by a
// same-string swap (cost crossCost+swapCost), or via two flips — take the
// cheaper per same-type pair. Any final unpaired single mismatch costs
// one flip.
class Solution
{
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost)
    {
        long long a = 0, b = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == t[i])
                continue;
            if (s[i] == '0')
                a++;
            else
                b++;
        }

        long long pairs = min(a, b);
        long long costAB = min((long long)swapCost, 2LL * flipCost);
        long long remaining = llabs(a - b);
        long long samePairs = remaining / 2;
        long long costSame = min(2LL * flipCost, (long long)crossCost + swapCost);
        long long leftover = remaining % 2;

        return pairs * costAB + samePairs * costSame + leftover * flipCost;
    }
};
