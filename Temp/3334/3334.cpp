// Link: https://leetcode.com/problems/find-the-maximum-factor-score-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return (long long)nums[0] * nums[0];

        vector<long long> prefGcd(n), prefLcm(n), sufGcd(n), sufLcm(n);
        prefGcd[0] = nums[0]; prefLcm[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefGcd[i] = __gcd(prefGcd[i-1], (long long)nums[i]);
            prefLcm[i] = prefLcm[i-1] / __gcd(prefLcm[i-1], (long long)nums[i]) * nums[i];
        }
        sufGcd[n-1] = nums[n-1]; sufLcm[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            sufGcd[i] = __gcd(sufGcd[i+1], (long long)nums[i]);
            sufLcm[i] = sufLcm[i+1] / __gcd(sufLcm[i+1], (long long)nums[i]) * nums[i];
        }

        long long best = prefGcd[n-1] * prefLcm[n-1]; // no removal
        for (int i = 0; i < n; i++) {
            long long g, l;
            if (i == 0) { g = sufGcd[1]; l = sufLcm[1]; }
            else if (i == n-1) { g = prefGcd[n-2]; l = prefLcm[n-2]; }
            else {
                g = __gcd(prefGcd[i-1], sufGcd[i+1]);
                l = prefLcm[i-1] / __gcd(prefLcm[i-1], sufLcm[i+1]) * sufLcm[i+1];
            }
            best = max(best, g * l);
        }
        return best;
    }
};
