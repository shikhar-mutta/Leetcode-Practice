// Link: https://leetcode.com/problems/put-boxes-into-the-warehouse-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int n = warehouse.size();
        vector<int> effective(n);
        effective[0] = warehouse[0];
        for (int i = 1; i < n; i++) effective[i] = min(effective[i-1], warehouse[i]);

        sort(boxes.begin(), boxes.end());
        int i = n - 1, count = 0;
        for (int box : boxes) {
            while (i >= 0 && effective[i] < box) i--;
            if (i < 0) break;
            count++;
            i--;
        }
        return count;
    }
};
