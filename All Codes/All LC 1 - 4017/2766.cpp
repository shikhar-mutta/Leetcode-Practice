// Link: https://leetcode.com/problems/relocate-marbles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    //  Approach:
    //  1. Create an unordered_map to store the counts of marbles at each position
    //  2. Iterate through the nums array and update the counts in the map
    //  3. Iterate through the moveFrom and moveTo arrays, and for each move
    //     update the counts in the map by adding the count of marbles at moveFrom[i] to moveTo[i] and setting the count at moveFrom[i] to 0
    //  4. Create a vector to store the final positions of marbles and iterate through the map, adding the positions with non-zero counts to the vector
    //  5. Sort the vector and return it as the final result
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
    {
        unordered_map<int, int> mp;

        int n = nums.size();

        for (auto &it : nums)
        {
            mp[it]++;
        }

        for (int i = 0; i < moveFrom.size(); i++)
        {
            if (moveFrom[i] == moveTo[i])
                continue;
            mp[moveTo[i]] += mp[moveFrom[i]];
            mp[moveFrom[i]] = 0;
        }
        vector<int> ans;

        for (auto &it : mp)
        {
            if (it.second != 0)
            {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};
