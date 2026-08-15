// Link: https://leetcode.com/problems/top-k-frequent-elements/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: bucket sort by frequency (bucket index = frequency, max n),
// collect from highest frequency bucket down until k elements gathered
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for (auto& [val, cnt] : freq) buckets[cnt].push_back(val);

        vector<int> res;
        for (int i = n; i >= 0 && (int)res.size() < k; i--) {
            for (int val : buckets[i]) {
                res.push_back(val);
                if ((int)res.size() == k) break;
            }
        }
        return res;
    }
};
