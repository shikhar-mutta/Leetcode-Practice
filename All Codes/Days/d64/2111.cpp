// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: the array splits into k independent subsequences (indices i,
// i+k, i+2k, ...) each of which must become non-decreasing. Minimum changes
// per subsequence = length - (longest non-decreasing subsequence), found via
// patience sorting with upper_bound. Sum across all k subsequences.
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int totalChanges = 0;
        for (int start = 0; start < k; start++) {
            vector<int> tails;
            for (int i = start; i < n; i += k) {
                int x = arr[i];
                auto it = upper_bound(tails.begin(), tails.end(), x);
                if (it == tails.end()) tails.push_back(x);
                else *it = x;
            }
            int len = 0;
            for (int i = start; i < n; i += k) len++;
            totalChanges += len - (int)tails.size();
        }
        return totalChanges;
    }
};
