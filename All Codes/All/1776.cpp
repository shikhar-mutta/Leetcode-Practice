// Link: https://leetcode.com/problems/car-fleet-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of cars
// SC: O(n) where n is the number of cars
// Approach: We can use a stack to keep track of the cars that are still on the road. We will iterate through the cars from right to left and for each car, we will check if it will collide with the car in front of it. If it will, we will calculate the time it will take for the collision to happen and store it in the answer array. If it will not collide, we will pop the car from the stack and continue checking with the next car in the stack. We will continue this process until we have checked all the cars. Finally, we will return the answer array.
class Solution
{
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars)
    {
        int n = cars.size();
        vector<double> ans(n, -1.0);
        vector<int> stk; // indices, monotonic
        for (int i = n - 1; i >= 0; i--)
        {
            long long p = cars[i][0], s = cars[i][1];
            while (!stk.empty())
            {
                int j = stk.back();
                long long p2 = cars[j][0], s2 = cars[j][1];
                if (s <= s2)
                {
                    stk.pop_back();
                    continue;
                }
                double t = (double)(p2 - p) / (s - s2);
                if (ans[j] > 0 && t > ans[j])
                {
                    stk.pop_back();
                    continue;
                }
                break;
            }
            if (stk.empty())
                ans[i] = -1.0;
            else
            {
                int j = stk.back();
                long long p2 = cars[j][0], s2 = cars[j][1];
                ans[i] = (double)(p2 - p) / (s - s2);
            }
            stk.push_back(i);
        }
        return ans;
    }
};
