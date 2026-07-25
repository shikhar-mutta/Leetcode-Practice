// Link: https://leetcode.com/problems/maximum-product-after-k-increments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n + k log n)
// SC: O(n)
// Approach: greedily spend each of the k increments on the current
// smallest element (a min-heap keeps it at the top) - raising the smallest
// value always yields at least as much product gain as raising any larger
// one, since it's the tightest bottleneck. After exhausting k increments,
// multiply everything together mod 1e9+7.
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),
                                                          nums.end());

        while (k--) {
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest + 1);
        }

        long long product = 1;
        while (!pq.empty()) {
            product = product * pq.top() % MOD;
            pq.pop();
        }
        return (int)product;
    }
};
