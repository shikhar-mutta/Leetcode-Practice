// Link: https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());
        int n = start.size();

        auto feasible = [&](long long gap) -> bool {
            long long last = (long long)start[0];
            for (int i = 1; i < n; i++) {
                long long lo = (long long)start[i];
                long long need = last + gap;
                long long pick = max(lo, need);
                if (pick > (long long)start[i] + d) return false;
                last = pick;
            }
            return true;
        };

        long long lo = 0, hi = (long long)2e9;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid;
            else hi = mid - 1;
        }
        return (int)lo;
    }
};
