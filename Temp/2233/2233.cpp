// Link: https://leetcode.com/problems/maximum-product-after-k-increments/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while (k-- > 0) {
            int top = pq.top(); pq.pop();
            pq.push(top + 1);
        }
        long long result = 1;
        while (!pq.empty()) {
            result = (result * pq.top()) % MOD;
            pq.pop();
        }
        return (int)result;
    }
};
