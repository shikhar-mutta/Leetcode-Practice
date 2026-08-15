// Link: https://leetcode.com/problems/mark-elements-on-array-by-performing-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> marked(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});
        long long total = 0;
        for (int x : nums) total += x;

        vector<long long> res;
        for (auto& q : queries) {
            int idx = q[0], k = q[1];
            if (!marked[idx]) {
                marked[idx] = true;
                total -= nums[idx];
            }
            int taken = 0;
            while (taken < k && !pq.empty()) {
                auto [val, i] = pq.top();
                if (marked[i]) { pq.pop(); continue; }
                pq.pop();
                marked[i] = true;
                total -= val;
                taken++;
            }
            res.push_back(total);
        }
        return res;
    }
};
