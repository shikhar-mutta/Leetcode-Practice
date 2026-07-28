// Link: https://leetcode.com/problems/three-equal-parts/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: count total 1's; must be divisible by 3 (else impossible;
// if zero, any split works). Otherwise each third of the ones (k each)
// must start an identical suffix pattern: locate the index of the
// (0, k-th, 2k-th) one, require the gap to the last one's tail length
// is large enough for leading zeros, then verify the three windows
// (each of length = tail-from-last-one) match character by character.
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int ones = count(arr.begin(), arr.end(), 1);
        if (ones % 3 != 0) return {-1, -1};
        if (ones == 0) return {0, n - 1};

        int k = ones / 3;
        vector<int> idx;
        for (int i = 0; i < n; i++) if (arr[i] == 1) idx.push_back(i);

        int i1 = idx[0], i2 = idx[k], i3 = idx[2 * k];
        int len = n - i3;
        if (i2 - i1 < len || i3 - i2 < len) return {-1, -1};

        for (int t = 0; t < len; t++) {
            if (arr[i1 + t] != arr[i2 + t] || arr[i1 + t] != arr[i3 + t]) return {-1, -1};
        }
        return {i1 + len - 1, i2 + len};
    }
};
