// Link: https://leetcode.com/problems/create-maximum-number/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * (m+n)^2)  SC: O(m+n)
// Approach: for each split of k between nums1 and nums2, take the max
// subsequence of given length from each, merge them greedily, keep the best
class Solution {
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> stk;
        int drop = nums.size() - k;
        for (int x : nums) {
            while (!stk.empty() && drop > 0 && stk.back() < x) {
                stk.pop_back();
                drop--;
            }
            stk.push_back(x);
        }
        stk.resize(k);
        return stk;
    }

    bool greater_(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i] != b[j]) return a[i] > b[j];
            i++; j++;
        }
        return i < (int)a.size();
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < (int)a.size() || j < (int)b.size()) {
            if (greater_(a, i, b, j)) res.push_back(a[i++]);
            else res.push_back(b[j++]);
        }
        return res;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;
        for (int i = max(0, k - n); i <= min(k, m); i++) {
            vector<int> a = maxSubsequence(nums1, i);
            vector<int> b = maxSubsequence(nums2, k - i);
            vector<int> merged = merge(a, b);
            if (best.empty() || merged > best) best = merged;
        }
        return best;
    }
};
