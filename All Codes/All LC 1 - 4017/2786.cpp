// Link: https://leetcode.com/problems/visit-array-positions-to-maximize-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: track the best running score ending on an even-parity element
// (`even`) and on an odd-parity element (`odd`) so far. For each new nums[i],
// it can either extend a same-parity running score for free, or extend the
// opposite-parity score paying the penalty x — take whichever is better and
// add nums[i]. Answer is the best of the two final scores (the first element
// is always visited for free, seeding whichever parity it has).
class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {

        long long even = LLONG_MIN;
        long long odd = LLONG_MIN;

        if (nums[0] % 2 == 0)
            even = nums[0];
        else
            odd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                long long takeSame = even;
                long long takeDiff = (odd == LLONG_MIN) ? LLONG_MIN : odd - x;
                even = max(takeSame, takeDiff) + nums[i];
            } else {
                long long takeSame = odd;
                long long takeDiff = (even == LLONG_MIN) ? LLONG_MIN : even - x;
                odd = max(takeSame, takeDiff) + nums[i];
            }
        }

        return max(even, odd);
    }
};
