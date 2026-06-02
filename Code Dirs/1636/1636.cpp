// Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> frequencySort(vector<int> &nums)
    {
        map<int, int> mp;
        for (int x : nums)
            mp[x]++;

        vector<pair<int, int>> v; // create a vector of pairs (number, frequency)

        for (auto &[x, f] : mp) // create a vector of pairs (number, frequency)
            v.emplace_back(x, f);

        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.second == b.second)
                     return a.first > b.first; // If frequencies are equal, sort by number in descending order
                 return a.second < b.second;   // Otherwise, sort by frequency in ascending order
             });

        vector<int> res;

        for (auto &[x, f] : v)
            res.insert(res.end(), f, x); // Insert the number 'x' into the result vector 'f' times

        return res;
    }
};
