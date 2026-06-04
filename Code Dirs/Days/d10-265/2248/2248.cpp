// Link: https://leetcode.com/problems/intersection-of-multiple-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Use Frequency Array.
    // TC: O(N * M) where M is the average length of the arrays.
    // SC: O(1001) since the numbers are in the range [1, 1000].
    vector<int> intersection(vector<vector<int>> &nums)
    {
        vector<int> temp(1001, 0);
        vector<int> ans;
        for (auto temp1 : nums)
        {
            for (int x : temp1)
            {
                temp[x]++;
            }
        }

        // Number of arrays
        int n = nums.size();

        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] == n)
                ans.push_back(i);
        }
        return ans;
    }

    // Approach 2: Use HashMap.
    // TC: O(N * M log M) where M is the average length of the arrays.
    // SC: O(N * M)
    vector<int> intersection(vector<vector<int>> &nums)
    {
        vector<int> ans;
        unordered_map<int, int> mp; // to count the frequency of each number
        int n = nums.size();        // number of arrays

        for (const auto &arr : nums)
            for (int num : arr)
                mp[num]++; // increment the count for this number

        for (const auto &[num, count] : mp)
            if (count == n)
                ans.push_back(num);

        sort(ans.begin(), ans.end()); // sort the result in ascending order
        return ans;
    }
};
