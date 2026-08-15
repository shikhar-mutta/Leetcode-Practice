// Link: https://leetcode.com/problems/minimum-time-to-activate-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        long long total = (long long)n * (n + 1) / 2;

        auto validCount = [&](int t) -> long long {
            vector<bool> active(n, false);
            for (int i = 0; i <= t; i++) active[order[i]] = true;
            long long gapSum = 0;
            int i = 0;
            while (i < n) {
                if (active[i]) { i++; continue; }
                int j = i;
                while (j < n && !active[j]) j++;
                long long len = j - i;
                gapSum += len * (len + 1) / 2;
                i = j;
            }
            return total - gapSum;
        };

        if (validCount(n - 1) < k) return -1;

        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (validCount(mid) >= k) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
