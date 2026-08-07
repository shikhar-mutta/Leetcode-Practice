// Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k log k)  SC: O(k)
// Approach: min-heap seeded with (nums1[i], nums2[0]) for each i, pop
// smallest sum, push (nums1[i], nums2[j+1]) to advance that row
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty()) return res;

        auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < (int)nums1.size() && i < k; i++) pq.push({i, 0});

        while (!pq.empty() && (int)res.size() < k) {
            auto [i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if (j + 1 < (int)nums2.size()) pq.push({i, j + 1});
        }
        return res;
    }
};
