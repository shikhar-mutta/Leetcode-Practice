// Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return nums[a] < nums[b]; });

        vector<int> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[idx[j+1]] - nums[idx[j]] <= limit) j++;
            vector<int> positions;
            for (int k = i; k <= j; k++) positions.push_back(idx[k]);
            sort(positions.begin(), positions.end());
            for (int k = 0; k <= j - i; k++) res[positions[k]] = nums[idx[i + k]];
            i = j + 1;
        }
        return res;
    }
};
