// Link: https://leetcode.com/problems/coordinate-with-maximum-network-quality/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the number of towers.
// SC: O(n) for storing the result and the deque.
//  Approach:
//         1. Sort the towers based on their x-coordinates.
//         2. Use a sliding window approach to find the optimal coordinate.
//         3. For each potential coordinate, calculate the network quality by considering all towers within the radius.
//         4. Return the coordinate with the maximum network quality.
class Solution
{
public:
    vector<int> bestCoordinate(vector<vector<int>> &t, int radius)
    {
        sort(t.begin(), t.end());
        int n = t.size();
        deque<int> dq;
        int tid = 0, max_x = 0, max_y = 0, max_q = 0;
        for (int i = 0; i < n; i++)
        {
            int x = t[i][0];
            while (tid < n && x + radius >= t[tid][0])
                dq.push_back(tid++);
            while (!dq.empty() && t[dq.front()][0] < x - radius)
                dq.pop_front();
            for (int y = 0; y <= 50; y++)
            {
                int q = 0;
                for (auto id : dq)
                {
                    if (t[id][1] < y - radius || t[id][1] > y + radius)
                        continue;
                    auto dd = (t[id][0] - x) * (t[id][0] - x) +
                              (t[id][1] - y) * (t[id][1] - y);
                    if (dd <= radius * radius)
                        q += t[id][2] / (1 + sqrt(dd));
                }
                if (max_q < q)
                {
                    max_q = q;
                    max_x = x;
                    max_y = y;
                }
            }
        }
        return {max_x, max_y};
    }
};
