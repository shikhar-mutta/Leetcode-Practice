// Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(sum/k))
// SC: O(1)
// Approach: binary search the answer - the max candies per child. For a
// candidate amount mid, feasibility means summing floor(pile/mid) over all
// piles gives at least k children served; this check is monotonic (larger
// mid can only serve fewer or equal children), so binary search the
// largest feasible mid between 1 and sum/k (an upper bound, since serving
// k children needs at least k*mid total candies).
class Solution {
public:
    bool check(vector<int>& candies, int k, long long mid) {
        long long curr = 0;
        for (auto it : candies) {
            curr += (it / mid);
        }
        if (curr >= k)
            return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1;
        long long right = accumulate(candies.begin(), candies.end(), 0LL) / k;
        long long ans = 0;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(candies, k, mid)) {
                ans = mid;
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};
