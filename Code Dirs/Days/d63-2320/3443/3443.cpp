// Link: https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: since we only need the best single prefix, each prefix can be
// optimized independently as if it had its own fresh k-change budget.
// For a prefix with counts cN,cS,cE,cW, the achievable distance without
// any changes is base = |cN-cS| + |cE-cW|; each change can convert one
// "wrong-direction" character into the dominant one, adding at most 2 to
// that base, and the total can never exceed the prefix length i. So the
// best achievable at prefix i is min(i, base + 2*k); take the max over i.
class Solution
{
public:
    int maxDistance(string s, int k)
    {
        int cN = 0, cS = 0, cE = 0, cW = 0;
        int ans = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            char c = s[i];
            if (c == 'N')
                cN++;
            else if (c == 'S')
                cS++;
            else if (c == 'E')
                cE++;
            else
                cW++;
            int base = abs(cN - cS) + abs(cE - cW);
            ans = max(ans, min(i + 1, base + 2 * k));
        }
        return ans;
    }
};
