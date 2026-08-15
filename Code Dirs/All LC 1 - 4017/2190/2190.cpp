// Link: https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> cnt;
        int best = -1, bestCount = -1;
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            if (nums[i] == key) {
                int v = nums[i + 1];
                cnt[v]++;
                if (cnt[v] > bestCount) { bestCount = cnt[v]; best = v; }
            }
        }
        return best;
    }
};
