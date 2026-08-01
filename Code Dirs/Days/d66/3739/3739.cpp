// Link: https://leetcode.com/problems/count-subarrays-with-majority-element-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: map target -> +1, everything else -> -1, and take prefix sums
//  P[0..n] (P[0]=0). A subarray (i,j] has target as a strict majority iff
//  P[j] - P[i] > 0, i.e. P[j] > P[i]. So the answer is the number of pairs
//  i<j with P[j] > P[i], counted via a Fenwick tree over coordinate- compressed prefix values: process prefixes left to right, for each add
//  the count of previously inserted values strictly less than it, then
//  insert it.
constexpr int N = 2e5 + 2;
long long cntB[N], bias;
class Solution
{
public:
    static long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        bias = nums.size() + 1;
        int balance = bias;
        memset(cntB, 0, (2 * bias) * sizeof(long long));
        ;
        cntB[balance] = 1;
        long long ans = 0, sum = 0;

        for (int x : nums)
        {
            bool isT = x == target;
            sum += (-isT & cntB[balance]) - (-!isT & cntB[balance - 1]);
            balance += (isT << 1) - 1;
            cntB[balance]++;
            ans += sum;
        }
        return ans;
    }
};
auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();