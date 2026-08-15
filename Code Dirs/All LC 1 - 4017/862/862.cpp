// Link: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        deque<int> dq;
        int best = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                best = min(best, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefix[dq.back()] >= prefix[i]) dq.pop_back();
            dq.push_back(i);
        }
        return best == INT_MAX ? -1 : best;
    }
};
