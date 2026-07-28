// Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m log(sum))  SC: O(1)
// Approach: binary search on running time T. Feasible iff
// sum(min(battery, T)) >= n * T, since batteries exceeding T can be freely
// swapped across computers without loss.
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long lo = 0, hi = 0;
        for (int b : batteries) hi += b;
        hi /= n;
        auto feasible = [&](long long T) {
            long long sum = 0;
            for (int b : batteries) sum += min((long long)b, T);
            return sum >= (long long)n * T;
        };
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            if (feasible(mid)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
