// Link: https://leetcode.com/problems/maximum-running-time-of-n-computers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long lo = 0, hi = 0;
        for (int b : batteries) hi += b;
        hi /= n;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            long long sum = 0;
            for (int b : batteries) sum += min((long long)b, mid);
            if (sum >= (long long)n * mid) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
