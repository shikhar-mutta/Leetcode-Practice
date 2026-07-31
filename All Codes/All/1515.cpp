// Link: https://leetcode.com/problems/best-position-for-a-service-centre/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*log(n)) SC: O(1)
//  Approach: We can use gradient descent to find the optimal position for the service center. We can start from the centroid of the given positions and iteratively move in the direction of the steepest descent until we reach a local minimum. We can use a small step size to ensure that we converge to the global minimum. Finally, we can return the minimum distance sum.
class Solution
{
public:
    double getDist(vector<vector<int>> &positions, double x, double y)
    {
        double sum = 0.0;
        for (auto &p : positions)
        {
            double dx = x - p[0];
            double dy = y - p[1];
            sum += sqrt(dx * dx + dy * dy);
        }
        return sum;
    }

    double getMinDistSum(vector<vector<int>> &positions)
    {
        double x = 0.0, y = 0.0;

        // Start from centroid
        for (auto &p : positions)
        {
            x += p[0];
            y += p[1];
        }

        x /= positions.size();
        y /= positions.size();

        double step = 100.0;
        double ans = getDist(positions, x, y);

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (step > 1e-6)
        {
            bool improved = false;

            for (auto &d : dir)
            {
                double nx = x + step * d.first;
                double ny = y + step * d.second;

                double cur = getDist(positions, nx, ny);

                if (cur < ans)
                {
                    ans = cur;
                    x = nx;
                    y = ny;
                    improved = true;
                    break;
                }
            }

            if (!improved)
                step *= 0.5;
        }

        return ans;
    }
};