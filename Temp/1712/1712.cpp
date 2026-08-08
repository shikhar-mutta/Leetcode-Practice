// Link: https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
        long long total = prefix[n];

        long long count = 0;
        for (int i = 1; i <= n - 2; i++) {
            long long s1 = prefix[i];
            if (s1 * 3 > total) break;

            // find smallest j > i such that prefix[j]-s1 >= s1 (s2>=s1)
            int lo = i + 1, hi = n - 1, left = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (prefix[mid] - s1 >= s1) { left = mid; hi = mid - 1; }
                else lo = mid + 1;
            }
            // find largest j such that total-prefix[j] >= prefix[j]-s1 (s3>=s2)
            lo = i + 1; hi = n - 1;
            int right = i;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (total - prefix[mid] >= prefix[mid] - s1) { right = mid; lo = mid + 1; }
                else hi = mid - 1;
            }

            if (right >= left) count = (count + (right - left + 1)) % MOD;
        }
        return (int)count;
    }
};
