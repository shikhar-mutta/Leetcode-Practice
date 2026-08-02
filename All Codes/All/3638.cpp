// Link: https://leetcode.com/problems/maximum-balanced-shipments/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: greedy left-to-right scan tracking the running max of the
// current open shipment. As soon as a weight drops strictly below that
// max, closing the shipment right here is optimal (ending as early as
// possible leaves the most room for further shipments); start a fresh
// shipment at the next index. If the array ends with a shipment still
// open, it never became balanced and doesn't count.
class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int count = 0;
        int i = 0;
        while (i < n) {
            int curMax = weight[i];
            int j = i + 1;
            while (j < n && weight[j] >= curMax) {
                curMax = max(curMax, weight[j]);
                j++;
            }
            if (j < n) { count++; i = j + 1; }
            else break;
        }
        return count;
    }
};
