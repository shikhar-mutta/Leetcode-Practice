// Link: https://leetcode.com/problems/frequency-balance-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) SC: O(n)
// Approach: n<=1000, so brute force all subarrays. For a fixed left
// end, extend right incrementally maintaining a value->count map plus
// a set of distinct count-values currently in use. A window is balanced
// if it has exactly one distinct value, or if the set of distinct
// frequencies has exactly two entries with the larger equal to double
// the smaller.
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for (int l = 0; l < n; l++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> freqCount; // count-value -> how many distinct nums have it
            set<int> freqValues;
            for (int r = l; r < n; r++) {
                int x = nums[r];
                int oldC = freq[x];
                if (oldC > 0) {
                    freqCount[oldC]--;
                    if (freqCount[oldC] == 0) freqValues.erase(oldC);
                }
                int newC = oldC + 1;
                freq[x] = newC;
                freqCount[newC]++;
                freqValues.insert(newC);

                bool balanced = false;
                if (freq.size() == 1) balanced = true;
                else if (freqValues.size() == 2) {
                    int a = *freqValues.begin(), b = *freqValues.rbegin();
                    if (b == 2 * a) balanced = true;
                }
                if (balanced) ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};
