// Link: https://leetcode.com/problems/subsequences-with-a-unique-middle-mode-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: coordinate compression to reduce the range of values, then maintain counts of occurrences to the left and right of each position. For each position, calculate the number of valid subsequences where the current element is the unique middle mode by considering combinations of elements to the left and right that satisfy the mode condition. Use combinatorial counting and modular arithmetic to handle large numbers.
class Solution
{
public:
    int subsequencesWithMiddleMode(vector<int> &nums)
    {
        const long long MOD = 1'000'000'007;
        int n = nums.size();
        if (n < 5)
            return 0;

        // coordinate compression
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            a[i] =
                lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();

        vector<long long> lcnt(m, 0), rcnt(m, 0);
        for (int x : a)
            rcnt[x]++;

        long long S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0;
        for (int i = 0; i < m; i++)
            S4 += rcnt[i] * (rcnt[i] - 1) / 2;

        long long total_left = 0, total_right = n;
        long long ans = 0;
        auto C2 = [&](long long x) -> long long
        {
            return x < 2 ? 0 : x * (x - 1) / 2;
        };

        for (int p = 0; p < n; p++)
        {
            int id = a[p];
            // remove p from right
            long long rc = rcnt[id];
            long long lc = lcnt[id];
            S1 -= lc;
            S2 += lc * (-2 * rc + 1);
            S3 -= lc * lc;
            S4 -= (rc - 1);
            rcnt[id]--;
            total_right--;

            long long left_c = lcnt[id];
            long long right_c = rcnt[id];
            long long TL = total_left - left_c;
            long long TR = total_right - right_c;

            long long L0 = C2(TL), L1 = left_c * TL, L2 = C2(left_c);
            long long R0 = C2(TR), R1 = right_c * TR, R2 = C2(right_c);
            __int128 tot = (__int128)(L0 + L1 + L2) * (R0 + R1 + R2);
            __int128 base =
                tot - (__int128)L0 * R0 - (__int128)L1 * R0 - (__int128)L0 * R1;

            long long SR2 = S4 - C2(right_c);
            long long SL2 = S5 - C2(left_c);
            long long SAB = S1 - left_c * right_c;
            long long SAB2 = S2 - left_c * right_c * right_c;
            long long SBA2 = S3 - right_c * left_c * left_c;

            __int128 validA = 0, validB = 0;
            if (left_c > 0 && TR >= 2)
            {
                __int128 term = (__int128)TL * (TR * (TR - 1) / 2) -
                                (__int128)TR * SAB + SAB2 - (__int128)SR2 * TL;
                validA = (__int128)left_c * term;
            }
            if (right_c > 0 && TL >= 2)
            {
                __int128 term = (__int128)TR * (TL * (TL - 1) / 2) -
                                (__int128)TL * SAB + SBA2 - (__int128)SL2 * TR;
                validB = (__int128)right_c * term;
            }
            __int128 cur = base + validA + validB;
            ans = (ans + (long long)(cur % MOD)) % MOD;

            // add p to left
            lc = lcnt[id];
            rc = rcnt[id];
            S1 += rc;
            S2 += rc * rc;
            S3 += rc * (2 * lc + 1);
            S5 += lc;
            lcnt[id]++;
            total_left++;
        }
        return (int)ans;
    }
};
