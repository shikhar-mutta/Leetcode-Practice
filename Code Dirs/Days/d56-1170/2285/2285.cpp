// Link: https://leetcode.com/problems/maximum-total-importance-of-roads/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of cities.
    // SC: O(n) where n is the number of cities.
    //  Approach:
    //   1. We will create a vector to store the degree of each city.
    //   2. We will iterate through the roads and increment the degree of each city.
    //   3. We will sort the degree vector in ascending order.
    //   4. We will iterate through the degree vector and for each city, we will multiply its degree by its index + 1 and add it to the answer.
    //   5. We will return the answer as the maximum total importance of roads.
    //   6. Finally, we will return the answer as the maximum total importance of roads.
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degree(n, 0);

        for (const auto &edge : roads)
        {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            ans += 1LL * degree[i] * (i + 1);
        }

        return ans;
    }
};