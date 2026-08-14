// Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        vector<long long> leftMinSum(n, 0);
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            if ((int)maxHeap.size() > k) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == k) leftMinSum[i] = sum;
        }

        vector<long long> rightMaxSum(n, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            minHeap.push(nums[i]);
            sum += nums[i];
            if ((int)minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if ((int)minHeap.size() == k) rightMaxSum[i] = sum;
        }

        long long best = LLONG_MAX;
        for (int i = k - 1; i <= 2 * k - 1; i++) {
            best = min(best, leftMinSum[i] - rightMaxSum[i + 1]);
        }
        return best;
    }
};
