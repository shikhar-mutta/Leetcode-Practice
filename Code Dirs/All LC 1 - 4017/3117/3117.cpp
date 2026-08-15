// Link: https://leetcode.com/problems/minimum-sum-of-values-by-dividing-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>* numsPtr;
    vector<int>* andPtr;
    int n, m;
    const long long INF = LLONG_MAX / 2;
    unordered_map<long long, long long> memo2;

    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        n = nums.size();
        m = andValues.size();
        numsPtr = &nums;
        andPtr = &andValues;
        memo2.clear();
        long long res = solveMemo(0, 0, -1);
        return res >= INF ? -1 : (int)res;
    }

    long long solveMemo(int pos, int k, int runningAnd) {
        auto& nums = *numsPtr;
        auto& andValues = *andPtr;
        if (k == m) return pos == n ? 0 : INF;
        if (pos == n) return INF;
        int newAnd = (runningAnd == -1) ? nums[pos] : (runningAnd & nums[pos]);
        if ((newAnd & andValues[k]) != andValues[k]) return INF;
        long long key = (((long long)pos * 11 + k) << 20) ^ (unsigned int)newAnd;
        auto it = memo2.find(key);
        if (it != memo2.end()) return it->second;
        long long best = INF;
        if (newAnd == andValues[k]) {
            long long r = solveMemo(pos + 1, k + 1, -1);
            if (r < INF) best = min(best, r + nums[pos]);
        }
        long long r2 = solveMemo(pos + 1, k, newAnd);
        best = min(best, r2);
        memo2[key] = best;
        return best;
    }
};
