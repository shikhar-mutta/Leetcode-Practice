// Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void genSums(vector<int>& arr, vector<vector<long long>>& byCount) {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            long long sum = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) sum += arr[i];
            byCount[cnt].push_back(sum);
        }
        for (auto& v : byCount) sort(v.begin(), v.end());
    }

    int minimumDifference(vector<int>& nums) {
        int total2n = nums.size();
        int n = total2n / 2;
        vector<int> A(nums.begin(), nums.begin() + n);
        vector<int> B(nums.begin() + n, nums.end());
        long long total = accumulate(nums.begin(), nums.end(), 0LL);

        vector<vector<long long>> sumsA(n + 1), sumsB(n + 1);
        genSums(A, sumsA);
        genSums(B, sumsB);

        long long best = LLONG_MAX;
        for (int k = 0; k <= n; k++) {
            auto& listB = sumsB[n - k];
            for (long long sa : sumsA[k]) {
                long long target = total - 2 * sa; // minimize |target - 2*sb|
                auto it = lower_bound(listB.begin(), listB.end(), target,
                    [](long long sb, long long tgt) { return 2 * sb < tgt; });
                for (int off = -1; off <= 0; off++) {
                    auto it2 = it + off;
                    if (it2 >= listB.begin() && it2 < listB.end()) {
                        long long val = llabs(2 * (sa + *it2) - total);
                        best = min(best, val);
                    }
                }
            }
        }
        return (int)best;
    }
};
