// Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        int count = 0;
        for (auto& [val, cnt] : freq) {
            int other = k - val;
            if (other == val) {
                count += cnt / 2;
            } else if (other > val && freq.count(other)) {
                count += min(cnt, freq[other]);
            }
        }
        return count;
    }
};
