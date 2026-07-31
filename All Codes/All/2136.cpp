// Link: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
//  Approach: The problem can be solved by sorting the plants based on their grow time in descending order. We can then iterate through the sorted plants and keep track of the total plant time and the maximum bloom time. The final answer will be the maximum bloom time after all plants have been planted.
class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        int n = plantTime.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++)
        {
            vec[i] = {plantTime[i], growTime[i]};
        }

        // sort according to lamba
        auto lambda = [](pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second > p2.second;
        };

        sort(vec.begin(), vec.end(), lambda);

        int prevPlantDays = 0;
        int maxBloomDays = 0;

        for (int i = 0; i < n; i++)
        {
            int currPlantTime = vec[i].first;
            int currGrowTime = vec[i].second;

            prevPlantDays += currPlantTime;

            int currBloomTime = prevPlantDays + currGrowTime;
            maxBloomDays = max(maxBloomDays, currBloomTime);
        }
        return maxBloomDays;
    }
};
