// Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> pq(nums.begin(), nums.end());
        int ops = 0;
        while (pq.size() > 1 && pq.top() < k) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            pq.push(a * 2 + b);
            ops++;
        }
        return ops;
    }
};
