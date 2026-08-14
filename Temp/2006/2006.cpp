// Link: https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        int ans = 0;
        for (int x : nums) {
            ans += cnt[x - k] + cnt[x + k];
            cnt[x]++;
        }
        return ans;
    }
};
