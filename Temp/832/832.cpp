// Link: https://leetcode.com/problems/flipping-an-image/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) SC: O(1) extra
// Approach: for each row, two-pointer swap-and-invert from both ends toward the middle.
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& row : image) {
            int l = 0, r = row.size()-1;
            while (l <= r) {
                if (l != r) swap(row[l], row[r]);
                row[l] ^= 1;
                if (l != r) row[r] ^= 1;
                l++; r--;
            }
        }
        return image;
    }
};
