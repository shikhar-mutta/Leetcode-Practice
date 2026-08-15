// Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int lo = 0, hi = *max_element(arr.begin(), arr.end());
        auto sumWithCap = [&](int cap) {
            long long sum = 0;
            for (int x : arr) sum += min(x, cap);
            return sum;
        };
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (sumWithCap(mid) < target) lo = mid + 1;
            else hi = mid;
        }
        long long sumLo = sumWithCap(lo);
        long long sumLoMinus1 = sumWithCap(lo - 1);
        if (abs(sumLo - target) < abs(sumLoMinus1 - target)) return lo;
        return lo - 1;
    }
};
