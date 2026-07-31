// Link: https://leetcode.com/problems/find-the-grid-of-region-average/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(1) extra (encodes sum/count into unused high bits of img)
// Approach: Slide every 3x3 window; it's a valid region only if all adjacent
// (up/left) cell differences within it are <= threshold. For each valid
// region, stash its average (bits 12+) and a "region count" tag (bit 8) into
// each covered cell so overlapping regions can be averaged later. Final pass
// divides each cell's accumulated sum by its region count, else keeps original.
class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& img, int threshold) {
        int n = img.size(), m = img[0].size();
        for (int i = 0; i < n - 2; ++i)
            for (int j = 0; j < m - 2; ++j) {
                int sum = 0, is_region = true;
                for (int k = i; k < i + 3; ++k)
                    for (int l = j; l < j + 3; ++l) {
                        sum += (img[k][l] & 255);
                        is_region &=
                            k == i || abs((img[k][l] & 255) -
                                          (img[k - 1][l] & 255)) <= threshold;
                        is_region &=
                            l == j || abs((img[k][l] & 255) -
                                          (img[k][l - 1] & 255)) <= threshold;
                    }
                if (is_region)
                    for (int k = i; k < i + 3; ++k)
                        for (int l = j; l < j + 3; ++l) {
                            img[k][l] += (sum / 9) << 12;
                            img[k][l] += 1 << 8;
                        }
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (img[i][j] >> 8)
                    img[i][j] = (img[i][j] >> 12) / ((img[i][j] >> 8) & 15);
        return img;
    }
};
