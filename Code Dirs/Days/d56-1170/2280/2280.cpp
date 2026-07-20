// Link: https://leetcode.com/problems/minimum-lines-to-represent-a-line-chart/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of stock prices.
    // SC: O(n) where n is the number of stock prices.
    //  Approach:
    //  1. We will sort the stock prices based on the day.
    //  2. We will iterate through the stock prices and check if the slope of the line formed by the current point and the next point is equal to the slope of the line formed by the next point and the point after that.
    //  3. If the slopes are not equal, we will increment the count of lines.
    //  4. Finally, we will return the count of lines as the minimum number of lines to represent the line chart.
    //  5. We will use long long to avoid integer overflow when calculating the slopes.

    int minimumLines(vector<vector<int>> &stockPrices)
    {
        vector<pair<int, int>> p;
        for (int i = 0; i < stockPrices.size(); i++)
            p.push_back({stockPrices[i][0], stockPrices[i][1]});
        sort(p.begin(), p.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 return a.first < b.first;
             });
        if (p.size() <= 2)
            return p.size() - 1;
        int cnt = 1;
        for (int i = 0; i < p.size() - 2; i++)
        {
            long long x1 = p[i + 1].second - p[i].second;
            long long x2 = p[i + 2].first - p[i + 1].first;
            long long y1 = p[i + 2].second - p[i + 1].second;
            long long y2 = p[i + 1].first - p[i].first;
            if (x1 * x2 != y1 * y2)
                cnt++;
        }
        return cnt;
    }
};