// Link: https://leetcode.com/problems/number-of-subarrays-with-and-value-of-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        vector<pair<int,long long>> prev; // (andValue, count)
        long long ans = 0;
        for (int x : nums) {
            vector<pair<int,long long>> cur;
            cur.push_back({x, 1});
            for (auto& [v, c] : prev) {
                int nv = v & x;
                if (!cur.empty() && cur.back().first == nv) cur.back().second += c;
                else cur.push_back({nv, c});
            }
            // merge duplicates properly (since prev entries have distinct AND values in decreasing... actually may not be sorted)
            vector<pair<int,long long>> merged;
            unordered_map<int,long long> mp;
            for (auto& [v, c] : cur) mp[v] += c;
            for (auto& [v, c] : mp) {
                merged.push_back({v, c});
                if (v == k) ans += c;
            }
            prev = merged;
        }
        return ans;
    }
};
