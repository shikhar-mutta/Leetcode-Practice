// Link: https://leetcode.com/problems/find-the-maximum-factor-score-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(maxVal)) SC: O(n)
// Approach: factor score of an array = gcd(all) * lcm(all). Removing at most
// one element, try full array + each single-removal (via prefix/suffix
// gcd & lcm arrays combining the two sides around index i), take max.
class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pg(n), pl(n), sg(n), sl(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) { pg[i] = pl[i] = nums[i]; }
            else {
                pg[i] = __gcd(pg[i-1], (long long)nums[i]);
                pl[i] = pl[i-1] / __gcd(pl[i-1], (long long)nums[i]) * nums[i];
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) { sg[i] = sl[i] = nums[i]; }
            else {
                sg[i] = __gcd(sg[i+1], (long long)nums[i]);
                sl[i] = sl[i+1] / __gcd(sl[i+1], (long long)nums[i]) * nums[i];
            }
        }

        long long ans = pg[n-1] * pl[n-1];
        for (int i = 0; i < n; i++) {
            long long g, l;
            long long left_g = (i > 0) ? pg[i-1] : 0;
            long long left_l = (i > 0) ? pl[i-1] : 1;
            long long right_g = (i < n-1) ? sg[i+1] : 0;
            long long right_l = (i < n-1) ? sl[i+1] : 1;
            if (left_g == 0 && right_g == 0) continue; // n == 1, only one element, can't remove
            g = left_g == 0 ? right_g : (right_g == 0 ? left_g : __gcd(left_g, right_g));
            l = left_l / __gcd(left_l, right_l) * right_l;
            ans = max(ans, g * l);
        }
        return ans;
    }
};
