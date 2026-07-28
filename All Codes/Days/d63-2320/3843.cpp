// Link: https://leetcode.com/problems/first-element-with-unique-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: count each value's frequency, then count how many distinct
// values share each frequency. Scan the array in order and return the
// first element whose frequency is held by exactly one distinct value.
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        unordered_map<int, int> freqOfFreq;
        for (auto& [v, f] : freq) freqOfFreq[f]++;

        for (int x : nums) {
            if (freqOfFreq[freq[x]] == 1) return x;
        }
        return -1;
    }
};
