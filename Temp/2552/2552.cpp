// Link: https://leetcode.com/problems/count-increasing-quadruplets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Fenwick {
        vector<int> tree;
        int n;
        Fenwick(int n) : n(n) { tree.assign(n + 1, 0); }
        void update(int i, int delta) {
            for (++i; i <= n; i += i & (-i)) tree[i] += delta;
        }
        int query(int i) {
            int s = 0;
            for (++i; i > 0; i -= i & (-i)) s += tree[i];
            return s;
        }
    };

public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        Fenwick leftFreq(n + 2);
        long long ans = 0;

        for (int j = 1; j + 2 < n; j++) {
            leftFreq.update(nums[j-1], 1);

            Fenwick suffixFreq(n + 2);
            for (int idx = j + 1; idx < n; idx++) suffixFreq.update(nums[idx], 1);

            for (int k = j + 1; k < n; k++) {
                suffixFreq.update(nums[k], -1);
                if (nums[j] > nums[k]) {
                    int leftCount = leftFreq.query(nums[k] - 1);
                    int totalSuffix = suffixFreq.query(n);
                    int rightCount = totalSuffix - suffixFreq.query(nums[j]);
                    ans += (long long)leftCount * rightCount;
                }
            }
        }
        return ans;
    }
};
