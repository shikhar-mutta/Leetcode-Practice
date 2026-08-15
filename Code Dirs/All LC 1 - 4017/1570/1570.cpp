// Link: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/

#include <bits/stdc++.h>
using namespace std;

class SparseVector {
public:
    unordered_map<int,int> nonzero;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0) nonzero[i] = nums[i];
        }
    }

    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (auto& [idx, val] : nonzero) {
            if (vec.nonzero.count(idx)) result += val * vec.nonzero[idx];
        }
        return result;
    }
};
