// Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: for closing time i, the penalty is (count of 'N' hours
// before i, since those are open with no customer) + (count of 'Y'
// hours from i onward, since those are closed while a customer comes).
// Precompute prefix counts of 'N' and suffix counts of 'Y', combine them
// per candidate closing time, and return the earliest time achieving the
// minimum penalty.
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        int pre[n + 1];
        int suf[n + 1];
        pre[0] = 0;
        for (int i = 0; i < n; i++) {
            // int count = 0;
            // if(customers[i]=='N') count++;
            pre[i + 1] = pre[i] + ((customers[i] == 'N') ? 1 : 0);
        }
        suf[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + ((customers[i] == 'Y') ? 1 : 0);
        }
        int MinPen = n + 5;
        for (int i = 0; i <= n; i++) {
            pre[i] += suf[i];
            int pen = pre[i];
            MinPen = min(MinPen, pen);
        }
        for (int i = 0; i <= n; i++) {
            int pen = pre[i];
            if (pen == MinPen)
                return i;
        }
        return n;
    }
};
