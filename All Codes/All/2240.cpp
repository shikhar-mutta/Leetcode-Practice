// Link: https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(min(cost1, cost2))) via the Euclidean-like floor_sum recursion
// SC: O(log(min(cost1, cost2))) recursion depth
// Approach: for each of the n = total/cost1 + 1 possible pen counts p (0
// to max_pens), the number of pencil choices is floor((total - p*cost1) /
// cost2) + 1, so the answer is n + sum_{p=0}^{n-1} floor((A*p + B) / cost2)
// where A = -cost1, B = total%cost1 (using total%cost1 as an equivalent
// numerator via floorSum(n, cost2, cost1, total%cost1), reframing the
// subtraction as floor_sum's standard form). floorSum computes
// sum_{i=0}^{n-1} floor((a*i+b)/m) in O(log) time via the classic
// Euclidean-algorithm-style identity (peel off a/m and b/m as bulk
// contributions, then recurse on the swapped, reduced problem) - the same
// technique used to sum floor-division arithmetic progressions in
// competitive programming (e.g. AtCoder Library's floor_sum).
class Solution {
private:
    long long floorSum(long long n, long long m, long long a, long long b) {
        long long ans = 0;
        if (a >= m) {
            ans += (n - 1) * n / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        long long y_max = (a * n + b) / m;
        long long x_max = y_max * m - b;
        if (y_max == 0)
            return ans;

        ans += (n - (x_max + a - 1) / a) * y_max;
        ans += floorSum(y_max, a, m, (a - x_max % a) % a);
        return ans;
    }

public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long max_pens = total / cost1;
        long long n = max_pens + 1;
        return floorSum(n, cost2, cost1, total % cost1) + n;
    }
};
