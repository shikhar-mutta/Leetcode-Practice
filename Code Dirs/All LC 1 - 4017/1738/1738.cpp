// Link: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));
        vector<int> vals;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i+1][j+1] = matrix[i][j] ^ prefix[i][j+1] ^ prefix[i+1][j] ^ prefix[i][j];
                vals.push_back(prefix[i+1][j+1]);
            }
        }
        nth_element(vals.begin(), vals.begin() + k - 1, vals.end(), greater<int>());
        return vals[k-1];
    }
};
