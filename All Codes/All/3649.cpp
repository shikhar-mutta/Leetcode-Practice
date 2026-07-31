// Link: https://leetcode.com/problems/number-of-perfect-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        vector<long long> a(n);
        for (int i = 0; i < n; i++) a[i] = llabs((long long)nums[i]);
        sort(a.begin(), a.end());

        long long count = 0;
        for (int j = 0; j < n; j++) {
            // find leftmost i such that 2*a[i] >= a[j]
            int lo = 0, hi = j;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (2 * a[mid] >= a[j]) hi = mid; else lo = mid + 1;
            }
            count += (j - lo);
        }

        return count;
    }
};
