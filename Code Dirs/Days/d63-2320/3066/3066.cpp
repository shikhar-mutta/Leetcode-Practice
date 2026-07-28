// Link: https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n), SC: O(1) extra
// Approach: Sort, then repeatedly combine the two smallest values as
// 2*min + secondMin, reusing the sorted array itself as an implicit queue:
// index i scans the untouched original elements, index j scans the newly
// produced combined values (both in increasing order), merging them like a
// merge-sort merge step. Stop as soon as a value >= k is encountered.
class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        for (int i = 0, j = 0, count = 0, x, y; ; ++count) {
            if (i < a.size() && (j >= count || a[i] <= a[j])) x = a[i++];
            else x = a[j++];
            if (x >= k) return count;
            if (i < a.size() && (j >= count || a[i] <= a[j])) y = a[i++];
            else y = a[j++];
            long t = 2L * x + y; // test overflow
            a[count] = t < k ? (int)t : k;
        }
        return -1;
    }
};
