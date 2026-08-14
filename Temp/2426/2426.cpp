// Link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bit;
    int sz;

    void update(int i) {
        for (++i; i <= sz; i += i & (-i)) bit[i]++;
    }
    int query(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }

public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        vector<int> d(n);
        for (int i = 0; i < n; i++) d[i] = nums1[i] - nums2[i];

        int offset = 40000;
        sz = 80001;
        bit.assign(sz + 1, 0);

        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int bound = d[j] + diff + offset;
            bound = min(bound, sz - 1);
            if (bound >= 0) ans += query(bound);
            update(d[j] + offset);
        }
        return ans;
    }
};
