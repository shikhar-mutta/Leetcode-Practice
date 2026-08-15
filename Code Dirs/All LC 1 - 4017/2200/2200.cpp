// Link: https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIdx;
        for (int i = 0; i < n; i++) if (nums[i] == key) keyIdx.push_back(i);
        set<int> res;
        for (int j : keyIdx) {
            for (int i = max(0, j - k); i <= min(n - 1, j + k); i++) res.insert(i);
        }
        return vector<int>(res.begin(), res.end());
    }
};
