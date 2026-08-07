// Link: https://leetcode.com/problems/search-a-2d-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(m*n))  SC: O(1)
// Approach: treat the matrix as a single sorted array via index-to-(row,col) mapping, binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int val = matrix[mid / n][mid % n];
            if (val == target) return true;
            if (val < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
