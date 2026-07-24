// Link: https://leetcode.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q), SC: O(n)
//   Approach:
//     1. We can use a prefix sum array to calculate the total number of candies of each type.
//     2. For each query, we can check if it is possible to eat the favorite candy on the favorite day by checking if the total number of candies of the favorite type is greater than or equal to the number of days multiplied by the maximum number of candies that can be eaten per day.
//     3. We can also check if the total number of candies of the favorite type is less than or equal to the number of days multiplied by the minimum number of candies that can be eaten per day.
//  Note: We need to check both conditions to ensure that it is possible to eat the favorite candy on the favorite day.
class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount,
                        vector<vector<int>> &queries)
    {

        long long i, type, day, atmost, n = candiesCount.size(),
                                        q = queries.size();

        vector<long long> sum(n);
        vector<bool> ans;

        sum[0] = candiesCount[0];
        for (i = 1; i < n; i++)
            sum[i] = sum[i - 1] + candiesCount[i];

        for (i = 0; i < q; i++)
        {
            type = queries[i][0];
            day = queries[i][1];
            atmost = queries[i][2];

            if ((day + 1) * atmost > (type == 0 ? 0 : sum[type - 1]) &&
                sum[type] >= (day + 1) * 1)
                ans.push_back(1);
            else
                ans.push_back(0);
        }

        return ans;
    }
};
