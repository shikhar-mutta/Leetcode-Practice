// Link: https://leetcode.com/problems/watering-plants/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the number of plants in the input array plants.
// SC: O(1), as we are using a constant amount of extra space.
//   Approach:
//    1. We will iterate through the input array plants and for each index i, we will check if the current capacity of the watering can is greater than or equal to the water required for the current plant.
//   2. If it is, we will subtract the water required for the current plant from the capacity and increment the answer by 1.
//   3. If it is not, we will refill the watering can to its full capacity and subtract the water required for the current plant from the capacity. We will also increment the answer by (2 * i) + 1, as we need to go back to the river and then return to the current plant.
//   4. Finally, we will return the answer, which represents the total number of steps taken to water all the plants.
class Solution
{
public:
    int wateringPlants(vector<int> &plants, int capacity)
    {
        int ans = 0;
        int t = capacity;
        for (int i = 0; i < plants.size(); i++)
        {
            if (capacity >= plants[i])
            {
                capacity -= plants[i];
                ans++;
            }
            else
            {
                capacity = t - plants[i];
                ans += (2 * i) + 1;
            }
        }
        return ans;
    }
};