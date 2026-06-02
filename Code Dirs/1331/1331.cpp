// Link: https://leetcode.com/problems/rank-transform-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach 2: using sorting and hashing
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // remove duplicates

        int m = sorted.size();
        unordered_map<int, int> rank; // value -> rank
        for (int i = 0; i < m; i++)
            rank[sorted[i]] = i + 1;

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = rank[arr[i]];
        return ans;
    }

    // approach 1: using map
    // vector<int> arrayRankTransform(vector<int> &arr)
    // {
    //     int n = arr.size();
    //     map<int, vector<int>> arrMap;
    //     for (int i = 0; i < n; i++)
    //     {
    //         arrMap[arr[i]].push_back(i);
    //     }
    //     vector<int> ans(n, 0);
    //     int cnt = 1;

    //     for (auto it : arrMap)
    //     {
    //         for (auto val : it.second)
    //         {
    //             ans[val] = cnt;
    //         }
    //         cnt++;
    //     }
    //     return ans;
    // }
};
