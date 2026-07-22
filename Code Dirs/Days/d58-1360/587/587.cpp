// Link: https://leetcode.com/problems/erect-the-fence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) + O(n) + O(n) = O(nlogn)
    // SC: O(n)
    // Approach:
    // 1. Sort the points based on x and y coordinates.
    // 2. Use the concept of convex hull to find the outer points.
    // 3. Use two deques to store the lower and upper hulls.
    // 4. For each point, check if it is part of the lower or upper hull using the cross product.
    // 5. Finally, combine the points from both hulls and return the unique points as the result.
    int findEquationValue(pair<int, int> &P1, pair<int, int> &P2, pair<int, int> P3)
    {

        int x1 = P1.first;
        int x2 = P2.first;
        int x3 = P3.first;

        int y1 = P1.second;
        int y2 = P2.second;
        int y3 = P3.second;

        return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
    }
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        sort(trees.begin(), trees.end());
        vector<vector<int>> res;
        deque<pair<int, int>> lower, upper;

        for (auto &point : trees)
        {
            int l = lower.size();
            int u = upper.size();
            while (l >= 2 && findEquationValue(lower[l - 2], lower[l - 1], {point[0], point[1]}) < 0)
            {
                l--;
                lower.pop_back();
            }
            while (u >= 2 && findEquationValue(upper[u - 2], upper[u - 1], {point[0], point[1]}) > 0)
            {
                u--;
                upper.pop_back();
            }
            lower.push_back({point[0], point[1]});
            upper.push_back({point[0], point[1]});
        }

        set<pair<int, int>> temp;
        for (auto &it : upper)
        {
            temp.insert(it);
        }
        for (auto &it : lower)
        {
            temp.insert(it);
        }

        for (auto &it : temp)
        {
            res.push_back({it.first, it.second});
        }

        return res;
    }
};