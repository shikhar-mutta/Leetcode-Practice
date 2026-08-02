// Link: https://leetcode.com/problems/minimum-operations-to-make-character-frequencies-equal/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(26 * range(f))  SC: O(26)
// Approach: three ops available (delete, insert, shift a char to the
// NEXT letter only). Try every candidate target frequency f. Process
// letters a..z in order with two DP states: dp1 = best cost ending with
// this letter possibly having "borrowed" a shift-in from the previous
// letter, dp2 = best cost with this letter set to 0 (freeing its full
// count as a potential shift source for the next letter). A letter
// below f can fill its deficit via inserts, or more cheaply via shifted
// -in surplus from the immediately preceding letter (its "free" supply).
class Solution
{
public:
    int makeStringGood(string s)
    {
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        int n = s.size();
        int lo = INT_MAX, hi = 0;
        for (int x : cnt)
            if (x > 0)
            {
                lo = min(lo, x);
                hi = max(hi, x);
            }
        int result = n;
        for (int f = lo; f <= hi; f++)
        {
            long long dp1 = 0, dp2 = 0;
            for (int i = 0; i < 26; i++)
            {
                if (cnt[i] == 0)
                    continue;
                long long ndp1, ndp2;
                if (cnt[i] >= f)
                {
                    ndp1 = n;
                    ndp2 = min(dp1, dp2) + (cnt[i] - f);
                }
                else
                {
                    long long free = 0;
                    if (i - 1 >= 0 && cnt[i - 1] > 0)
                    {
                        free = (cnt[i - 1] >= f) ? (cnt[i - 1] - f) : cnt[i - 1];
                    }
                    ndp1 = min(min(dp1, dp2) + (f - cnt[i]), dp2 + max((long long)(f - cnt[i]) - free, 0LL));
                    ndp2 = min(dp1, dp2) + cnt[i];
                }
                dp1 = ndp1;
                dp2 = ndp2;
            }
            result = min({result, (int)dp1, (int)dp2});
        }
        return result;
    }
};
