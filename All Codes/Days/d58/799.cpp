// Link: https://leetcode.com/problems/champagne-tower/description/

#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // TC: O(query_row^2), where query_row is the number of rows in the champagne tower.
    // SC: O(query_row^2), for storing the amount of champagne in each glass in the dp array.
    // Approach:
    // 1. We create a 2D vector dp to represent the amount of champagne in each glass. The size of the dp vector is (query_row + 2) x (query_row + 2) to accommodate the maximum number of rows and glasses we might need to consider.
    // 2. We initialize the top glass (dp[0][0]) with the poured amount of champagne.
    // 3. We iterate through each row and each glass in that row. If the amount of champagne in a glass exceeds 1, we calculate the overflow and distribute it equally to the two glasses directly below it (dp[r + 1][c] and dp[r + 1][c + 1]) and set the current glass to 1 (the maximum capacity).
    // 4. Finally, we return the amount of champagne in the specified glass (dp[query_row][query_glass]).
    double champagneTower(int poured, int query_row, int query_glass)
    {
        // Tạo bảng dp với kích thước đủ chứa tới query_row + 1
        vector<vector<double>> dp(query_row + 2, vector<double>(query_row + 2, 0.0));

        dp[0][0] = poured;

        for (int r = 0; r <= query_row; ++r)
        {
            for (int c = 0; c <= r; ++c)
            {
                // Nếu lượng sâm-panh trong ly lớn hơn 1, nó sẽ tràn xuống dưới
                if (dp[r][c] > 1.0)
                {
                    double overflow = (dp[r][c] - 1.0) / 2.0;
                    dp[r + 1][c] += overflow;
                    dp[r + 1][c + 1] += overflow;
                    dp[r][c] = 1.0; // Sức chứa tối đa của ly là 1
                }
            }
        }

        return dp[query_row][query_glass];
    }
};