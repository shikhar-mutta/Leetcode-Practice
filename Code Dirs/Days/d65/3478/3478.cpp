// Link: https://leetcode.com/problems/choose-k-elements-with-maximum-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums1[a] < nums1[b]; });

        vector<long long> ans(n, 0);
        priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap of size k
        long long curSum = 0;

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && nums1[idx[j]] == nums1[idx[i]]) j++;
            for (int t = i; t < j; t++) ans[idx[t]] = curSum;
            for (int t = i; t < j; t++) {
                int v = nums2[idx[t]];
                minHeap.push(v);
                curSum += v;
                if ((int)minHeap.size() > k) {
                    curSum -= minHeap.top();
                    minHeap.pop();
                }
            }
            i = j;
        }

        return ans;
    }
};
