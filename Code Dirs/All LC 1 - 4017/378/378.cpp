// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log(max-min))  SC: O(1)
// Approach: binary search on value; count elements <= mid using staircase
// walk from bottom-left, narrow range until lo==hi
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];

        auto countLE = [&](int mid) {
            int count = 0, row = n - 1, col = 0;
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) { count += row + 1; col++; }
                else row--;
            }
            return count;
        };

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (countLE(mid) < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
