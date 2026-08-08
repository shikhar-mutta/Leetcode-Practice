// Link: https://leetcode.com/problems/longest-turbulent-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int best = 1, up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i-1]) { up = down + 1; down = 1; }
            else if (arr[i] < arr[i-1]) { down = up + 1; up = 1; }
            else { up = 1; down = 1; }
            best = max(best, max(up, down));
        }
        return best;
    }
};
