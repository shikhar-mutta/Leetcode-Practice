// Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int,int> cnt;
            for (int j = i; j < i + k; j++) cnt[nums[j]]++;
            vector<pair<int,int>> items; // (value, freq)
            for (auto& [v, c] : cnt) items.push_back({v, c});
            sort(items.begin(), items.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
                if (a.second != b.second) return a.second > b.second;
                return a.first > b.first;
            });
            long long sum = 0;
            for (int t = 0; t < min((int)items.size(), x); t++) {
                sum += (long long)items[t].first * items[t].second;
            }
            res.push_back((int)sum);
        }
        return res;
    }
};
