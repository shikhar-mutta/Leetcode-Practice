// Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        // Create a hash map to store the index of each restaurant in list1
        unordered_map<string, int> mp;
        int n = list1.size();
        for (int i = 0; i < n; i++)
            mp[list1[i]] = i;

        vector<string> res;
        int minSum = INT_MAX, m = list2.size();

        // Iterate through list2 and check if the restaurant is in the hash map
        for (int j = 0; j < m; j++)
        {
            auto it = mp.find(list2[j]);
            if (it == mp.end())
                continue;
            int s = it->second + j;
            // Update the minimum sum and the result list accordingly
            if (s < minSum)
            {
                minSum = s;
                res = {list2[j]};
            }
            else if (s == minSum)
            { // If the sum is equal to the minimum sum, add the restaurant to the result list
                res.push_back(list2[j]);
            }
        }

        return res;
    }
};