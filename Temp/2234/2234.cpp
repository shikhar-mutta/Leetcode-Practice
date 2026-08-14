// Link: https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long costToRaise(vector<int>& a, int count, long long L, vector<long long>& prefix) {
        int pos = lower_bound(a.begin(), a.begin() + count, (int)min(L, (long long)INT_MAX)) - a.begin();
        return L * (long long)pos - prefix[pos];
    }

    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(flowers.begin(), flowers.end());
        int n = flowers.size();
        int idx = lower_bound(flowers.begin(), flowers.end(), target) - flowers.begin();
        vector<int> a(flowers.begin(), flowers.begin() + idx);
        long long cnt = n - idx;
        int m = a.size();

        vector<long long> prefix(m + 1, 0);
        for (int i = 0; i < m; i++) prefix[i + 1] = prefix[i] + a[i];

        vector<long long> costFull(m + 1, 0);
        for (int i = m - 1; i >= 0; i--) costFull[i] = costFull[i + 1] + (target - a[i]);

        long long answer = 0;
        for (int i = 0; i <= m; i++) {
            long long cost = costFull[i];
            if (cost > newFlowers) continue;
            long long remain = newFlowers - cost;
            long long contrib = (cnt + (m - i)) * (long long)full;
            if (i > 0) {
                long long lo = 0, hi = target - 1;
                while (lo < hi) {
                    long long mid = lo + (hi - lo + 1) / 2;
                    if (costToRaise(a, i, mid, prefix) <= remain) lo = mid;
                    else hi = mid - 1;
                }
                contrib += lo * (long long)partial;
            }
            answer = max(answer, contrib);
        }
        return answer;
    }
};
