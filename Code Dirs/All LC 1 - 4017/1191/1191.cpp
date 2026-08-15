// Link: https://leetcode.com/problems/k-concatenation-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long long MOD = 1e9 + 7;
        auto kadane = [](vector<int>& a) {
            long long best = 0, cur = 0;
            for (int x : a) {
                cur = max((long long)x, cur + x);
                best = max(best, cur);
            }
            return best;
        };

        long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
        long long oneCopy = kadane(arr);
        if (k == 1) return (int)(oneCopy % MOD);

        vector<int> twoArr = arr;
        twoArr.insert(twoArr.end(), arr.begin(), arr.end());
        long long twoCopy = kadane(twoArr);

        long long best = twoCopy;
        if (totalSum > 0) {
            best = max(best, twoCopy + (k - 2) * totalSum);
        }
        return (int)(best % MOD);
    }
};
