// Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i + k <= n; i++)
        {
            unordered_map<int, int> cnt;
            for (int j = i; j < i + k; j++)
                cnt[nums[j]]++;
            vector<pair<int, int>> freqs(cnt.begin(), cnt.end());
            sort(freqs.begin(), freqs.end(), [](const pair<int, int> &a, const pair<int, int> &b)
                 {
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first; });
            long long sum = 0;
            for (int t = 0; t < min((int)freqs.size(), x); t++)
                sum += (long long)freqs[t].first * freqs[t].second;
            res.push_back((int)sum);
        }
        return res;
    }
};
