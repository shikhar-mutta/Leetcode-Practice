// Link: https://leetcode.com/problems/minimum-operations-to-form-subsequence-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        long long sum = 0;
        for (int x : nums) sum += x;
        if (sum < target) return -1;

        vector<long long> cnt(35, 0);
        for (int x : nums) cnt[__builtin_ctz(x)]++;

        long long ops = 0;
        for (int i = 0; i < 32; i++) {
            if ((target >> i) & 1) {
                if (cnt[i] == 0) {
                    int j = i + 1;
                    while (cnt[j] == 0) j++;
                    cnt[j]--;
                    for (int l = j; l > i; l--) {
                        ops++;
                        if (l == i + 1) cnt[i] += 2;
                        else cnt[l - 1] += 1;
                    }
                }
                cnt[i]--;
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        return (int)ops;
    }
};
