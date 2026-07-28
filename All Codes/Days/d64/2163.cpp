// Link: https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: n=3m. minPrefix[i] = min possible sum of m smallest elements
// among nums[0..i] (via max-heap of size m, running sum). maxSuffix[i] =
// max possible sum of m largest elements among nums[i..n-1] (via min-heap
// of size m, running sum). Answer = min over split point i in [m-1,2m-1]
// of minPrefix[i] - maxSuffix[i+1].
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 3;
        vector<long long> minPrefix(n, 0);
        priority_queue<int> maxHeap;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            maxHeap.push(nums[i]);
            sum += nums[i];
            if ((int)maxHeap.size() > m) {
                sum -= maxHeap.top();
                maxHeap.pop();
            }
            if ((int)maxHeap.size() == m) minPrefix[i] = sum;
        }
        vector<long long> maxSuffix(n, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap;
        sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            minHeap.push(nums[i]);
            sum += nums[i];
            if ((int)minHeap.size() > m) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if ((int)minHeap.size() == m) maxSuffix[i] = sum;
        }
        long long ans = LLONG_MAX;
        for (int i = m - 1; i <= 2 * m - 1; i++)
            ans = min(ans, minPrefix[i] - maxSuffix[i + 1]);
        return ans;
    }
};
