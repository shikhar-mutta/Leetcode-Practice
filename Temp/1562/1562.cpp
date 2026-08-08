// Link: https://leetcode.com/problems/find-latest-group-of-size-m/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (m == n) return n;
        vector<int> length(n + 2, 0);
        int result = -1;

        for (int i = 0; i < n; i++) {
            int pos = arr[i];
            int leftLen = length[pos - 1];
            int rightLen = length[pos + 1];
            int newLen = leftLen + rightLen + 1;

            if (leftLen == m || rightLen == m) result = i;

            length[pos - leftLen] = newLen;
            length[pos + rightLen] = newLen;
        }
        return result;
    }
};
