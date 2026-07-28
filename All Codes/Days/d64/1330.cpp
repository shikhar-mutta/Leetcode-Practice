// Link: https://leetcode.com/problems/reverse-subarray-to-maximize-array-value/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: reversing subarray [i,j] only changes the two boundary
// edges. Boundary reversals (i=0 or j=n-1) are checked directly in
// O(n). For fully interior reversals, using the identity
// |x|+|y| = max(|x+y|,|x-y|), the best combined gain over any two edges
// (a,b) and (c,d) reduces to max(maxX-minY, maxP-minQ) where, per edge,
// X=sum-|diff|, Y=sum+|diff|, P=diff-|diff|, Q=diff+|diff| — each
// computable via a single pass.
class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n = nums.size();
        long long base = 0;
        for (int i = 0; i < n - 1; i++) base += abs(nums[i] - nums[i + 1]);

        long long ans = base;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, base + abs((long long)nums[0] - nums[i + 1]) - abs((long long)nums[i] - nums[i + 1]));
            ans = max(ans, base + abs((long long)nums[n - 1] - nums[i]) - abs((long long)nums[i] - nums[i + 1]));
        }

        if (n >= 3) {
            long long maxX = LLONG_MIN, minY = LLONG_MAX, maxP = LLONG_MIN, minQ = LLONG_MAX;
            for (int k = 0; k < n - 1; k++) {
                long long a = nums[k], b = nums[k + 1];
                long long E = abs(a - b), S = a + b, D = a - b;
                maxX = max(maxX, S - E);
                minY = min(minY, S + E);
                maxP = max(maxP, D - E);
                minQ = min(minQ, D + E);
            }
            long long delta = max(maxX - minY, maxP - minQ);
            ans = max(ans, base + delta);
        }
        return (int)ans;
    }
};
