// Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: frequency map; for k>0, check each unique value has value+k
// present; for k==0, count values with frequency >= 2
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int count = 0;
        for (auto& [val, cnt] : freq) {
            if (k == 0) {
                if (cnt >= 2) count++;
            } else {
                if (freq.count(val + k)) count++;
            }
        }
        return count;
    }
};
