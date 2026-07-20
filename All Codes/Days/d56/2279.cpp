// Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of bags.
    // SC: O(1) where n is the number of bags.
    // Approach:
    //   1. We will calculate the remaining capacity of each bag by subtracting the number of rocks in the bag from the capacity of the bag.
    //   2. We will sort the remaining capacities in ascending order.
    //   3. We will iterate through the sorted remaining capacities and keep adding the remaining capacities to the additional rocks until we run out of additional rocks
    //   4. We will return the number of bags that we were able to fill completely with the additional rocks.
    int maximumBags(std::vector<int> &capacity, std::vector<int> &rocks, int additionalRocks)
    {
        const int n = capacity.size();
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            capacity[i] -= rocks[i];
            sum += capacity[i];
        }
        if (sum <= additionalRocks)
            return n;
        std::sort(capacity.begin(), capacity.end());
        int ret = 0;
        for (int c : capacity)
        {
            additionalRocks -= c;
            if (additionalRocks < 0)
                return ret;
            ++ret;
        }
        return ret;
    }
};
