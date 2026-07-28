// Link: https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(N)
//  Approach: for three indices i<j<k, sum of pairwise distances
//  (j-i)+(k-j)+(k-i) simplifies to 2*(k-i), independent of the middle
//  index. So for each value, only the first and last of a consecutive
//  triple of its occurrences matter; scan each value's occurrence list
//  with a window of 3 and take the minimum span, then double it.
//  We use a static array to store the last two occurrences of each value
//  and reset it after each test case.
const int N = 1e5 + 1;
int pos[N][2] = {[0 ... N - 1][0 ... 1] = -1};
class Solution
{
public:
    static int minimumDistance(vector<int> &nums)
    {
        const int n = nums.size();
        int ans = INT_MAX, M = 0;
        for (int k = 0; k < n; k++)
        {
            const int x = nums[k];
            M = max(M, x);
            if (pos[x][1] != -1)
            {
                ans = min(ans, (k - pos[x][1]) << 1);
            }
            pos[x][1] = exchange(pos[x][0], k);
        }
        memset(pos, -1, sizeof(int) * 2 * (M + 1));
        return ans == INT_MAX ? -1 : ans;
    }
};