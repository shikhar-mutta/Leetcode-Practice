// Link: https://leetcode.com/problems/minimum-sensors-to-cover-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
// Approach: a sensor covers a (2k+1)x(2k+1) square (Chebyshev distance
// <= k), so tiling the grid needs ceil(n/(2k+1)) * ceil(m/(2k+1)) sensors.
class Solution {
public:
    int minSensors(int n, int m, int k) {
        long long width = 2LL * k + 1;
        long long rows = (n + width - 1) / width;
        long long cols = (m + width - 1) / width;
        return (int)(rows * cols);
    }
};
