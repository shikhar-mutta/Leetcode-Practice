// Link: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * log(max_sum - min_sum))  SC: O(1)
// Approach: Use binary search to find the kth smallest sum. The minimum possible sum is the sum of the first elements of each row, and the maximum possible sum is the sum of the last elements of each row. For each mid value, count how many sums are less than or equal to mid using a recursive function. If the count is greater than or equal to k, search in the left half; otherwise, search in the right half.
class Solution
{
public:
    int c(vector<vector<int>> &mat, int v, int low, int mid, int k)
    {
        if (low > mid)
        {
            return 0;
        }
        if (v == mat.size())
            return 1;

        int ans = 0;

        for (int i = 0; i < mat[0].size(); i++)
        {
            int ns = low - mat[v][0] + mat[v][i];
            if (ns > mid)
                break;

            ans += c(mat, v + 1, ns, mid, k);
            if (ans >= k)
                return k;
        }

        return ans;
    }
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        int m = mat[0].size();
        int l = 0, h = 0;

        for (int i = 0; i < n; i++)
        {
            l += mat[i][0];
            h += mat[i][m - 1];
        }
        int b = l;

        while (l < h)
        {

            int m = (h - l) / 2 + l;

            if (c(mat, 0, b, m, k) >= k)
            {
                h = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};