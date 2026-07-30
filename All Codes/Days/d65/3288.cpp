// Link: https://leetcode.com/problems/length-of-the-longest-increasing-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the nums array
// SC: O(n^2) where n is the length of the nums array
// Approach: We can use dynamic programming to solve this problem. We can create a 2D array dp where dp[i][j] represents the maximum xor score of the subarray nums[i...j]. We can fill the dp array by iterating through all possible subarrays and calculating the maximum xor score for each subarray. Finally, we can return the maximum xor score for each query by accessing the dp array.

#define all(a) (a).begin(), (a).end()
class Solution
{
public:
    int maxPathLength(vector<vector<int>> &coordinates, int k)
    {
        auto cmp = [&](auto &a, auto &b)
        {
            if (a.first != b.first)
                return a.first < b.first;

            return a.second > b.second;
        };

        vector<pair<int, int>> left, right;

        int x = coordinates[k][0], y = coordinates[k][1];

        for (auto &p : coordinates)
        {
            int x_ = p[0], y_ = p[1];

            if (x_ < x && y_ < y)
                left.emplace_back(x_, y_);

            else if (x_ > x && y_ > y)
                right.emplace_back(x_, y_);
        }

        sort(all(left), cmp);
        sort(all(right), cmp);

        return lis(left) + 1 + lis(right);
    }

private:
    int lis(vector<pair<int, int>> &A)
    {
        vector<int> l;

        for (auto &[x, y] : A)
        {
            auto it = lower_bound(all(l), y);

            if (it == l.end())
                l.push_back(y);

            else
                *it = y;
        }

        return l.size();
    }
};
