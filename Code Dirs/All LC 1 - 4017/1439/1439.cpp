// Link: https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> current = mat[0];
        for (int r = 1; r < (int)mat.size(); r++) {
            vector<int> next;
            for (int a : current) {
                for (int b : mat[r]) {
                    next.push_back(a + b);
                }
            }
            sort(next.begin(), next.end());
            if ((int)next.size() > k) next.resize(k);
            current = next;
        }
        return current[k - 1];
    }
};
