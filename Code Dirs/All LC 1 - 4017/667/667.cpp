// Link: https://leetcode.com/problems/beautiful-arrangement-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: first k+1 elements alternate low/high (1,k+1,2,k,3,...) to produce k distinct differences 1..k; remaining elements ascend normally giving difference 1 each.
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res;
        int lo = 1, hi = k+1;
        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) res.push_back(lo++);
            else res.push_back(hi--);
        }
        for (int i = k+2; i <= n; i++) res.push_back(i);
        return res;
    }
};
