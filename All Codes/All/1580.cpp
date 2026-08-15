// Link: https://leetcode.com/problems/put-boxes-into-the-warehouse-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        vector<int> effective(n);
        int prefixMin = INT_MAX;
        vector<int> prefix(n), suffix(n);
        for (int i = 0; i < n; i++) {
            prefixMin = min(prefixMin, warehouse[i]);
            prefix[i] = prefixMin;
        }
        int suffixMin = INT_MAX;
        for (int i = n - 1; i >= 0; i--) {
            suffixMin = min(suffixMin, warehouse[i]);
            suffix[i] = suffixMin;
        }
        for (int i = 0; i < n; i++) effective[i] = max(prefix[i], suffix[i]);

        sort(effective.begin(), effective.end());
        sort(boxes.begin(), boxes.end());

        int i = 0, count = 0;
        for (int room : effective) {
            if (i < (int)boxes.size() && boxes[i] <= room) {
                count++;
                i++;
            }
        }
        return count;
    }
};
