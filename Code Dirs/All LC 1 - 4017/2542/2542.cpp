// Link: https://leetcode.com/problems/maximum-subsequence-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums2[a] > nums2[b]; });

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long sum = 0;
        long long best = 0;
        for (int i : idx) {
            minHeap.push(nums1[i]);
            sum += nums1[i];
            if ((int)minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }
            if ((int)minHeap.size() == k) {
                best = max(best, sum * nums2[i]);
            }
        }
        return best;
    }
};
