// Link: https://leetcode.com/problems/sort-array-by-increasing-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] != freq[b]) return freq[a] < freq[b];
            return a > b;
        });
        return nums;
    }
};
