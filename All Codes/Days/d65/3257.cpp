// Link: https://leetcode.com/problems/maximum-value-sum-by-placing-three-rooks-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) where m is the number of rows and n is the number of columns in board
// SC: O(m*n) where m is the number of rows and n is the number of columns in board
// Approach: We can use dynamic programming to keep track of the maximum value sum that can be obtained by placing three rooks on the board. We can use a dp array where dp[i][j] represents the maximum value sum that can be obtained by placing rooks on the first i rows and j columns of the board. We can initialize dp[0][0] = 0 since there is no value sum that can be obtained by placing rooks on the first row and column. For each subsequent row and column, we can update dp[i][j] based on the previous rows and columns. If we place a rook on the current row and column, we can add the value of the current cell to dp[i-1][j-1] since we can obtain the maximum value sum by placing rooks on the previous rows and columns. If we do not place a rook on the current row and column, we can take the maximum value sum from the previous rows and columns. Finally, we can return dp[m][n] as the result.
struct top3
{
    array<pair<int, int>, 3> t;
    top3() { t.fill({0, INT_MIN}); }
    void insert(int i, int x)
    {
        auto p = make_pair(i, x);
        if (x >= t[2].second)
        {
            t[0] = t[1];
            t[1] = t[2];
            t[2] = p;
        }
        else if (x >= t[1].second)
        {
            t[0] = t[1];
            t[1] = p;
        }
        else if (x > t[0].second)
        {
            t[0] = p;
        }
    }
};
class Solution
{
public:
    long long maximumValueSum(vector<vector<int>> &board)
    {
        const int M = board.size();
        const int N = board[0].size();
        vector<top3> columns(N);
        vector<tuple<int, int, int>> vals;
        for (auto [i, row] : views::enumerate(board))
        {
            top3 t;
            for (auto [j, x] : views::enumerate(row))
            {
                t.insert(j, x);
            }
            for (auto [j, x] : t.t)
            {
                columns[j].insert(i, x);
            }
        }
        for (auto [j, t] : views::enumerate(columns))
        {
            for (auto [i, x] : t.t | views::reverse)
            {
                if (x == INT_MIN)
                {
                    break;
                }
                vals.emplace_back(x, i, j);
            }
        }
        auto extract_val_from_mask = [&](unsigned int &mask)
        {
            int i = bit_width(mask) - 1;
            mask ^= (1 << i);
            return vals[i];
        };
        auto extract_sum = [&](unsigned int mask) -> optional<long long>
        {
            if (popcount(mask) != 3)
            {
                return nullopt;
            }
            auto [x1, i1, j1] = extract_val_from_mask(mask);
            auto [x2, i2, j2] = extract_val_from_mask(mask);
            auto [x3, i3, j3] = extract_val_from_mask(mask);
            if (i1 != i2 && i2 != i3 && i1 != i3 && j1 != j2 && j2 != j3 &&
                j1 != j3)
            {
                return static_cast<long long>(x1) + x2 + x3;
            }
            return nullopt;
        };
        const int m = min(static_cast<int>(vals.size()), 11);
        assert(m >= 3);
        ranges::partial_sort(vals, vals.begin() + m, greater<void>{});
        optional<long long> ans;
        for (int mask = 0; mask < (1 << m); mask++)
        {
            ans = max(ans, extract_sum(mask));
        }
        return ans.value();
    }
};
