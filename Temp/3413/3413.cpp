// Link: https://leetcode.com/problems/maximum-coins-from-k-consecutive-bags/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<long long> prefix(n + 1, 0);
        vector<long long> ls(n);
        for (int i = 0; i < n; i++) {
            long long l = coins[i][0], r = coins[i][1], c = coins[i][2];
            prefix[i + 1] = prefix[i] + c * (r - l + 1);
            ls[i] = l;
        }

        auto windowSum = [&](long long start, long long end) -> long long {
            if (start > end) return 0;
            // find range of intervals overlapping [start, end]
            // idx_lo: first interval with r >= start
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (coins[mid][1] >= start) hi = mid;
                else lo = mid + 1;
            }
            int idxLo = lo;
            // idx_hi: last interval with l <= end
            lo = 0; hi = n;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (coins[mid][0] > end) hi = mid;
                else lo = mid + 1;
            }
            int idxHi = lo - 1;
            if (idxLo > idxHi) return 0;

            long long total = prefix[idxHi + 1] - prefix[idxLo];
            // subtract partial from idxLo
            {
                long long l = coins[idxLo][0], r = coins[idxLo][1], c = coins[idxLo][2];
                long long fullLen = r - l + 1;
                long long overlapLen = min(r, end) - max(l, start) + 1;
                total -= c * (fullLen - overlapLen);
            }
            if (idxHi != idxLo) {
                long long l = coins[idxHi][0], r = coins[idxHi][1], c = coins[idxHi][2];
                long long fullLen = r - l + 1;
                long long overlapLen = min(r, end) - max(l, start) + 1;
                total -= c * (fullLen - overlapLen);
            }
            return total;
        };

        long long best = 0;
        for (int i = 0; i < n; i++) {
            long long start1 = coins[i][0];
            best = max(best, windowSum(start1, start1 + k - 1));
            long long end2 = coins[i][1];
            long long start2 = end2 - k + 1;
            best = max(best, windowSum(start2, end2));
        }
        return best;
    }
};
