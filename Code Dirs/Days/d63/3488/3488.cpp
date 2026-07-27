// Link: https://leetcode.com/problems/closest-equal-element-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(max(nums[i]))
// Approach: For each number x, store the last index where it appeared in the array. Then for each query, check the last index of the queried number and calculate the distance to the current index. If the distance is equal to n (the length of the array), it means that the number does not appear in the array, so return -1. Otherwise, return the minimum distance to the closest equal element.
constexpr int MM = 1e6 + 1;
int pos[MM] = {[0 ... MM - 1] = -1};
class Solution
{
public:
    static vector<int> solveQueries(vector<int> &nums, vector<int> &queries)
    {
        const int n = nums.size(), n2 = n * 2;
        int left[n], right[n];
        int xMax = 0;
        for (int i = 0; i < n2; i++)
        {
            const int x = nums[i % n];
            xMax = max(x, xMax);
            if (i >= n)
                left[i - n] = pos[x];
            pos[x] = i - n;
        }
        memset(pos, -1, (xMax + 1) * sizeof(int)); // reset for pos[0...xMax]
        for (int i = n2 - 1; i >= 0; i--)
        {
            const int x = nums[i % n];
            if (i < n)
                right[i] = pos[x];
            pos[x] = i;
        }
        for (int &q : queries)
        {
            int x = q;
            q = (x - left[x] == n) ? -1 : min(x - left[x], right[x] - x);
        }
        // reset for the next testcase
        memset(pos, -1, (xMax + 1) * sizeof(int));
        return queries;
    }
};