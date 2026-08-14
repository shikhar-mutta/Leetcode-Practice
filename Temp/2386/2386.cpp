// Link: https://leetcode.com/problems/find-the-k-sum-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long maxSum = 0;
        for (int &x : nums) {
            if (x >= 0) maxSum += x;
            else x = -x;
        }
        sort(nums.begin(), nums.end());

        priority_queue<pair<long long,int>> pq;
        pq.push({maxSum, 0});
        for (int i = 1; i < k; i++) {
            auto [sum, idx] = pq.top(); pq.pop();
            if (idx < (int)nums.size()) {
                pq.push({sum - nums[idx], idx + 1});
                if (idx > 0) pq.push({sum - nums[idx] + nums[idx-1], idx + 1});
            }
        }
        return pq.top().first;
    }
};
